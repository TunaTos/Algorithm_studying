#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long MOD = 1000000000LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    
    for (int d = 1; d <= 9; ++d) dp[1][d] = 1;

    for (int len = 2; len <= N; ++len) {
        dp[len][0] = dp[len - 1][1] % MOD;
        dp[len][9] = dp[len - 1][8] % MOD;
        for (int d = 1; d <= 8; ++d) {
            dp[len][d] = (dp[len - 1][d - 1] + dp[len - 1][d + 1]) % MOD;
        }
    }

    long long ans = 0;
    for (int d = 0; d <= 9; ++d) {
        ans = (ans + dp[N][d]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
