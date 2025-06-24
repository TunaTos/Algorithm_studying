#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N, Tcase;
vector<ull> dp;

template<typename T>
void show_vector(const T& t)
{
	for (int i = 1; i <= N; i++)
		cout << t[i] << " ";
	cout << endl;	
}

void input() noexcept
{
	cin >> N >> Tcase;
	
	dp.assign(N+1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i-1];
	}
}

ull get_sum(const int& index1, const int& index2) noexcept
{
	assert(index1 <= index2);

	return dp[index2] - dp[index1 -1];	
}

void solve() noexcept
{
	input();
	// show_vector(dp);
	for (int i = 0; i < Tcase; i++)
	{
		int index1, index2;
		cin >> index1 >> index2;
		cout << get_sum(index1, index2) << endl;
	}
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}