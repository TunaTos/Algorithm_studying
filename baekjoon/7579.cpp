#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define INF 10000000000
#define MAX_M 10000001
#define endl '\n'
int appNum, M;
vector<ull> dp(MAX_M), weight, value;
ull memorySum, thresh, costSum;

template<typename T>
void showVec(const T& t)
{
	for (int i = 1; i <= 100; i++)
	{
		cout << t[i] << " ";
		if (i % 10 == 0)
			cout << endl;
	}cout << endl;
}

void input() noexcept
{
	ull input;
	cin >> appNum >> M;
	
	weight.push_back(0); value.push_back(0);
	for (int i = 0; i < appNum; i++)
	{
		cin >> input; weight.push_back(input);
		memorySum += input;
	}
	for (int i = 0; i < appNum; i++)
	{
		cin >> input; value.push_back(input);
		costSum += input;
	}
	thresh = memorySum - M;
}

void setDp() noexcept
{
	for (int i = 1; i <= appNum; ++i)
	{
		for (int j = thresh; j >= weight[i]; --j)
		{
			dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	input();
	
	//cout << memorySum << " " << thresh << endl;
	
	setDp();
	//showVec(dp);
	cout << costSum - dp[thresh];
	return (0);
}