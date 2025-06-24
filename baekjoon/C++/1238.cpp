#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_VERT 1001
using namespace std;

int res = -100;
int re_dist[MAX_VERT]; // 도착지에서 가는 거리 
int dist[MAX_VERT];
int V, E, Target;
vector<pair<int, int>> adj[MAX_VERT]; // <Target,Weight>



void show_redist();
void show_dist();

void Input()
{
	int From, To, W;
	cin >> V >> E >> Target;
	for (int i = 0; i < E; i++)
	{
		cin >> From >> To >> W;
		adj[From].push_back(make_pair(To, W));
	}
}
void Set(int* arr)
{
	for (int i = 1; i <= V; i++)
		arr[i] = INF;
	
}

int Dijkstra(int start, int target, int* d_arr)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d_arr[start] = 0;


	while (!pq.empty())
	{
		int from = pq.top().second;
		pq.pop();
		if (from == target) return d_arr[from];
		
		for (auto& ele : adj[from])
		{
			int to = ele.first;	
			if (d_arr[to] > d_arr[from] + ele.second)
			{
				d_arr[to] = d_arr[from] + ele.second;
				pq.push({ -d_arr[to],to});
			}	
		}
	}
	return -1;
}

void Reset()
{
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
}
void Solve()
{
	Set(re_dist);
	Dijkstra(Target, -1, re_dist); // 목적지에서 구하는 것

	for (int i = 1; i <= V; i++)
	{
		Set(dist);
		res = max(res,Dijkstra(i, Target, dist) + re_dist[i]);
		Reset();
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solve();

	return 0;
}

void show_redist()
{
	cout << "This is redist : ";
	for (int i = 1; i <= V; i++)
	{
		cout << re_dist[i] << " ";
	} cout << endl;
}
void show_dist()
{
	cout << "This is dist : ";
	for (int i = 1; i <= V; i++)
	{
		cout << dist[i] << " ";
	} cout << endl;

}
