#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
using ull = unsigned long long;


int V;
vector<vector<int>> adj;
vector<ull> cost;
vector<int> indegree;


template<typename T>
void showContainer(const T& t)
{
	for (int i = 1; i <= V; i++)
	{
		cout << t[i] << " ";
	}cout << endl;
}


void init()
{
	adj.resize(V+1, vector<int>());
	cost.resize(V+1, 0);
	indegree.resize(V+1, 0);
}


void input()
{
	cin >> V;
	init();
	for (int i = 1; i <= V; i++)
	{
		int indegreeNum;
		cin >> cost[i];

		cin >> indegreeNum;
		for (int j = 0; j < indegreeNum; j++)
		{
			int node;
			cin >> node;
			adj[node].push_back(i);
			indegree[i]++;
		}
	}
}

ull getTopological()
{

	queue<int> q;
	vector<ull> dp(V+1, 0);

	for (int i = 1; i <= V; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			dp[i] = cost[i];
		}
	}
	
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (const auto& next: adj[node])
		{
			dp[next] = max(dp[next], dp[node] + cost[next]);
			indegree[next]--;
			
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	sort(dp.begin(), dp.end());
	return dp[V];	
}

void solve()
{
	input();
	// showContainer(cost);
	// showContainer(indegree);
	cout << getTopological();
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}