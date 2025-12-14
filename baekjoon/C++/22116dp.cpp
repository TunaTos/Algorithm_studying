#include <bits/stdc++.h>
#define MAX_LEN 1001
using namespace std;
using pii = pair<int,int>;
int Len;

int matrix[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1};

template<typename T>
void debug(const T& t)
{
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len ; j++)
        {
            cout << t[i][j] << " ";
        }cout << endl;   
    }
}

void input()
{
    cin >> Len;
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len ; j++)
            cin  >> matrix[i][j];
    }
}

void reset()
{
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len ; j++)
            visited[i][j] = false;
    }
}

bool inTheMatrix(const int& xpos, const int& ypos)
{
    if(xpos>=1 && xpos<= Len && ypos>=1 && ypos <= Len)
        return true;
    else
        return false;
}


bool dfs(int xpos, int ypos, const int& thresh)
{
    visited[xpos][ypos] = true;

    for (int i = 0; i < 4; i++)
    {
        int x = xpos + x_move[i];
        int y = ypos + y_move[i];

        if(!inTheMatrix(x,y)) continue;
        int val = abs(matrix[x][y] - matrix[xpos][ypos]);

        if(val > thresh || visited[x][y]) continue;
        dfs(x,y,thresh);
    }
    return visited[xpos][ypos];
}



void solve()
{
    int left = 0; int right = 1000000000;

    while(left <= right)
    {
        int mid = (left + right) / 2; 
        dfs(1,1,mid);
        if(visited[Len][Len])
            right = mid - 1;            
        
        else
            left  = mid + 1;
        reset();
    }
    cout << left;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return (0); 
}