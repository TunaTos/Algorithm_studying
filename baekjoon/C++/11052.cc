/**
 * P4 -> 7
 * P3 -> 6
 * P2 -> 5
 * P1 -> 1
 * 
 * 딱 맞게 N이 나와야한다.
 * 
 * P(N) 
 *      카드 갯수가 N인 경우 최대 비용
 * P(N)  
 *      P(1) + P(N-1)
 *      P(2) + P(N-2)
 *      P(3) + P(N-3)
 * 
 * P(0) -> 0
 * P(1) -> p(1)
 * 
 * P(N) = for (int i = 0; i <= N; ++i)
 *              P(i) + P(N-1)
 * 
 * 
 * 
 * P(N) -> 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N;
vector<ull> cards;
vector<ull> dp;

// Function for Debug
void show_vec(const vector<ull>& v) {
    for (int i = 0; i <= N; ++i) {
        cout << v[i] << " ";
    }cout << endl;
}


void input() {
    cin >> N;

    cards.assign(N+1, 0);
    dp.assign(N+1, 0);

    for (int i = 1; i <= N; ++i) 
            cin >> cards[i];

    dp[0] = 0;
}

void solve() {

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) { 
            dp[i] = max(dp[i],dp[i-j] + cards[j]);
        }
    }

}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    cout << dp[N];
    //show_vec(dp);

    return (0);
}