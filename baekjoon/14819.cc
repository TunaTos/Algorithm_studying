#include <iostream>
#include <vector>
#include <deque>
#include <string>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

vector<deque<int>> cycles(5);
int Case;
vector<pii> orders;

void cycle(int idx, int num, int dir)
{
    if (dir == -1) // 반시계
    {
        for (int i = 0; i < num; i++)
        {
            int input = cycles[idx].front();
            cycles[idx].pop_front();
            cycles[idx].push_back(input);
        }
    }
    else // 시계
    {
        for (int i = 0; i < num; i++)
        {
            int input = cycles[idx].back();
            cycles[idx].pop_back();
            cycles[idx].push_front(input);
        }
    }
}

void checkDirection(int cycleNumber, int dir)
{
    vector<int> dirVec(5); 
     
    // 왼쪽 -> 0 오른쪽 2 왼쪽 6

    dirVec[1] = dir; // 처음 
    for (int i = 1; i <= 4; i++)
    {
        if (cycles[i][2] == cycles[i+1][6])
            dirVec[i+1] = dirVec[i];
        else
            dirVec[i+1] = dirVec[i] * -1;
    }
    

    for (int i = 1; i <= 5; i++)
        cycle(1, cycleNumber, dirVec[i]);
}

void input()
{
    string str;
    for (int i = 1; i <= 4; i++)
    {
        cin >> str;
        cycles[i].clear();
        for (char ch : str)
            cycles[i].push_back(ch - '0');
    }
    cin >> Case;
    orders.resize(Case);
    for (int i = 0; i < Case; i++)
        cin >> orders[i].first >> orders[i].second;
}

void showContainer(const deque<int> &dq)
{
    for (int ele : dq)
        cout << ele << " ";
    cout << endl;
}

void solve()
{
    input();
    for ()
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}