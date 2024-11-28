#include <bits/stdc++.h>
#define endl '\n'
#define MAX_VERT 200001
using namespace std;
using ull = unsigned long long;
using pll = pair<ull,ull>; // weight, node

const auto INF = numeric_limits<ull>::max();
int E, V, From, To;
vector<int> res;
vector<pll> adj[MAX_VERT];

void input() noexcept
{
	int from, to;
	ull w;
	cin >> V >> E >> From >> To;

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> w;
		adj[from].push_back(make_pair(w,to));
		adj[to].push_back(make_pair(w, from));
	}
}

vector<ull> dijkstra(const int& node) noexcept
{
	priority_queue<pll,vector<pll>, greater<pll>> pq;

	auto res = vector<ull>(V+1, INF);
	res[node] = 0;
	pq.push(make_pair(0,node));

	while (!pq.empty())
	{
		auto [dis, from] = pq.top();
		pq.pop();
		if (dis > res[from])
			continue;

		for (auto [weight, to] : adj[from])
		{
			if (res[to] > res[from] + weight)
			{
				res[to] = res[from] + weight;
				pq.push(make_pair(res[to], to));
			}
		}
	}	
	return res;
}


void solve() noexcept
{
	input();
	vector<ull> from_distance = dijkstra(From);
	vector<ull> to_distance = dijkstra(To);
	ull min_distance = from_distance[To];

	for (int i = 1; i <= V; i++)
	{
		if (from_distance[i] + to_distance[i] == min_distance)
			res.emplace_back(i);
	}
	
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for(const auto&ele: res)
		cout << ele << ' ';
	cout << endl;
}



int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}