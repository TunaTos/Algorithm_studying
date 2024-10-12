#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[101][100001]; 
vector<int> caffein;

void input() {
    cin >> N >> K;
    caffein.resize(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> caffein[i];
    }
    for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
}

void solve() { 
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= caffein[i]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j - caffein[i]] + 1); 
            }
        }
    }
    
    if (dp[N][K] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[N][K] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
