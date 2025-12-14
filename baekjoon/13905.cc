#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

using ull = unsigned long long;
using pui = pair<ull, int>;
typedef pair<ull, pair<int, int>> Edge;

int V, E, Start, Target;
vector<Edge> edges;
vector<int> parents, weights;
vector<vector<pui>> adj;

int Find(int a)
{
    if (parents[a] == a)
        return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b) return;

    if (weights[a] <= weights[b])
    {
        parents[a] = b;
        weights[b] += weights[a];
    }
    else
    {
        parents[b] = a;
        weights[a] += weights[b];
    }
}

void input()
{
    cin >> V >> E;
    cin >> Start >> Target;

    parents.assign(V + 1, 0);
    weights.assign(V + 1, 1);
    adj.assign(V + 1, vector<pui>());

    for (int i = 1; i <= V; i++)
        parents[i] = i;

    int node1, node2;
    ull w;
    for (int i = 0; i < E; i++)
    {
        cin >> node1 >> node2 >> w;
        edges.push_back(make_pair(w, make_pair(node1, node2)));
    }
}

void Kruskal()
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    int totalEdge = 0;
    for (const auto &edge : edges)
    {
        ull cost = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;

        if (Find(node1) == Find(node2))
            continue;

        Union(node1, node2);
        adj[node1].push_back(make_pair(cost, node2));
        adj[node2].push_back(make_pair(cost, node1));

        totalEdge++;
        if (totalEdge == V - 1)
            break;
    }

    edges.clear();
    parents.clear();
    weights.clear();
}

void dfs(int node, vector<bool> &visited, vector<int> &par)
{
    visited[node] = true;
    for (const auto &ele : adj[node])
    {
        if (visited[ele.second])
            continue;
        par[ele.second] = node;
        dfs(ele.second, visited, par);
    }
}

void solve()
{
    input();
    Kruskal();
    
    vector<bool> visited(V + 1, false);
    vector<int> par(V + 1, 0);
    for (int i = 1; i <= V; i++)
        par[i] = i;

    dfs(Start, visited, par);

    vector<ull> pathCost;
    int idx = Target;
    ull res = 987654321;

    while (idx != par[idx])
    {
        for (const auto &ele : adj[idx])
        {
            if (ele.second == par[idx])
            {
                res = min(res, ele.first);
                break;
            }
        }
        idx = par[idx];
    }

    cout << res << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}