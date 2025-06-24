#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
using ull = unsigned long long;
using pui = pair<unsigned long long, int>;

int V, E, S;
vector<vector<pui>> adj;
vector<ull> dis;

void input()
{
	cin >> V >> E >> S;

	// init container
	adj.assign(V+1, vector<pui>());
	dis.assign(V+1, INF);
	
	int from, to;
	ull weight;
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(weight, to));	
	}
}

void dijkstra()
{
	priority_queue<pui,vector<pui>, greater<pui>> pq;

	pq.push(make_pair(0,S));
	dis[S] = 0;

	while (!pq.empty())
	{
		ull d = pq.top().first;
		int s = pq.top().second;

		pq.pop();

		if (d > dis[s])
			continue;
		
		for (const auto& next: adj[s])
		{
			ull cost = next.first;
			int n = next.second;

			if (dis[n] > dis[s] + cost)
			{
				dis[n] = dis[s] + cost;
				pq.push(make_pair(dis[s], n));
			}
		}
	}
}


void solve()
{
	input();
	dijkstra();
	for (int i = 1; i <= V; i++)
	{
		if (dis[i] == INF)
			cout << "INF\n";
		else
			cout << dis[i] << '\n';
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}