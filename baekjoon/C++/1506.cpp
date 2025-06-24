#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#define endl '\n'
using namespace std;
typedef unsigned long long ull;

int V;
ull res;
vector<ull> weight;
vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<bool> visited;
stack<int> dfs_nodes;

void show_adj()
{
	for (int i = 1; i <= V; i++)
	{
		cout << "This is i : ";
		for (auto& ele : rev_adj[i])
			cout << ele << ' ';
		cout << endl;
	}

}


void init()
{
	string input;
	cin >> V;
	weight.resize(V + 1); adj.resize(V + 1); rev_adj.resize(V + 1);

	for (size_t i = 1; i <= V; ++i)
		cin >> weight[i];

	for (int i = 1; i <= V; ++i)
	{
		cin >> input;
		for (int j = 0; j < V; ++j)
		{
			if (input[j] == '1')
			{
				adj[i].push_back(j + 1);
				rev_adj[j + 1].push_back(i);
			}
		}
	}
}

void dfsFirst(const int& node)
{
	visited[node] = true;

	for (auto& next : adj[node])
	{
		if (!visited[next])
			dfsFirst(next);
	}
	dfs_nodes.push(node);
}

void dfsSecond(const int& node, vector<int>& node_weights)
{
	visited[node] = true;
	node_weights.push_back(weight[node]);
	for (auto& next : rev_adj[node])
	{
		if (!visited[next])
			dfsSecond(next, node_weights);
	}


}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	init();
	//show_adj();
	visited.resize(V + 1, false);
	for (int i = 1; i <= V; i++)
		if (!visited[i])
			dfsFirst(i);
	fill(visited.begin(), visited.end(), false);

	while (!dfs_nodes.empty())
	{
		int v = dfs_nodes.top();
		dfs_nodes.pop();

		if (visited[v]) continue;

		vector<int> node_weights;
		dfsSecond(v, node_weights);
		sort(node_weights.begin(), node_weights.end());
		res += node_weights[0];
	}
	cout << res;
	return (0);
}