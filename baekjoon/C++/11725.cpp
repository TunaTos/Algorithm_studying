#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];
int parent[MAX];

void dfs(int node) {
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (parent[next] == 0) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[1] = 1; // Assume the root is 1
    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}