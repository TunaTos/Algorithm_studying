#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int N, K, res;
vector<int> numbers;
vector<int> contained;

void dfs(int idx, int dpt)
{
    if (dpt == K)
    {
        // for (int i = 0; i < contained.size(); ++i)
        //     cout << contained[i] << " ";
        // cout << endl;
        ++res;
        return ;        
    }

    for (int i = idx; i <= N; ++i)
    {
        contained.push_back(numbers[i]);
        dfs(i+1, dpt+1);
        contained.pop_back();
    }

}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    if (N == K || K == 0 || N == 1)
    {
        cout << 1;
        return 0;
    }

    numbers.resize(N+1, 0);
    for (int i = 1; i <= N; ++i)
        numbers[i] = i;

    dfs(1,0);
    cout << res;

    
    return (0);
}