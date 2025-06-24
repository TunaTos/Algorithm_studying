#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
using namespace std;
using ull = unsigned long long;

int N, K;
vector<ull> dp;
vector<ull> cost;



void showCost()
{
	for (int i = 1; i <= N; i++)
	{
		cout << cost[i] << " ";
	}cout << endl;
}

void showDp()
{
	for (int i = 1; i <= K; i++)
	{
		cout << dp[i] << " ";
	}cout << endl;
	
}

void input()
{
	cin >> N >> K;

	dp.resize(K+1, INF);	
	cost.resize(N+1, 0);

	for (int i = 1; i <= N; i++)
		cin >> cost[i];	
}


long long getResult()
{
	dp[0] = 0;
	// 최소를 구할 수 있는 knapsack problem
	for (int i = 1; i <= N; i++)
	{
		for (int j = cost[i]; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - cost[i]] + 1);
		}
	}
	if (dp[K] == INF)
		return -1;
	else
		return dp[K];
}

void solve()
{
	input();
	cout << getResult();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}