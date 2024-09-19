#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <string>
#define endl '\n'
using namespace std;

const int MAX_VERT = 100001;
const string errorMessage = "Confused";
vector<int> adj[MAX_VERT], revAdj[MAX_VERT], sccNumber(MAX_VERT);
vector<int> sccComponent[MAX_VERT];

vector<bool> visited(MAX_VERT,false);
stack<int> Stack;

int Tcase, V, E, scc;

void input() noexcept
{
	int from, to;
	cin >> V >> E;
	
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to;
		adj[from].push_back(to), revAdj[to].push_back(from);
	}
}

void dfsInAdj(const int& node) noexcept
{
	visited[node] = true;

	for (const auto& next : adj[node])
	{
		if (!visited[next])
			dfsInAdj(next);
	}
	Stack.push(node);
}

void dfsInRev(const int& node, const int& s) noexcept
{
	visited[node] = true;
	sccNumber[node] = s;
	sccComponent[s].push_back(node);
	for (const auto& next : revAdj[node])
	{
		if (!visited[next])
			dfsInRev(next, s);
	}
}

void getScc() noexcept
{
	for (int i = 0; i < V; i++)
		if (!visited[i])
			dfsInAdj(i);
	
	std::fill(visited.begin(), visited.begin() + V, false);

	while (!Stack.empty())
	{
		int node = Stack.top();
		Stack.pop();

		if (!visited[node])
		{
			dfsInRev(node, ++scc);
		}
	}
}

void getResult() noexcept
{
	vector<int> indegree(scc + 1, 0);

	for (int i = 0; i < V; i++)
	{
		for (const auto& next : adj[i])
			if (sccNumber[i] != sccNumber[next])
				++indegree[sccNumber[next]];
	}

	vector<int> startPoint;
	for (int i = 1; i <= scc; i++)
		if (indegree[i] == 0)
			startPoint.push_back(i);
	if (startPoint.size() != 1)
		cout << errorMessage << endl;
	else
	{
		sort(sccComponent[startPoint[0]].begin(), sccComponent[startPoint[0]].end());
		for (const auto& ele : sccComponent[startPoint[0]])
			cout << ele << endl;
	}
}


void reset() noexcept
{
	for (int i = 0; i <= V; i++)
	{
		adj[i].clear(); revAdj[i].clear();
		visited[i] = false;
	}
	for (int i = 0; i <= scc; i++)
	{
		sccNumber[i] = 0;
		sccComponent[i].clear();
	}
	scc = 0;


}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Tcase;
	for (int i = 0; i < Tcase; i++)
	{
		input();
		getScc();
		getResult();
		cout << endl;
		reset();
	}

	return 0;
}
