#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERT 501
#define MAX_EDGE 6001
#define INF 987654321
using namespace std;



vector<pair<int, int>> adj[MAX_VERT];
long long Dist[MAX_VERT];
int V, E;

void show_adj();
void show_dis();
void show_res();

void Init()
{
	int start, end, weight;

	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) Dist[i] = INF;

	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(end, weight));
	}
}

bool BellmanFord()
{
	Dist[1] = 0;
	
	for (int i = 0; i < V-1; i++)
	{
		for (int a = 1; a <= V; a++)
		{
			for (int b = 0; b < adj[a].size(); b++)
			{
				int From = a;
				int To = adj[a][b].first;
				int Weight = adj[a][b].second;

				if (Dist[From] == INF) continue;
				
				if (Dist[To] > Dist[From] + Weight) Dist[To] = Dist[From] + Weight;
			}
		}
	}


	for (int a = 1; a <= V; a++)
	{
		for (int b = 0; b < adj[a].size(); b++)
		{
			int From = a;
			int To = adj[a][b].first;
			int Weight = adj[a][b].second;

			if (Dist[From] == INF) continue;

			if (Dist[To] > Dist[From] + Weight) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Init();
	bool is_possible = BellmanFord();
	if (!is_possible)
	{
		cout << -1;
		return 0;
	}

	show_res();




	return 0;
}

void show_adj()
{
	cout << "This is adj " << endl;

	for (int i = 1; i <= V; i++)
	{
		cout << i << " ";

		if (adj[i].size() == 0) continue;

		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << adj[i][j].first << " " << adj[i][j].second << " ";
		}
		cout << endl;
	}
}
void show_dis()
{
	cout << "This is Dist " << endl;
	for (int i = 1; i <= V; i++)
	{
		cout << Dist[i] << " ";
	}

}

void show_res()
{
	for (int i = 2; i <= V; i++)
	{
		if (Dist[i] == INF) cout << -1 << endl;
		else
			cout << Dist[i] << endl;

	}



}