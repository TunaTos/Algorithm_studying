#include <iostream>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX_LEN 1001
#define endl '\n'
typedef long long ll;
using namespace std;

int dp_len, list_len, add = -100;
ll res = INF;
vector<pair<int, int>> val_list; // {cost, value}
vector<ll> dp(2000,INF);


void show_dp();
void show_list();


void Input()
{
	int cost, value;
	cin >> dp_len >> list_len;

	dp[0] = 0;

	for (int i = 0; i < list_len; i++)
	{
		cin >> cost >> value;
		add = max(add, value);
		val_list.emplace_back(cost, value);
	}
}


void solve()
{
	for (int i = 1; i <= dp_len + add; i++)
	{
		for (int j = 0; j < list_len; j++)
		{
			int from = i - val_list[j].second;
			int to = i;

			if (from < 0) continue;

			dp[to] = min(dp[to], dp[from] + val_list[j].first);
			
			if (i >= dp_len) res = min(res, dp[to]);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	solve();

	//show_dp();
	//show_list();
	cout << res;




	return 0;
}


void show_dp()
{
	cout << "This is dp" << endl;
	for (int i = 1; i <= dp_len + add; i++)
	{
		cout << dp[i] << " ";
	}cout << endl;
}
void show_list()
{
	cout << "This is list" << endl;
	for (auto& ele : val_list)
		cout << ele.first << " " << ele.second << " / ";
	cout << endl;
}