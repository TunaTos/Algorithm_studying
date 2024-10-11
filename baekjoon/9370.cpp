#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_VERT 2001
#define INF 1e9
#define endl '\n'
typedef long long ll;
using namespace std;

int Tcase, Vert, Edge, t_num, start, d1, d2;
ll s_dist[MAX_VERT], d1_dist[MAX_VERT], d2_dist[MAX_VERT];
vector<int> target;
vector < pair<int, ll>> adj[MAX_VERT]; // to weight
void Debug();
void show_adj();


void Reset()
{
	for (int i = 1; i <= Vert; i++)
	{
		adj[i].clear();
	}
	target.clear();

}

void set_dist()
{
	for (int i = 1; i <= Vert; i++)
	{
		s_dist[i] = d1_dist[i] = d2_dist[i] = INF;
	}
}
void Input()
{
	int from, to;
	ll weight;
	cin >> Vert >> Edge >> t_num;
	cin >> start >> d1 >> d2;
	
	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
	set_dist();

	for (int i = 0; i < t_num; i++)
	{
		cin >> from;
		target.push_back(from);
	}
	sort(target.begin(), target.end());
}

void Dijkstra(ll dist[], int stand)
{
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,stand });
	dist[stand] = 0;

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dist[from]) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = ele.second;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to],to });
			}
		}
	}
}


void Solve()
{
	for (int i = 0; i < target.size(); i++)
	{
		int T = target[i];

		ll dis1 = s_dist[d1], dis2 = s_dist[d2]; // 시작점에서 d1, d2까지의 거리
		ll t = 0;
		if (dis1 <= dis2) // d1까지의 거리가 더 작으면
			t = s_dist[d1] + d1_dist[d2] + d2_dist[T];

		else 
			t = s_dist[d2] + d2_dist[d1] + d1_dist[T];
		//cout << "This is T and t" << s_dist[T] << " " << t << endl;

		if (s_dist[T] == t)
		{
			cout << T << " ";
		}
	}
	cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		Input();
		Dijkstra(s_dist, start);
		Dijkstra(d1_dist, d1);
		Dijkstra(d2_dist, d2);
		//Debug();
		Solve();
		Reset();

	}

	return 0;
}

void Debug()
{
	cout << "s_dist , d1_dist, d2_dist" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << s_dist[i] << " ";
	}cout << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << d1_dist[i] << " ";
	}cout << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << d2_dist[i] << " ";
	}cout << endl;
}

void show_adj()
{
	cout << "This is adj" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << i << " ";
		for (auto& ele : adj[i])
		{
			cout << ele.first << " " << ele.second << "/ ";
		}cout << endl;
	}
}