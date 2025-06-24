#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

ull num{0};
int res{0};

void input() noexcept
{
    cin >> num;
}

void get_result() noexcept
{
    ull sum = 0;
    int left = 1, right = 1; 

    while (left <= right)
    {
        if (sum < num)
        {
            sum += right; 
            ++right;     
        }
        else if (sum > num)
        {
            sum -= left;
            ++left;  
		}
        else 
        {
            ++res;     
            sum += right; 
            ++right;
        }
        
        if (right > num + 1)
            break;
    }
}

void solve() noexcept
{
    input();
    get_result();
    cout << res << endl;
}

int main() noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}
