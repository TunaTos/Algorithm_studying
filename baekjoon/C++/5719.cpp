#include <bits/stdc++.h>
#define endl '\n'
#define MAX_VERT 500
using namespace std;
using ull = unsigned long long;
using pui = pair<unsigned long long, int>; // weight, to

ull INF = numeric_limits<ull>::max();
int V, E, From, To; // index start at 0
vector<pui> adj[MAX_VERT], rev_adj[MAX_VERT];
bool edge[MAX_VERT][MAX_VERT]; // FROM -> TO 

void debug(const auto vec)
{
	for (const auto& ele : vec)
		cout << ele << " ";
	cout << endl;
}

void debug()
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << edge[i][j] << ' ';
		}cout << endl;
	}
}

void input() noexcept
{
	int from, to, weight;
	cin >> From >> To;

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(weight, to));
		rev_adj[to].push_back(make_pair(weight, from)); 
	}
}

vector<ull> dijkstra(const int& node, const vector<pui> adj[]) noexcept
{
	priority_queue<pui, vector<pui>, greater<pui>> pq;
	vector<ull> Distance = vector<ull>(V, INF);
	
	Distance[node] = 0;
	pq.push(make_pair(0, node));

	while (!pq.empty())
	{
		auto [dis, from] = pq.top();
		pq.pop();

		if (Distance[from] < dis) continue;

		for (auto& ele : adj[from]) 
		{
			ull cost = ele.first;
			int to = ele.second;

			if (Distance[to] > Distance[from] + cost)
			{
				Distance[to] = Distance[from] + cost;
				pq.push(make_pair(Distance[to], to));
			}
		}
	}
	return Distance;
}

bool is_continue() noexcept
{
	cin >> V >> E;
	return !(V == 0 && E == 0);
}

void set_edge(const auto& distance, const auto& rev_distance) noexcept
{
	for (int i = 0; i < V; i++)
	{
		for(auto ele: adj[i])
		{
			int j = ele.second;

			if (distance[i] + ele.first + rev_distance[j] == distance[To])
				edge[i][j] = true;
		}
	}
}

ull get_next_min_distance(const int& node, const vector<pui> adj[]) noexcept
{
	priority_queue<pui, vector<pui>, greater<pui>> pq;
	vector<ull> Distance = vector<ull>(V, INF);
	
	Distance[node] = 0;
	pq.push(make_pair(0, node));

	while (!pq.empty())
	{
		auto [dis, from] = pq.top();
		pq.pop();

		if (Distance[from] < dis) continue;

		for (auto& ele : adj[from]) 
		{
			ull cost = ele.first;
			int to = ele.second;
			if (edge[from][to] == 1) continue;
			if (Distance[to] > Distance[from] + cost)
			{
				Distance[to] = Distance[from] + cost;
				pq.push(make_pair(Distance[to], to));
			}
		}
	}
	return Distance[To];
}


void reset() noexcept
{
	for (int i = 0; i < V; i++)
	{
		adj[i].clear(); rev_adj[i].clear();
		for (int j = 0; j < V; j++)
			edge[i][j] = false;
	}
}


void solve() noexcept
{
	while (is_continue())
	{
		input();
		auto from_distance = dijkstra(From, adj);
		auto to_distance = dijkstra(To, rev_adj);  
		set_edge(from_distance, to_distance);
		auto result = get_next_min_distance(From, adj);
		if (result == INF)
			cout << -1;
		else
			cout << result;
		cout << endl;
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
