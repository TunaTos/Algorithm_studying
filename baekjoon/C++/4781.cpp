#include <bits/stdc++.h>
#define MAX_N 5001
#define MAX_M 10001
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N, M;
double m;
ull dp[MAX_M];
vector<int> value, weight;

template<typename T>
void showVector(const T& t)
{
	for (int i = 1; i <= N; i++)
	{
		cout << t[i] << " ";
	}cout << endl;
	
}

bool input() noexcept
{

	cin >> N >> m;
	if (N ==0 && m == 0.00)
		return false;
	M = round(m * 100.0);
	return true;
}

void reset() noexcept
{
	fill(dp, dp + MAX_M, 0);
	value.clear(); weight.clear();
}

void setDp() noexcept
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = weight[i]; j <= M; j++)
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
	}
}

void solve() noexcept
{
	while(input())
	{
		value.push_back(0); weight.push_back(0);
		int v_input; double w_input;

		for (int i = 0; i < N; i++)
		{
			cin >> v_input >> w_input;
			value.push_back(v_input); weight.push_back(round(w_input * 100.0));
		}
		setDp();
		cout << dp[M] << endl;
		reset();
	}
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}