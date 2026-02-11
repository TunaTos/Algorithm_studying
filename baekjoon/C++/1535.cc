/**
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;

int N;
ll res = 0;
vector<ll> damage, happy;
vector<vector<ll>> dp;

void input() {
    cin >> N;
    damage.assign(N+1, 0);
    happy.assign(N+1, 0);

    for (int i = 1; i <= N; ++i)
        cin >> damage[i];
    for (int i = 1; i <= N; ++i)
        cin >> happy[i];  
        
    dp.assign(N+1, vector<ll>(100+1, 0));
}

void solve() {

    for (int i = 1; i <= N; ++i) {
        ll d = damage[i];
        ll h = happy[i];

        for (int j = 1; j <= 99; ++j) {
            if (j < d) 
                dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - d] + h);
            }
            res = max(dp[i][j], res);
        }
    }
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    cout << res << endl;
    return (0);
}