#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int V;
vector<int> indegree;
vector<ull> dis;
vector<ull> cost;
vector<vector<int>> adj;

void init() noexcept
{
	indegree.assign(V+1, 0);
	dis.assign(V+1, 0);
	cost.assign(V+1, 0);
	adj.assign(V+1, vector<int>());
}

void input() noexcept
{
	cin >> V;
	init();

	for (int i = 1; i <= V; i++)
	{
		ull tmp;
		cin >> tmp;
		dis[i] = tmp;
		cost[i] = tmp;

		while (true)
		{
			cin >> tmp;
			if (tmp == -1)
				break;
			indegree[i]++;
			adj[tmp].push_back(i);
		}
	}
}

void topological() noexcept
{
	queue<int> q;
	
	for (int i = 1; i <= V; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int from = q.front();
		q.pop();

		for (const auto& next: adj[from])
		{
			
			dis[next] = max(dis[from] + cost[next], dis[next]);
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
}


void solve() noexcept
{
	input();
	topological();
	
	for (int i = 1; i <= V; i++)
		cout << dis[i] << endl;
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}