#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
int board[101][101];
int next_board[101][101];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int countComponents() {
    bool visited[101][101] = {false};
    int count = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] > 0 && !visited[i][j]) {
                count++;
                if (count > 1) return 2;
                
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ni = curr.first + dr[k];
                        int nj = curr.second + dc[k];
                        if (ni >= 0 && ni < M && nj >= 0 && nj < N &&
                            board[ni][nj] > 0 && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
    }
    return count;
}

void simulate() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            next_board[i][j] = board[i][j];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] > 0) {
                int k = board[i][j];
                for (int r = i - k; r <= i + k; ++r) {
                    for (int c = j - k; c <= j + k; ++c) {
                        if (r >= 0 && r < M && c >= 0 && c < N) {
                            if (next_board[r][c] < k) {
                                next_board[r][c] = k;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = next_board[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M >> N)) return 0;

    bool anyMold = false;
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            board[i][j] = s[j] - '0';
            if (board[i][j] > 0) anyMold = true;
        }
    }

    if (!anyMold) {
        cout << 0 << endl;
        return 0;
    }

    int days = 0;
    while (true) {
        if (countComponents() <= 1) break;
        simulate();
        days++;
    }

    cout << days << endl;

    return 0;
}