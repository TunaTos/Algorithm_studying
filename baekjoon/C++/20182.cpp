#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define endl '\n'
#define MAX_VERT 100001
using ull = unsigned long long;
using namespace std;

vector<pair<ull, int>> adj[MAX_VERT]; // weight to

int V, E, S, T;
ull budget;

bool operator < (const pair<ull, int>& p1, const pair<ull, int>& p2)
{
	return p1.first > p2.first;
}

void input()
{
	int from, to;
	ull weight;
	cin >> V >> E >> S >> T >> budget;

	while (E--)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ weight, to });
		adj[to].push_back({ weight, from });
	}
}

bool dijkstra(int& flow)
{
	vector<ull> dist(V + 1, ULLONG_MAX);
	priority_queue<pair<ull, int>,vector<pair<ull,int>>, greater<pair<ull,int>>> pq; 

	pq.push({ 0, S });
	dist[S] = 0;

	while (!pq.empty())
	{
		ull weight = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (dist[from] < weight)
			continue;

		for (auto& next : adj[from])
		{
			ull cost = next.first;
			int to = next.second;

			if (cost > flow)
				continue;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				pq.push({ dist[to], to });
			}
		}
	}

	return dist[T] <= budget;
}

int solve()
{
	int low = 1, high = 20;
	int answer = -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (dijkstra(mid))
		{
			answer = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	cout << solve();

	return 0;
}
