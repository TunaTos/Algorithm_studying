/**
 * 상, 하, 좌, 우
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;


int Row, Col, wPower, bPower;
vector<vector<char>> matrix;
vector<vector<bool>> visited;
constexpr int x_move[] = {-1,1,0,0}, y_move[] = {0,0,-1,1};

template<typename container>
void showContainer(const container& c) {
    for (int i =1; i <= Row; ++i) {
        for (int j =1; j <= Col; ++j) {
            cout << c[i][j] << " ";
        }cout << endl;
    }
}

void input() {
    cin >> Col >> Row;
    
    // init continer
    matrix.assign(Row+1, vector<char>(Col+1, 0));
    visited.assign(Row+1, vector<bool>(Col+1, false));
    
    string str;
    for (int i =1; i <= Row; ++i) {
        cin >> str;
        for (int j =0; j < str.size(); ++j) 
            matrix[i][j + 1] = str[j]; 
    }
}

bool inTheMatrix(int xpos, int ypos) {
    return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
}

int dfs(int xpos, int ypos, char c) {
    
    visited[xpos][ypos] = true;
    int cnt = 1;

    for (int i = 0; i < 4; ++i) {
        int x = xpos + x_move[i];
        int y = ypos + y_move[i];

        if (!inTheMatrix(x,y)) continue;
        if (visited[x][y]) continue;
        if (matrix[x][y] != c) continue;
        
        cnt += dfs(x, y, c);
    }
    return cnt;
}

void solve() {
    for (int i = 1; i <= Row; ++i) {
        for (int j =1; j <= Col; ++j) {
            if (visited[i][j]) continue;
            int tmp = dfs(i,j, matrix[i][j]);
            matrix[i][j] == 'W' ? wPower += pow(tmp,2) : bPower += pow(tmp,2);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    solve();
    cout << wPower << " " << bPower << endl;
    
    return (0);
}