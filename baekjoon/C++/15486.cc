#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);;

    int N;
    cin >> N;

    vector<int> T(N+2);
    vector<ll> P(N+2);
    vector<ll> dp(N+2, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; --i) {
        if (i + T[i] <= N + 1) {
            dp[i] = max(dp[i+1], P[i] + dp[i + T[i]]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[1] << endl;
}
