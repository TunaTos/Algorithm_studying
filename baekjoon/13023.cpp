#include <bits/stdc++.h>
#define MAX_VERT 2001
#define endl '\n'
using namespace std;

int V, E;
bool flag=false;
vector<int> adj[MAX_VERT];
vector<bool> visited(MAX_VERT, false);

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

void dfs(int node, int dpt) noexcept
{
	if (dpt == 5)
	{
		flag = true;
		return;
	}
	visited[node] = true;
	for(const auto&ele: adj[node])
	{
		if (!visited[ele])
			dfs(ele, dpt + 1);
	}
	visited[node] = false;
}

void solve() noexcept
{
	input();
	for (int i = 0; i < V; i++)
	{
		if (!flag)
			dfs(i, 1);
		fill(visited.begin(), visited.end(), false);
	}
	if (flag)
		cout << 1;
	else
		cout << 0;
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}