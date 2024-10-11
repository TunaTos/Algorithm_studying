#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_VERT 1001
#define INF 9876543210
using namespace std;

int V, E, s_vert, e_vert;
long long Distance[MAX_VERT];
int Way[MAX_VERT];
vector<int> path;

vector<pair<int,int>> adj[MAX_VERT]; // To Weight



void Input()
{
	cin >> V;
	cin >> E;
	for (int i = 1; i <= V; i++) Distance[i] = INF;

	int from, to, weight;
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back(make_pair(to, weight));
	}

	cin >> s_vert >> e_vert;
}



void Djkstra()
{
	priority_queue<pair<int, int>> pq; // - Weight, From
	pq.push({ 0,s_vert });
	Distance[s_vert] = 0;
	Way[s_vert] = s_vert;

	while (!pq.empty())
	{
		int Cost = -pq.top().first;
		int From = pq.top().second;
		pq.pop();
		if (From == e_vert) return;


		for (auto& ele : adj[From])
		{
			int To = ele.first;
			int Weight = ele.second;

			if (Distance[To] > Cost + Weight)
			{
				Distance[To] = Cost + Weight;
				pq.push({ -Distance[To],To });
				Way[To] = From;
			}
		}
	}
}

void get_path(int pos)
{
	path.push_back(pos);
	if (Way[pos] != pos)
	{
		get_path(Way[pos]);
	}
	if (Way[pos] == pos)
	{
		return;
	}
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Djkstra();
	get_path(e_vert);

	cout << Distance[e_vert] << '\n';
	cout << path.size() << '\n';
	reverse(path.begin(),path.end());

	for (auto& ele : path)
		cout << ele << " ";
	


	return 0;
}