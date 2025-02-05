#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int N = 5;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

char board[N][N];
vector<pair<int, int>> selected;
int answer = 0;

bool isConnected() {
    queue<pair<int, int>> q;
    bool visited[N][N] = {false};
    int connectedCount = 1;
    
    q.push(selected[0]);
    visited[selected[0].first][selected[0].second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            for (auto& p : selected) {
                if (p.first == nx && p.second == ny && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    connectedCount++;
                }
            }
        }
    }
    return connectedCount == 7;
}

void findCombination(int index, int sCount, int depth) {
    if (depth == 7) { 
        if (sCount >= 4 && isConnected()) {
            answer++;
        }
        return;
    }

    for (int i = index; i < 25; i++) {
        int x = i / 5;
        int y = i % 5;

        selected.push_back({x, y});
        findCombination(i + 1, sCount + (board[x][y] == 'S'), depth + 1);
        selected.pop_back();
    }
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    findCombination(0, 0, 0);
    cout << answer << endl;
    return 0;
}