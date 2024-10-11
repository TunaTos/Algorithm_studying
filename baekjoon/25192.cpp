#include <bits/stdc++.h>
using namespace std;

int Tcase, res;

unordered_map<string,int> m;

void solve() noexcept
{
    string input;
    for (int i = 0; i < Tcase; i++)
    {
        cin >> input;
        
        if(input=="ENTER") {
            m.clear();
            continue;
        }
        if(m[input] == 1) continue;
        else{
            m[input] = 1;
            ++res;
        }
    }
}

int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> Tcase;
    solve();
    cout << res;

    return (0);
}