/**
 * dp[i][j] -> i,j를 사용할 때의 스티커의 최대값
 *      (i,j)에서 스티커를 선택한다면?
 *      (i,j)에서 스티커를 선택하지 않는다면?
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int tcase, n;
vector<vector<ull>> stickers, dp;

// function for debugging
void show_matrix(vector<vector<ull>> m)
{
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= n; ++j) { 
            cout << m[i][j] << " ";
        } cout << endl;
    }
}
void input() noexcept {
    cin >> n;

    // init container
    stickers.assign(2+1, vector<ull>(n+1,0));
    dp.assign(2+1, vector<ull>(n+1,0));
    
    for (int i = 1; i <= 2; ++i) 
        for (int j = 1; j <= n; ++j) 
            cin >> stickers[i][j];
}

void solve() {

    dp[1][1] = stickers[1][1];
    dp[2][1] = stickers[2][1];

    for (int col = 2; col <= n; ++col) {
        for (int row = 1; row <= 2; ++row) {
            ull tmp = 0;
            row == 1 
                ? tmp = dp[2][col-1] + stickers[row][col] 
                : tmp = dp[1][col-1] + stickers[row][col];
            
            dp[row][col] = max({dp[row][col], tmp, dp[row][col-1], dp[row][col-2] + stickers[row][col]});        
        }
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tcase;

    while (tcase--) {
        input();
        //show_matrix(stickers); cout << endl;
        solve();
        //show_matrix(dp);
        cout << max({dp[1][n], dp[2][n]}) << endl;
    }

    return (0);
}