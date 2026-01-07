/**
 * 0부터 N까지의 정수 K개를 더해서
 * 그 합이 N이 되는 경우의 수를 수하라
 * 
 * 한 개의 수를 여러 번 쓸 수 있다.
 * 
 * 0부터 20까지 정수 2개를 더해서 합이 20이 되는 경우?
 * 
 * (0,20) (1,19) ....(10,10) .. (19,1) (20,0)
 *  
 * 0부터 6까지 정수 4개를 써서 합이 6이 되는 경우? 
 * 
 * dp[n][k] -> 0부터 n까지 사용해서 k가 되는 가지수
 * dp(a,b,c) -> 0부터 a까지 b개의 수를 사용해서 c가 되는 경우의 수
 * 
 * dp(n, k, n) = dp(n, t, n)
 * 
 * dp(t,n) -> t개의 수를 사용해서 c가 되는 경우의 수
 * 
 * dp(2, 20) 
 *      dp(1,1) + dp(1,19)
 *      dp(1,2) + dp(1,18)
 *      dp(1,3) + dp(1,17) -> 
 *  
 * 2개를 써서 2를 만든다 -> 
 *      1개를 써서 0을 만든거       0 2
 *      1개를 써서 1을 만든거       1 1
 *      1개를 써서 2름 만든거       2 0
 * 
 * 3개를써서 3을 만든다  ->
 *      2개를써서 0을 만든거        002
 *      2개를써서 1을 만든거        10,01
 *      2개를써서 2를 만든거        020 200 111
 *      2개를써서 3을 만든거        300 030 121 211
 *  
 *      
 * dp[n][k] = for (int i = 1; i <= n; ++i) 
 *                  dp[n-1][i]
 * 
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define DIV 1'000'000'000
using namespace std;
using ull = unsigned long long;

int N, K;
vector<vector<ull>> dp;

void show_matrix() {
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j <= N; ++j) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }
}

void input() {
    cin >> N >> K;
    
    dp.assign(200+1, vector<ull>(200+1,0));

    // set init value
    for (int i = 0; i <= N; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 0; i <= K; ++i) {
        dp[i][0] = 1;
    }
}

void solve() {
    // dp[a][b] -> a개를 사용해서 b를 만드는 경우의 수
    if (K == 1) {
        cout << dp[1][N] << endl;
        return;
    }
    
    for (int i = 2; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int a = 0; a <= j; ++a) {
                dp[i][j] = ((dp[i][j]) % DIV + (dp[i-1][a]) % DIV) % DIV;
            }
        }
    }

    cout << dp[K][N];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return (0);
}