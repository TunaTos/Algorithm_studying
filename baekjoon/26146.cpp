#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_VERT 200001
#define MAX_EDGE 500001
using namespace std;

vector<vector<int>> adj(MAX_VERT);
vector<vector<int>> revAdj(MAX_VERT);
vector<int> sccNum(MAX_VERT);
vector<bool> visited(MAX_VERT, false);
vector<int> order; 
int V, E, scc;

void showVector()
{
	for (int i = 1; i <= V; i++)
		cout << sccNum[i] << " ";
	cout << endl;
}

void input()
{
	int from, to;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to);
		revAdj[to].push_back(from);
	}
}

void dfsAdj(const int& node)
{
	visited[node] = true;
	
	for (auto& next : adj[node])
	{
		if (!visited[next])
			dfsAdj(next);
	}
	order.push_back(node); 
}

void dfsRev(const int& node, int sccNumber)
{
	visited[node] = true;
	sccNum[node] = sccNumber;

	for (auto& next : revAdj[node])
	{
		if (!visited[next])
			dfsRev(next, sccNumber);
	}
}

void getScc()
{
	for (int i = 1; i <= V; i++)
		if (!visited[i])
			dfsAdj(i);

	fill(visited.begin(), visited.end(), false); // visited 초기화

	// order를 역순으로 처리
	for (int i = order.size() - 1; i >= 0; i--)
	{
		int node = order[i];

		if (!visited[node])
			dfsRev(node, ++scc);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	getScc();
	if (scc == 1) cout << "Yes";
	else
		cout << "No";

	return 0;
}
