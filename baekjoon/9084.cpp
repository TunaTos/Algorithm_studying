#include <bits/stdc++.h>
#define MAX_N 21
#define MAX_M 100001
using namespace std;

int Tcase, N, M, dp[MAX_N][MAX_M];
vector<int> coins;

void showDp() noexcept
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}	
}
void showCoins() noexcept
{
	cout << "This is coins : " << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << coins[i] << " ";
	}cout << endl;
	
}
void input() noexcept
{
	int input;
	cin >> N;
	coins.push_back(0);
	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		coins.push_back(input);
	}
	cin >> M;
}

void getDp() noexcept
{
	dp[0][0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			dp[i][j] = dp[i-1][j];
			
			if (j >= coins[i])
				dp[i][j] += dp[i][j - coins[i]];
		}
	}
}

void reset() noexcept
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			dp[i][j] = 0;
	}
	coins.clear();
}

void solve() noexcept
{
	cin >> Tcase;
	for (int i = 0; i < Tcase; i++)
	{
		input();
		//showDp();
		getDp();
		cout << dp[N][M] << endl;
		//showDp();
		
		reset();
	}
	

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return (0);
}