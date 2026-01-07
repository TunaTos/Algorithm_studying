/**
 * top down 방식
 * 왜 되는걸까? 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define endl '\n'
using namespace std;
using ll =  long long;

int N;
vector<ll> cards;
vector<ll> dp;

// Function for Debug
void show_vec(const vector<ll>& v) {
    for (int i = 0; i <= N; ++i) {
        cout << v[i] << " ";
    }cout << endl;
}


void input() {
    cin >> N;

    cards.assign(N+1, 0);
    dp.assign(N+1, -1);

    for (int i = 1; i <= N; ++i) 
            cin >> cards[i];
    
    dp[0] = 0;
}


ll dfs(int idx) {
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    
    for (int i = 1; i <= idx; ++i) {
        dp[idx] = max(dp[idx], dfs(idx - i) + cards[i]);
    }

    return dp[idx];
}

void solve()
{
    cout << dfs(N);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return (0);
}