#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Topological
{
private:
	int V, E;
	vector<vector<int>> adj;
	vector<int> indegree;
public:
	Topological(const int& v_input, const int& e_input):
		V(v_input), E(e_input), adj(V+1, vector<int>()), indegree(V+1, 0) {};
	void addEdge(const int& from, const int& to)
	{
		adj[from].push_back(to);
		indegree[to]++;
	}

	void getTopologicalOrder()
	{
		queue<int> q;
		for (int i = 1; i <= V; i++)
		{
			if (indegree[i] == 0)
				q.push(i);
		}
		
		while (!q.empty())
		{
			int from = q.front();
			q.pop();

			cout << from << " ";

			for (const auto& next: adj[from])
			{
				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
			}
		}
	}
};


void solve()
{
	int v, e, from, to;
	cin >> v >> e;
	auto T = Topological{v,e};

	for (int i = 0; i < e; i++)
	{
		cin >> from >> to;
		T.addEdge(from, to);
	}
	T.getTopologicalOrder();
	
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}