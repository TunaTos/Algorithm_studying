#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Tcase;
vector<int> numbers;
int Len, Target, res = 987654321;


void input()
{
    cin >> Len >> Target;
    numbers.clear();
    for (int i = 0; i < Len; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);

    }
    
}


void dfs(int n, int r, int dpt, int idx,  vector<int>& selected)
{
    if (selected.size() == r)
    {
        int sum = 0;
        for (int num : selected)
            sum += num;

		if (sum >= Target)
        	res = min(res, abs(Target - sum));

        return ;
    }

    for (int i = idx; i < Len; i++)
    {
        selected.push_back(numbers[i]);
        dfs(n, r, dpt+1, i+1, selected);
        selected.pop_back();
    }
}


void solve()
{
    cin >> Tcase;

    for (int i = 0; i < Tcase; i++)
    {
        input();
        res = INT_MAX;
        for (int j = 1; j <= Len; j++)
        {
            vector<int> selected;
            dfs(Len, j, 0,0,selected);
        }        
        cout << "# " << i+1 << " " << res << endl;
    }
    
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return (0);
}