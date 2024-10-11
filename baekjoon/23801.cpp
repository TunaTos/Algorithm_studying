#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define MAX_VERTS 100001
#define MAX_EDGES 300001
#define INF 1e11

using namespace std;
typedef long long ll;

ll dist1[MAX_VERTS], dist2[MAX_VERTS], res = INF * 3;
vector<pair<int, int>> adj[MAX_VERTS];
vector<int> pos;
int Vert, Edge, Start, End, pos_len;

void show_dist1();
void show_dist2();

void setdist()
{
	for (int i = 1; i <= Vert; i++)
		dist1[i] = dist2[i] = INF;
}


void Input()
{
	int from, to, weight;
	int input;
	cin >> Vert >> Edge;

	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
	cin >> Start >> End;
	cin >> pos_len;
	for (int i = 0; i < pos_len; i++)
	{
		cin >> input;
		pos.push_back(input);
	}
}


void Dijkstra(int s, int e, ll dist[]) // 시작점에서 나중까지의 거리를 return한다
{
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,s });
	dist[s] = 0;

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		//if (from == e) return dist[e];

		if (dist[from] < weight) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = (ll)ele.second;
			

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to],to });
			}
		}
	}
}

void getResult()
{
	for (int i = 0; i < pos.size(); i++)
	{
		int stand = pos[i];

		ll val1 = dist1[stand];
		ll val2 = dist2[stand];

		if (val1 != INF && val2 != INF)
			res = min(res, val1 + val2);
	}

	if (res == INF*3) cout << -1;
	else
		cout << res;


}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	Input();
	setdist();

	Dijkstra(Start, End, dist1);
	Dijkstra(End, Start, dist2);

	//show_dist1();
	//show_dist2();

	getResult();

	return 0;
}


void show_dist1()
{
	cout << "This is dist1" << endl;
	for (int i = 1; i <= Vert; i++)
		cout << dist1[i] << " ";
	cout << endl;
}
void show_dist2()
{
	cout << "This is dist2" << endl;
	for (int i = 1; i <= Vert; i++)
		cout << dist2[i] << " ";
	cout << endl;
}