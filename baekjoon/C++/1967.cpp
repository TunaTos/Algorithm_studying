#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_VERT 10001
using namespace std;

vector<pair<int, int>> adj[MAX_VERT];
bool visited[MAX_VERT];
int V;
vector<int> Leaf;
long long Distance[MAX_VERT];
int Max = -100;
int m_index;

void show_Distance()
{
	for (int i = 1; i <= V; i++)
		cout << Distance[i] << " ";
	cout << endl;
}
void Input()
{
	int from, to, weight;
	cin >> V;

	for (int i = 0; i < V-1; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
}

void BFS(int s_vert)
{
	queue<int> q;
	q.push(s_vert);

	while (!q.empty())
	{
		int Len = q.size();
		//show_Distance();

		for (int i = 0; i < Len; i++)
		{
			int s_node = q.front();
			visited[s_node] = true;
			q.pop();

			for (auto& ele : adj[s_node])
			{
				int e_node = ele.first;
				int cost = ele.second;

				if (!visited[e_node])
				{
					Distance[e_node] = Distance[s_node] + cost;
					if (Max < Distance[e_node])
					{
						Max = Distance[e_node];
						m_index = e_node;
					}
				}
				if (!visited[e_node])
				{
					q.push(e_node);
					visited[e_node] = true;
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	if (V == 1)
	{
		cout << 0;
		return 0;
	}
	BFS(1);
	Max = -100;

	memset(visited, false, sizeof(visited));
	memset(Distance, 0, sizeof(Distance));


	BFS(m_index);
	cout << Max;

	


	return 0;
}