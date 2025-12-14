#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100001
#define endl '\n'
using ll = long long;

int V;
vector<vector<int>> adj;
vector<ll> nodeNum, dp;
vector<bool> visited;

void dfs(const int node)
{	
	visited[node] = true;
	dp[node] = nodeNum[node];
	for (const auto& next: adj[node])
	{
		if (visited[next]) continue;
		dfs(next);
		dp[node] = max(dp[node] + dp[next], dp[node]);
	}
}

void input()
{
	cin >> V;
	
	adj.resize(V+1, vector<int>());
	nodeNum.resize(V+1, 0);
	dp.resize(V+1, 0);
	visited.resize(V+1, false);

	int from, to;

	for (int i = 0; i < V - 1; i++)
	{
		cin >> from >> to;
		++from; ++to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for (int i = 1; i <= V; i++)
		cin >> nodeNum[i];	
}


void solve()
{
	input();
	dfs(1);
	cout << dp[1];
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}