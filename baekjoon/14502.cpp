#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define EMPTY 0
#define WALL 1
#define VIRUS 2
using namespace std;

int x_move[] = { -1,1,0,0 }; // 상 하 좌 우
int y_move[] = { 0,0,-1,1 };
int Row, Col, res = -100, w_num, v_num;
int Matrix[9][9];
bool visited[9][9];
vector<pair<int, int>> e_pos;
vector<pair<int, int>> v_pos;

void Debug();
void Init()
{
    cin >> Row >> Col;
    for (int i = 1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            cin >> Matrix[i][j];
            if (Matrix[i][j] == EMPTY)
                e_pos.push_back({ i,j });

            if (Matrix[i][j] == VIRUS)
            {
                v_pos.push_back({ i,j });
                visited[i][j] = true;
            }
               if (Matrix[i][j] == WALL)
                w_num++;
        }
    }
}

bool InTheMatrix(int xpos, int ypos)
{
    if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col)
        return true;
    else
        return false;
}

void bfs()
{
    queue<pair<int, int>> q;

    for (auto& ele : v_pos)
    {
        q.push({ ele.first,ele.second });
        v_num++;
        visited[ele.first][ele.second] = true;
    }
        
    while (!q.empty())
    {
        int q_len = q.size();

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int j = 0; j < q_len; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                int x_pos = x + x_move[i];
                int y_pos = y + y_move[i];

                if (!visited[x_pos][y_pos] && Matrix[x_pos][y_pos] != WALL && InTheMatrix(x_pos, y_pos))
                {
                    q.push({ x_pos, y_pos });
                    v_num++;
                    visited[x_pos][y_pos] = true;
                    Matrix[x_pos][y_pos] = VIRUS;
                }
            }

        }
    }
}


void Solve()
{
    int Len = e_pos.size();
    //cout << "This is size" << Len << endl;
    // Set Wall
    for (int a = 0; a < Len - 2; a++)
    {
        for (int b = a + 1; b < Len - 1; b++)
        {
            for (int c = b + 1; c < Len; c++)
            {
                // Set The Wall
                Matrix[e_pos[a].first][e_pos[a].second] = WALL;
                Matrix[e_pos[b].first][e_pos[b].second] = WALL;
                Matrix[e_pos[c].first][e_pos[c].second] = WALL;

                bfs();
                res = max(res, Row * Col - (w_num + 3) - v_num);
                //cout << res << endl;
                //Debug();
                //cout << w_num + 3 << " " << v_num << " " << endl;
                // Break the Wall
                Matrix[e_pos[a].first][e_pos[a].second] = EMPTY;
                Matrix[e_pos[b].first][e_pos[b].second] = EMPTY;
                Matrix[e_pos[c].first][e_pos[c].second] = EMPTY;
                memset(visited, false, sizeof(visited));
                v_num = 0;
            }
           
        }
    }
}

int main() {
    ios::sync_with_stdio();
    cin.tie(); cout.tie();

    Init();
    if (v_pos.empty() == true)
    {
        cout << Row * Col - w_num;
        return 0;
    }
    
    Solve();
    cout << res;



    return 0;
}


void Debug()
{
    cout << "This is Matrix : " << endl;
    for (int i = 1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "This is visited : " << endl;
    for (int i = 1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}