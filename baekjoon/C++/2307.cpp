#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VERT 1001
#define INF 1e15
typedef long long ll;
using namespace std;


int Vert, Edge;
ll min_distance;
vector<pair<int, ll>> adj[MAX_VERT];
vector<ll> dis(MAX_VERT, INF);
vector<int> parents(MAX_VERT, -1);
vector<int> path;
void show_dis();
void show_parents();
void show_path();

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
	parents[1] = 1;

}
void getPath()
{
	int idx = Vert;
	path.push_back(Vert);

	while (parents[idx] != idx)
	{
		path.push_back(parents[idx]);
		idx = parents[idx];
	}
	reverse(path.begin(), path.end());
}
void Dijstra()
{
	priority_queue<pair<ll, int>> pq; // -weight, to
	pq.push({ 0,1 });
	dis[1] = 0;

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dis[from]) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = ele.second;

			if (dis[to] > dis[from] + cost)
			{
				dis[to] = dis[from] + cost;
				parents[to] = from;
				pq.push({ -dis[to],to });	
			}
		}
	}
	min_distance = dis[Vert];
}

ll getValue(int b_from,int b_to)
{
	vector<ll> dis(MAX_VERT, INF);

	priority_queue<pair<ll, int>> pq; // -weight, to
	pq.push({ 0,1 });
	dis[1] = 0;

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dis[from]) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = ele.second;
			if (from == b_from && to == b_to) continue;

			if (dis[to] > dis[from] + cost)
			{
				dis[to] = dis[from] + cost;
				parents[to] = from;
				pq.push({ -dis[to],to });
			}
		}
	}

	if (dis[Vert] == INF)
	{
		return -1;
	}
	else
		return dis[Vert];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Dijstra();
	getPath();
	ll res = -100;

	for (size_t i = 0; i < path.size() - 1; i++)
	{
		int ban_from = path[i];
		int ban_to = path[i + 1];

		ll val = getValue(ban_from,ban_to);
		if (val == -1)
		{
			res = -1;
			break;
		}
		else
			res = max(res, val - min_distance);
	}


	cout << res;



	return 0;
}

void show_dis()
{
	cout << "This is distance" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << dis[i] << " ";
	}cout << endl;
}
void show_parents()
{
	cout << "This is parents" << endl;
	for (int i = 1; i <=Vert; i++)
	{
		cout << parents[i] << " ";
	}cout << endl;
}
void show_path()
{
	cout << "This is path" << endl;
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}cout << endl;
}