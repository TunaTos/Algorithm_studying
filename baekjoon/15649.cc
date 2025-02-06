#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, R;
vector<int> numbers;
vector<int> tmp;


void dfs(int idx, int dpt)
{
    if (dpt == R)
    {
        for (const auto ele: tmp)
            cout << ele << " ";
        cout << endl;
        return ;
    }

    for (int i = idx; i <= N; i++)
    {
        tmp.push_back(numbers[i]);
        dfs(i+1, dpt+1);
        tmp.pop_back();

    }
    


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> R;
    numbers.resize(N+1);
    for (int i = 1; i <= N; ++i)
        numbers[i] = i;

    dfs(1,0);
    return (0);
}