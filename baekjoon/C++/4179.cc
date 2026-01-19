/**
 * 불에 타기 전에 탈출할 수 있는가? 
 * 
 * 미로의 가장자리 -> 통과!
 * 벽이 있는 공간은 통과 x
 * 
 * J는 초기 위치
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define WALL '#'
#define FIRE 'F'
using namespace std;
using pos = pair<int,int>;

int row, col, res = 1;
vector<vector<char>> matrix;
vector<vector<bool>> visited;
queue<pos> human, fire;
const int x_move[] = {-1,1,0,0}, y_move[] = {0,0,-1,1};

template<typename container>
void show_matrix(const container& c) {
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << c[i][j] << " ";
        }cout << endl;
    }
}

void input() noexcept {
    string str;
    cin >> row >> col;

    // init container
    matrix.assign(row+1, vector<char>(col+1, '0'));
    visited.assign(row+1, vector<bool>(col+1, false));
    
    for (int i = 1; i <= row; i++)
    {
        cin >> str;
        for (int j = 1; j <= col; j++)
        {
            matrix[i][j] = str[j-1];
            if (matrix[i][j] == FIRE)
                fire.push(make_pair(i,j));
            else if (matrix[i][j] == 'J')
                human.push(make_pair(i,j));
        }
    }
}

bool in_the_matrix(int xpos, int ypos) {
    return xpos >=1 && xpos <= row && ypos >= 1 && ypos <= col;  
}

bool human_move() {

    int qSize = human.size();

    for (int i = 0; i < qSize; ++i) {
        int xpos = human.front().first;
        int ypos = human.front().second;
        human.pop();
        if (matrix[xpos][ypos] == FIRE)
            continue;
        
        if (xpos == 1 || xpos == row || ypos == 1 || ypos == col)
            return true;
        
        for (int j = 0;  j < 4; j++)
        {
            int x = xpos + x_move[j];
            int y = ypos + y_move[j];

            if (!in_the_matrix(x,y)) continue;
            if (matrix[x][y] == 'F') continue;
            if (matrix[x][y] == '#') continue;
            if (visited[x][y]) continue;

            visited[x][y] = true;
            human.push(make_pair(x,y));
        }
    }
    ++res;

    return false;
}

void fire_move() {
    int qSize = fire.size();

    for (int i = 1; i <= qSize; i++)
    {
        int xpos = fire.front().first;
        int ypos = fire.front().second;
        fire.pop();
        for (int j = 0; j < 4; j++)
        {
            int x = xpos + x_move[j];
            int y = ypos + y_move[j];

            if (!in_the_matrix(x,y)) continue;
            if (matrix[x][y] == 'F') continue;
            if (matrix[x][y] == '#') continue;

            matrix[x][y] = 'F';
            fire.push(make_pair(x,y));
        }
    }
}

void solve() {

    while (true) {
        bool flag = human_move();
        if (flag) {
            cout << res << endl;
            return ;
        }
        fire_move();
        if (human.empty())
        {
            cout << "IMPOSSIBLE";
            return ;
        }
    }
}





int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    visited[human.front().first][human.front().second] = true;
    solve();
    
    return (0);
}