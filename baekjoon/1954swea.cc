#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Tcase, N, dir = 1, xpos, ypos;
vector<vector<int>> matrix;
const int x_move[] = {-1,0,1,0}; // 상 우 하 좌
const int y_move[] = {0,1,0,-1};

bool inTheMatrix(int x, int y)
{
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

void nextDir()
{
    if (dir == 3)
        dir = 0;
    else   
        ++dir;
}

void dfs(int xpos, int ypos, int cnt)
{

    matrix[xpos][ypos] = cnt;
    //cout << "I am xpos and ypos and cnt :" << xpos << "  " << ypos << " " << cnt << endl;
    if (cnt == N * N)
        return ;

    int nx = xpos + x_move[dir];
    int ny = ypos + y_move[dir];

    if (!inTheMatrix(nx, ny) || matrix[nx][ny] != 0)
    {
        nextDir();
        nx = xpos + x_move[dir];
        ny = ypos + y_move[dir];
        
        dfs(nx,ny,cnt+1);
    }
    
    else
        dfs(nx,ny,cnt+1);

}

void input()
{
    cin >> N;
    matrix.assign(N+1, vector<int>(N+1,0));
    dir = 1;
    xpos = ypos = 1;

    
}

void solve()
{
    cin >> Tcase;

    for (int i = 0; i < Tcase; i++)
    {
        input();
        dfs(1,1, 1);
        cout << "#" << i+1 << endl;
        for (int i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                cout << matrix[i][j] << " ";
            }cout << endl;
        }
    
    }    
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();



    return (0);
}