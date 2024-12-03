#include <bits/stdc++.h>
#define endl '\n'
#define MAX_VERT 101
using namespace std;
using ll = long long;
using pli = pair<long long, int>; // weight, node

vector<int> items;
vector<pli> adj[MAX_VERT];
int V, E, M;
ll INF = numeric_limits<long long>::max();
ll res = 0;

void input() noexcept
{
	int from, to, weight;
	cin >> V >> M >> E;
	
	items.resize(V+1, 0);
	for (int i = 1; i <= V; i++)
		cin >> items[i];
	
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(weight,to));
		adj[to].push_back(make_pair(weight, from));
	}
}


ll dijkstra(const int& node) noexcept
{
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	vector<ll> Distance = vector<ll>(V+1, INF);

	pq.push(make_pair(0, node));
	Distance[node] = 0;
	
	while (!pq.empty())
	{
		ll weight = pq.top().first;
		int start = pq.top().second;
		pq.pop();


		if (Distance[start] < weight) continue;

		for(auto& next: adj[start])
		{
			ll cost = next.first;
			int to = next.second;

			if (Distance[to] > Distance[start] + cost)
			{
				Distance[to] = Distance[start] + cost;
				pq.push(make_pair(Distance[to], to));
			}
		}
	}
	
	ll tmp = 0;
	for (int i = 1; i <= V; i++)
	{
		if (Distance[i] <= M)
			tmp += items[i];
	}
	
	
	return tmp;
}


void solve() noexcept
{
	input();
	for (int i = 1; i <= V; i++)
		res = max(res, dijkstra(i));
	cout << res;
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}