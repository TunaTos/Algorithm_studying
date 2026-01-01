#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int x_move[] = {-1,1,0,0};
const int y_move[] = {0,0,-1,1};
int Row, Col, pictureCount, maxWidth, tmp;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

template<typename container>
void showMatrix(container& c) {
    for (int i =1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            cout << c[i][j] << " ";
        }cout << endl;
    }
}

void input() noexcept 
{
    cin >> Row >> Col;
    
    // init container
    matrix.assign(Row+1, vector<int>(Col+1, 0));
    visited.assign(Row+1, vector<bool>(Col+1, false));

    for (int i =1; i <= Row; ++i) 
        for (int j = 1; j <= Col; ++j) 
            cin >> matrix[i][j];
}

bool inTheMatrix(int xpos, int ypos) {
    return xpos >= 1 && xpos <= Row && ypos >=1 && ypos <= Col;
}

void dfs(int xpos, int ypos, int cnt) {
    
    visited[xpos][ypos] = true;
    ++tmp;

    for (int i = 0; i < 4; ++i) {
        int x = xpos + x_move[i];
        int y = ypos + y_move[i];

        if (!inTheMatrix(x,y)) continue;
        if (visited[x][y]) continue;
        if (matrix[x][y] == 0) continue;

        dfs(x,y,++cnt);
    }
}

void solve() {
    for (int i = 1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                tmp = 0;
                pictureCount++;
                dfs(i,j,1);
                maxWidth = max(maxWidth, tmp);
            }
        }
    }
}

int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    
    cout << pictureCount << endl;
    cout << maxWidth << endl;
    
    return (0);
}