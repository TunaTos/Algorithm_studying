/**
 * dfs를 사용하면 될 것 같은디요
 * 
 * N,M -> 가져올 수 있는 사탕의 최대 개수를 말하라
 * 완전탐색하면 -> 시간초과
 * dfs를 하면서 dp를 사용해야함
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

int Row, Col, res;
vector<vector<int>> matrix;
vector<vector<int>> dp;
constexpr int x_move[] = {1,0,1};
constexpr int y_move[] = {0,1,1};


void input() {
    cin >> Row >> Col;

    // init continer;
    matrix.assign(Row+1, vector<int>(Col +1, 0));
    dp.assign(Row+1, vector<int>(Col+1, -1));

    for (int i =1; i <= Row; ++i) 
        for (int j = 1; j <= Col; ++j)
            cin >> matrix[i][j];

}


void solve() {
    
    for (int i =1; i <= Row; ++i) {
        for (int j = 1; j <= Col; ++j) {
            if (!(i ==1 && j == 1))
                dp[i][j] = matrix[i][j] + max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
}

// function for debugging
template<typename container>
void showMatrix(const container& c) {
    for (int i = 1; i <= Row; ++i) {
        for (int j =1; j <= Col; ++j) {
            cout << c[i][j] << " ";
        }cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    dp[1][1] = matrix[1][1];
    solve();
    cout << dp[Row][Col] << endl;
    //showMatrix(dp);

    return (0);
}