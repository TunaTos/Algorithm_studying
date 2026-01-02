/**
 * dp[k][n] -> 마지막 숫자가 k인 숫자면서 길이가 n인 숫자
 *    
 * dp[n][k] = 
 * 1 1 1[11] 1(111)
 * 2 1 2[12, 22] 3[112, 122, 222]
 * 3 1 3[13,23,33] 6[113,123,223,133,233,333]
 * 4 1 4,(14, 24, 34 ,44) | 
 * 5 1
 * 6 1
 * 7 1
 * 8 1
 * 9 1
 * 
 * F(1,n) = F(1,k) + F(k,n)
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define DIV 10'007
using namespace std;
using ull = unsigned long long;


int N;
vector<vector<ull>> dp;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    dp.assign(9 + 1 , vector<ull>(N+1, 0));

    for (int c = 1; c <= N; ++c) {
        for (int r = 0; r <= 9; ++r) {
            if (c == 1)
                dp[r][c] = r + 1;
            else {
                if (r == 0) 
                    dp[r][c] = dp[r][c-1];
                else
                    dp[r][c] = (dp[r-1][c] + dp[r][c-1]) % DIV;
            }
        }
    }
    
    /*for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }*/

    cout << dp[9][N] << endl;
    return (0);
}