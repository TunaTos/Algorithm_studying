#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int Tcase, Edges, Verts, dist[20], trace[20]; 
vector<pair<int, int>> adj[20]; // {to, weight}
// Function for setting
void clearadj();
void setdist();
//Function for debug()
void show_dist();
void show_trace();

void input()
{
	int from, to, weight;

	cin >> Edges >> Verts;
	
	for (int i = 0; i < Edges; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
}

void Dijkstra()
{
	priority_queue<pair<int, int>> pq; // -weight, from
	pq.push({ 0,0});
	dist[0] = 0;

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
				trace[to] = from;
			}
		}
	}
}

vector<int> getResult()
{
	vector<int> pos;
	if (dist[Verts - 1] == INF)
	{
		pos.push_back(-1);
		return pos;
	}

	int p = Verts - 1;

	while (true)
	{
		pos.push_back(p);

		if (trace[p] != p)
		{
			p = trace[p];
		}
		else
		{
			break;
		}
	}

	reverse(pos.begin(), pos.end());

	return pos;
}


void Solve()
{
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		input();
		setdist();
		Dijkstra();
		vector<int> res = getResult();
		cout << "Case #" << i+1 << ": ";
		for (auto& ele : res)
			cout << ele << " ";
		cout << '\n';
		clearadj();

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	Solve();

	return 0;
}

void clearadj()
{
	for (int i = 0; i < 20; i++)
		adj[i].clear();
	
}
void setdist()
{
	for (int i = 0; i < 20; i++)
	{
		dist[i] = INF;
		trace[i] = i;
	}
}
void show_dist()
{
	cout << "This is dist" << endl;
	for (auto& ele : dist)
		cout << ele << " ";
	cout << endl;
}
void show_trace()
{
	cout << "This is trace" << endl;
	for (auto& ele : trace)
		cout << ele << " ";
	cout << endl;
}