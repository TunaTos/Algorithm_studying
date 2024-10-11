#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VERTEX 20001
#define INF 987654321
using namespace std;

// Distance, vertex
vector<pair<int, int>> adj[MAX_VERTEX];
int V, E,S;
int Dist[MAX_VERTEX];
bool Select[MAX_VERTEX];
priority_queue <pair<int, int>> pq;


void show_Dist();
void show_Select();
void show_Adj();
void show_Res();

void Init()
{
	
	cin >> V >> E;
	cin >> S;
	for (int i = 1; i <= V; i++) Dist[i] = INF;

	int From, To, Weight;
	for (int i = 0; i < E; i++)
	{
		cin >> From >> To >> Weight;
		adj[From].push_back(make_pair(Weight, To));
	}
}
void Djkstra()
{
	pq.push({ 0,S });
	Dist[S] = 0;

	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int start = pq.top().second;
		pq.pop();

		if (Select[start]) continue;
		Select[start] = true;

		for (auto& ele : adj[start])
		{
			int cost = ele.first;
			int target = ele.second;

			if (Dist[target] > Dist[start] + cost)
			{
				Dist[target] = Dist[start] + cost;
				pq.push({ -Dist[target],target });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Init();
	Djkstra();
	show_Res();




	return 0;
}


void show_Dist()
{
	cout << "This is Distance : " << endl;
	for (int i = 1; i <= V; i++)
	{
		cout << Dist[i] << " ";
	}
	cout << endl;
}
void show_Select()
{
	cout << "This is Selected : " << endl;
	for (int i = 1; i <= V; i++)
	{
		cout << Select[i] << " ";
	}
	cout << endl;
}
void show_Adj()
{
	cout << "This is adj : " << endl;
	for (int i = 1; i <= V; i++)
	{
		cout << i << " ";

		for (auto& ele : adj[i])
			cout << ele.first << " " << ele.second << " ";
		cout << endl;
	}
}


void show_Res()
{
	for (int i = 1; i <= V; i++)
	{
		if (Dist[i] == INF) cout << "INF\n";
		else
			cout << Dist[i] << '\n';
	}
}