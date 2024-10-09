#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int N, T;
ull tmp;
ull matrix[1001][1001];
vector<ull> cost(1001,0);
vector<ull> profit(1001,0);

void showMatrix()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

void showCostAndProfit()
{
	cout << "cost : profit" << endl;
	for (int i = 1; i <= N; i++)
		cout << cost[i] << " " << profit[i] << endl;
}

void input() noexcept
{
	cin >> N >> T;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i] >> profit[i];
		tmp += profit[i];
	}
}

void getDp() noexcept
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (cost[i] > j) 
				matrix[i][j] = matrix[i-1][j];
			else
				matrix[i][j] = max(matrix[i-1][j], 
					matrix[i-1][j - cost[i]] + profit[i]);
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	//showMatrix();
	//showCostAndProfit();
	getDp();
	//showMatrix();
	//cout << tmp << endl;
	cout << tmp - matrix[N][T];
	return (0);
}