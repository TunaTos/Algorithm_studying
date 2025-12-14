#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    bool Union(int x, int y) {
        int rootX = Find(x), rootY = Find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) swap(rootX, rootY);
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) rank[rootY]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, T;
    cin >> V >> E >> T;

    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    long long totalCost = 0;
    int conqueredCities = 0;  

    for (auto& edge : edges) {
        if (uf.Union(edge.from, edge.to)) {
            totalCost += edge.weight + (T * conqueredCities);  
            conqueredCities++; 
            if (conqueredCities == V - 1) break; 
        }
    }

    cout << totalCost << endl;

    return 0;
}
