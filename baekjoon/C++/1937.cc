#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {-1,1,0,0};
constexpr int dy[] = {0,0,-1,1};

int N;
vector<vector<int>> matrix, dp;

void input() {
    cin >> N;
    matrix.assign(N, vector<int>(N, 0));
    dp.assign(N, vector<int>(N, -1));  // -1: 방문하지 않은 상태

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
}

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y]; // 이미 방문한 경우 값 반환

    dp[x][y] = 1;  // 최소 1칸은 이동 가능

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inRange(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }

    return dp[x][y];
}

void solve() {
    input();
    int maxMove = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxMove = max(maxMove, dfs(i, j));
        }
    }

    cout << maxMove << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    return 0;
}
