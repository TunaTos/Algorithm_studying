#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VERT 101
#define MAX_EDGE 1000
#define INF 1e7
typedef long long ll;
using namespace std;

int jihyun, sungha, Vert, Edge;
ll j_dist[MAX_VERT], s_dist[MAX_VERT], min_val = INF * 3;
vector<pair<int, int>> adj[MAX_VERT]; // {to,weight}

void setdist();
void show_dist(ll arr[])
{
	for (int i = 1; i <= Vert; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void Input()
{
	int from, to, weight;
	cin >> Vert >> Edge;

	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
	cin >> jihyun >> sungha;


}

void Dijkstra(int start, ll dist[]) // Start에서 시작하는 기준으로 dist를 구한다.
{
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dist[from]) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			int cost = ele.second;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to],to });
			}
		}
	}
}

void set_min_val()
{
	for (int i = 1; i <= Vert; i++)
	{
		if (i == jihyun || i == sungha) continue;
		min_val = min(min_val, j_dist[i] + s_dist[i]);
	}

}

int getResult()
{
	/*
	지헌거리 <= 성하거리

	->
	지헌이로부터 가장 가까운 거리
	번호가 가장 작은 거리
	*/
	priority_queue<pair<int, int>> pq; // -지헌이 거리, -번호

	for (int i = 1; i <= Vert; i++)
	{
		if (i == jihyun || i == sungha) continue;	
		if (min_val != s_dist[i] + j_dist[i]) continue;
		if (j_dist[i] > s_dist[i]) continue;


		pq.push({ -j_dist[i],-i });
	}
	if (pq.empty()) return -1;

	return -pq.top().second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	Input();
	setdist();
	Dijkstra(jihyun,j_dist);
	Dijkstra(sungha, s_dist);
	//show_dist(j_dist); show_dist(s_dist);
	set_min_val();
	cout << getResult();



	return 0;
}

void setdist()
{
	for (int i = 1; i <= Vert; i++)
		j_dist[i] = s_dist[i] = INF;
}

