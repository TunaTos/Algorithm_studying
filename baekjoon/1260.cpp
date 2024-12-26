#include <bits/stdc++.h>
#define MAX_VERT 1001
#define endl '\n'
using namespace std;

int V, E, Start;
vector<int> adj[MAX_VERT];
vector<bool> visited(MAX_VERT, false);
vector<int> dfs_nodes;


void input() noexcept
{
	cin >> V >> E >> Start;
	int node1, node2;
	for (int i = 0; i < E; i++)
	{
		cin >> node1 >> node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
}

void arrangeAdj() noexcept
{
	for (int i = 1; i <= V; i++)
	{
		if (adj[i].size() != 0)
			sort(adj[i].begin(),adj[i].end());
	}
}

void dfs(const int& node) noexcept
{
	visited[node] = true;
	dfs_nodes.push_back(node);
	

	for(const auto&ele: adj[node])
	{
		if (!visited[ele])
			dfs(ele);
	}
}

void bfs() noexcept
{
	queue<int> q;
	visited[Start] = true;
	q.push(Start);

	while (!q.empty())
	{
		int q_size = q.size();
		

		for (int i = 0; i < q_size; i++)
		{
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (const auto& ele: adj[node])
			{
				if (!visited[ele])
				{
					q.push(ele);
					visited[ele]= true;
				}
			}
		}
	}
}

void solve() noexcept
{
	input();
	arrangeAdj();
	dfs(Start);
	for(const auto&ele: dfs_nodes)
	{
		cout << ele << ' ';
		visited[ele] = false;
	}cout << endl;
	bfs();

}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();

	return (0);
}