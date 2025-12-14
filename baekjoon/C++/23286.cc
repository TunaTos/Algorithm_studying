#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MAX_N 301

int dist[MAX_N][MAX_N];
int N, M, T;

void floyd_warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue; 
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
    }
}

void solve() {
    cin >> N >> M >> T;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, h;
        cin >> u >> v >> h;
        dist[u][v] = h; 
    }

    floyd_warshall();
	    
    while (T--) {
        int s, e;
        cin >> s >> e;
        cout << (dist[s][e] == INF ? -1 : dist[s][e]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
