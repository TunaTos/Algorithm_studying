#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
#define endl '\n'
using ull = unsigned long long;
using namespace std;

class Edge
{
public:
    int u, v;
    ull w;

    Edge(const int& u_input, const int& v_input, const ull& w_input) :
        u(u_input), v(v_input), w(w_input) {}

    bool operator < (const Edge& other) const {
        return this->w < other.w;
    }
};

int V, E;
vector<int> parent;
vector<int> weight;
vector<Edge> edges;
vector<vector<pair<int, ull>>> adj; // {to, weight}
vector<bool> visited;

int Find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a == b) return;
    if (weight[a] < weight[b]) swap(a, b);
    parent[b] = a;
    if (weight[a] == weight[b]) weight[a]++;
}

ull mst() {
    ull res = 0;
    int edgeNumber = 0;

    for (auto& ele : edges) {
        int u = ele.u, v = ele.v;
        ull w = ele.w;

        u = Find(u); v = Find(v);
        if (u == v) continue;

        Union(u, v);
        adj[ele.u].push_back({ ele.v, ele.w });
        adj[ele.v].push_back({ ele.u, ele.w });
        res += w;
        edgeNumber++;
        if (edgeNumber == V - 1) break;
    }
    return res;
}

pair<int, ull> dfs(int node, ull dist) {
    visited[node] = true;
    pair<int, ull> farthest = { node, dist };

    for (auto& next : adj[node]) {
        if (!visited[next.first]) {
            auto result = dfs(next.first, dist + next.second);
            if (result.second > farthest.second) {
                farthest = result;
            }
        }
    }
    return farthest;
}

int main() {
    cin >> V >> E;
    adj.resize(V);
    parent.resize(V);
    weight.resize(V, 0);
    visited.resize(V, false);

    for (int i = 0; i < V; i++) parent[i] = i;

    for (int i = 0; i < E; i++) {
        int u, v;
        ull w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    sort(edges.begin(), edges.end());

    ull min_cost = mst();
    cout << min_cost << endl;

    fill(visited.begin(), visited.end(), false);
    auto farthest_from_start = dfs(0, 0);

    fill(visited.begin(), visited.end(), false);
    auto farthest_from_farthest = dfs(farthest_from_start.first, 0);

    ull diameter = farthest_from_farthest.second;
    cout << diameter << endl;

    return 0;
}
