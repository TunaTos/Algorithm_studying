#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int v, tcase, res;
vector<vector<int>> adj;
vector<bool> visited;

void input() noexcept {
    cin >> v;

    // init container
    adj.assign(v+1, vector<int>());
    visited.assign(v+1, false);
    res = 0;

    int node;
    for (int i = 1; i <= v; ++i) {
        cin >> node;
        adj[i].push_back(node);    
    }
}

void dfs(int node) {
    visited[node] = true;

    for (const auto& next: adj[node]) 
        if (!visited[next]) 
            dfs(next);
}

void solve() {
    for (int i = 1; i <= v; ++i) {
        if (!visited[i]) {
            ++res;
            dfs(i);
        }
    }  
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tcase;

    while (tcase--) {
        input();
        solve();
        cout << res << endl;
    }


    return (0);
}