#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;
using pos = pair<int,int>;

int row, col;
pos start, target;
vector<vector<int>> matrix;
vector<vector<vector<int>>> dis;
vector<vector<vector<bool>>> visited;

const int x_move[] = {-1,1,0,0}, y_move[] = {0,0,-1,1};

template<typename matrix> 
void show_matrix(const matrix& m) 
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << m[i][j] << " ";
        } cout << endl;
    }
}

void input() noexcept 
{
    cin >> row >> col;
    cin >> start.first >> start.second;
    cin >> target.first >> target.second;
    
    // init container
    matrix.assign(row+1, vector<int>(col+1));
    dis.assign(2, vector<vector<int>>(row+1, vector<int>(col+1)));
    visited.assign(2, vector<vector<bool>>(row+1, vector<bool>(col+1)));
    
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

bool inTheMatrix(const int& xpos, const int& ypos) {
    return xpos >= 1 && xpos <= row && ypos >= 1 && ypos <= col;
}

void bfs()
{
    queue<pair<int, pos>> q; // {h, (x,y)}
    q.push({0, start});
    visited[0][start.first][start.second] = true;
    dis[0][start.first][start.second] = 0;

    while (!q.empty()) {
        auto [h, p] = q.front();
        q.pop();

        int x = p.first, y = p.second;

        if (x == target.first && y == target.second) {
            cout << dis[h][x][y] << endl;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + x_move[i];
            int ny = y + y_move[i];
            if (!inTheMatrix(nx, ny)) continue;

            if (matrix[nx][ny] == 0) {
                if (visited[h][nx][ny]) continue;
                visited[h][nx][ny] = true;
                dis[h][nx][ny] = dis[h][x][y] + 1;
                q.push({h, {nx, ny}});
            } else { 
                // 벽이면: 아직 안 부쉈을 때만 부수고 이동
                if (h == 1) continue;
                if (visited[1][nx][ny]) continue;
                visited[1][nx][ny] = true;
                dis[1][nx][ny] = dis[0][x][y] + 1;
                q.push({1, {nx, ny}});
            }
        }
    }

    cout << -1 << endl;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    input();
    bfs();

    return (0);
}