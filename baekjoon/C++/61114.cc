#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
vector<ll> weight, profit, dp;



void input() {
	cin >> N >> K;

	// init container
	weight.assign(N+1, 0); profit.assign(N+1, 0); dp.assign(K+1, 0);
	

	for (int i = 1; i <= N; ++i) {
		cin >> weight[i] >> profit[i];
	}
}



void solve() {

	for (int i = 1; i <= N; ++i) {
		for (int j = K; j >= weight[i]; --j) {
			dp[j] = max(dp[j], dp[j-weight[i]] + profit[i]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	input();
	solve();
	
	cout << dp[K];
	// cout << endl; show_dp();
	return (0);
}