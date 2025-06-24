#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_VERT 801
using namespace std;

int res1, res2, V, E, M1, M2;
vector<pair<int, int>> adj[MAX_VERT];
int dist[MAX_VERT];

void show_dist();
void Reset_dist();
void Input()
{
	cin >> V >> E;
	int s, e, w;
	for (int i = 1; i <= V; i++) dist[i] = INF;
	for (int i = 0; i < E; i++)
	{
		cin >> s >> e >> w;
		adj[s].push_back(make_pair(e, w));
		adj[e].push_back(make_pair(s, w));
	}
	cin >> M1 >> M2;
}

int Dijkstra(int s_vert, int e_vert)
{
	priority_queue < pair<int, int>> pq;
	pq.push(make_pair(0, s_vert));
	dist[s_vert] = 0;

	while (!pq.empty())
	{
		int Cost = -pq.top().first;
		int From = pq.top().second;
		pq.pop();

		if (From == e_vert) return dist[e_vert];
		for (auto& ele : adj[From])
		{
			int To = ele.first;
			int Add_Cost = ele.second;

			// relaxation해야하는 경우
			if (dist[To] > dist[From] + Add_Cost)
			{
				dist[To] = dist[From] + Add_Cost;
				pq.push(make_pair(-dist[To], To));
			}
		}
	}

	return dist[e_vert];
}

bool getDistance1()
{
	res1 += Dijkstra(1, M1);
	if (dist[M1] == INF) return false;
	Reset_dist();
	res1 += Dijkstra(M1, M2);
	if (dist[M2] == INF) return false;
	Reset_dist();
	res1 += Dijkstra(M2, V);
	if (dist[V] == INF) return false;
	Reset_dist();

	return true;


}

bool getDistance2()
{
	res2 += Dijkstra(1, M2);
	if (dist[M2] == INF) return false;
	Reset_dist();
	res2 += Dijkstra(M2, M1);
	if (dist[M1] == INF) return false;
	Reset_dist();
	res2 += Dijkstra(M1, V);
	if (dist[V] == INF) return false;
	Reset_dist();


	return true;
}
void Solve()
{
	bool res1_valid = getDistance1();
	bool res2_valid = getDistance2();

	if (res1_valid && res2_valid) cout << min(res1, res2);
	else if (res1_valid && !res2_valid) cout << res1;
	else if (res2_valid && !res1_valid) cout << res2;
	else
		cout << -1;
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solve();



	return 0;
}


void show_dist()
{
	cout << "This is dist : ";
	for (int i = 1; i <= V; i++)
		cout << dist[i] << " ";
	cout << endl;

}

void Reset_dist()
{
	for (int i = 1; i <= V; i++) dist[i] = INF;

}