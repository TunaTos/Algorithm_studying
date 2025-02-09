#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

/**
 * 퀸의 공격범위 : 수직, 수평 대각선
 * grid의 의미 : N행 grid[n]열
 * 
 */
int N, res;
vector<int> grid;

template<typename C>
void showContainer(const C& c) {
    for (int  i = 1; i <= N; ++i)
        cout << grid[i] << " ";
    cout << endl;
}

bool isPrunning(int dpt)
{
    int stand = grid[dpt];
    if (dpt == 1 || dpt == 0)
        return true;
    for (int  i = 1; i <= dpt - 1; ++i)
    {
        if (grid[i] == stand) // 같은 row
            return false;

        if (abs(grid[i] - stand) == abs(dpt - i)) // 대각선
            return false;
    }
    return true;
}

void dfs(int idx, int dpt) 
{
    if (dpt == N + 1)
    {
        //showContainer(grid);
        ++res;
        return ;
    }
    for (size_t i = 1; i <= N; i++)
    {
        grid[dpt] = i;
        if (isPrunning(dpt))
            dfs(idx, dpt + 1);
    }
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    grid.resize(N+1,0);

    dfs(0, 1);
    cout << res;
    return (0);
}