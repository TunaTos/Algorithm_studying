#include <bits/stdc++.h>
#define MAX_VERT 101
#define endl '\n'
using namespace std;

int V, E, Edge = 1;
vector<int> adj[MAX_VERT];
vector<int> dis(MAX_VERT, -1);


void show_vec() noexcept
{
	for (int i = 1; i <= V; i++)
		cout << dis[i] << ' ';
	cout << endl;
}

void input() noexcept
{
	int node1, node2;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
}

void bfs(const int node) noexcept
{
	queue<int> q;
	q.push(node);
	dis[node] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		int q_size = q.size();
		
		for (int i = 0; i < q_size; i++)
		{
			int node = q.front();
			q.pop();

			for(const auto& next: adj[node])
			{
				if (dis[next] == -1) // not visited
				{
					dis[next] = cnt + 1;
					q.push(next);
				}
			}
		}
		++cnt;
	}
}

bool get_max_distance()
{
	int tmp = -1;
	for (int i = 1; i <= V; i++)
	{
		if (dis[i] == -1)
			return false;
		if (dis[i] > tmp)
		{
			tmp = dis[i];
			Edge = i;
		}
	}
	return true;
}

void get_result()
{
	for (int i = 1; i <= V; i++)
	{
		if (dis[i] == -1 || dis[i] >= 8)
		{
			cout << "Big World!";
			return;
		}
	}
	cout << "Small World!";
}


void solve() noexcept
{
	input();
	bfs(1);
	if (!get_max_distance())
	{
		cout << "Big World!";
		return;
	}
	else
	{
		std::fill(dis.begin(), dis.end(), -1);
		bfs(Edge);
	}
	get_result();
	
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}