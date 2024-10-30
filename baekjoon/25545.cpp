#include <bits/stdc++.h>
#define MAX_VERT 200001
using namespace std;
using ull = unsigned long long;

class Edge {
public:
    int start, end, id;
    ull weight;
    Edge(int s_input, int e_input, ull w_input, int id_input)
        : start(s_input), end(e_input), weight(w_input), id(id_input) {}
    bool operator < (const Edge& other) const {
        return weight < other.weight;
    }
};

int V, E;
vector<int> parents(MAX_VERT), size(MAX_VERT, 1);
vector<Edge> edges;
ull maxWeight, minWeight;

void reset() {
    for (int i = 1; i <= V; i++) {
        parents[i] = i;
        size[i] = 1;
    }
}

int Find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a != b) {
        if (size[a] >= size[b]) {
            parents[b] = a;
            size[a] += size[b];
        } else {
            parents[a] = b;
            size[b] += size[a];
        }
    }
}

ull kruskal(vector<Edge>& sortedEdges) {
    ull result = 0;
    reset();
    int edgeCount = 0;
    for (auto& edge : sortedEdges) {
        if (Find(edge.start) != Find(edge.end)) {
            Union(edge.start, edge.end);
            result += edge.weight;
            edgeCount++;
            if (edgeCount == V - 1) break;
        }
    }
    return result;
}

void getMSTandMaxST() {
    // MST: Sort edges in increasing order and get MST weight
    sort(edges.begin(), edges.end());
    minWeight = kruskal(edges);
    
    // MaxST: Sort edges in decreasing order and get MaxST weight
    reverse(edges.begin(), edges.end());
    maxWeight = kruskal(edges);
}

bool findMMST() {
    // Try shuffling edges and finding an MMST
    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < 100; ++i) { // Try 100 different shuffles
        shuffle(edges.begin(), edges.end(), g);
        ull mmstWeight = kruskal(edges);
        if (mmstWeight != minWeight && mmstWeight != maxWeight) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int u, v;
        ull w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w, i);
    }

    // Edge case where M = N - 1, no MMST can exist
    if (E == V - 1) {
        cout << "NO" << endl;
        return 0;
    }

    getMSTandMaxST();

    // If minWeight equals maxWeight, no MMST can exist
    if (minWeight == maxWeight) {
        cout << "NO" << endl;
        return 0;
    }

    // Try finding an MMST by shuffling edges and checking
    if (findMMST()) {
        cout << "YES" << endl;
        for (int i = 0; i < V - 1; i++) {
            cout << edges[i].id << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
