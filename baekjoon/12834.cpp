#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
typedef long long ll;
using namespace std;

int N, V, E, Kist,C_Food;
int dist[1001];
ll res;
vector<int> s_pos;
vector<pair<int, int>> adj[1001]; // to, weight
//Function For Debug()
void show_dist();

void setdist();
void Input()
{
	setdist();
	int input,from,to, weight;
	cin >> N >> V >> E;
	cin >> Kist >> C_Food;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		s_pos.push_back(input);
	}

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
}

int Dijkstra(int s)
{
	priority_queue<pair<int, int>> pq; // -weight, to
	dist[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();
		for (auto& ele : adj[from])
		{
			int to = ele.first;
			int cost = ele.second;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				pq.push({ -cost,to });
			}
		}
	}

	if (dist[Kist] == INF) dist[Kist] = -1;
	if (dist[C_Food] == INF) dist[C_Food] = -1;
	return dist[Kist] + dist[C_Food];
}

void Solve()
{
	for (auto& start : s_pos)
	{
		res += Dijkstra(start);
		//show_dist();
		setdist();
	}

	cout << res;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solve();


	return 0;
}

void setdist()
{
	for (int i = 1; i <= 1000; i++)
		dist[i] = INF;

}

void show_dist()
{
	cout << "This is dist" << endl;
	for (int i = 1; i <= V; i++)
		cout << dist[i] << " ";
	cout << endl;
}