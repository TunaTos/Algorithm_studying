#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1};
int Tcase, ball, Row, Col;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pair<int,int>> wallPos;

template<typename T>
void showMatrix(const T& t)
{
    for (int i = 1; i <= Row; i++)
    {
        for (int j = 1; j <= Col; j++)
        {
            cout << t[i][j] << " ";
        }cout << endl;
    }
}
bool inTheMatrix(int xpos, int ypos)
{
    return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
}


void init()
{
    matrix.assign(Row+1, vector<int>(Col+1, 0));
    visited.assign(Row+1, vector<bool>(Col+1, false));
    wallPos.clear();
}

int getResult()
{
    // matrix에 남은 벽을 알아내는 함수
    int res = 0;
    for (int i = 1; i <= Row; i++)
    {
        for (int j = 1; j < Col; j++)
        {
            if (matrix[i][j] != 0)
                ++res;
        }
    }
    return res;
}

void pullDownWalls()
{
    /**
     * matrix를 당기는 함수
     */
    for (int i = 1; i <= Col; i++)
    {
        queue<pair<int,pair<int,int>>> q; // val row col

        for (int j = Row; j  >=  1; j--)
        {
            if (matrix[j][i] != 0)
                q.push(make_pair(matrix[j][i],make_pair(j,i)));
        }

        int qSize = q.size();
        for (int a = 0; a < qSize; a++)
        {
            auto b = q.front();
            q.pop();

            int val = b.first;
            int xpos = b.second.first;
            int ypos = b.second.second;

            matrix[xpos][ypos] = 0;
            matrix[Row-a][ypos] = val;
        }
        
    }
    
    
}

void input()
{
    cin >> ball >> Col >> Row;
    init();
    
    for (int i = 1; i <= Row; i++)
        for (int j = 1; j <= Col; j++)
            cin >> matrix[i][j];
    
}


void solve()
{
    cin >> Tcase;

    for (int i = 0; i < Tcase; i++)
    {
        cin >> ball >> Row >> Col;
        input();
        // do something
        pullDownWalls();
        cout << "#" << i+1 << " " << getResult() << endl;

    }
    

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //solve();

    input();
    showMatrix(matrix);

    pullDownWalls();
    cout << endl;
    showMatrix(matrix);
    
    return (0);
}