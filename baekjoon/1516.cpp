#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
typedef unsigned long long ull;
using namespace std;

int V;
vector<int> indegree;
vector<vector<int>> adj;
vector<ull> weight;
vector<ull> res;

// Function for Debuging
void show_indegree()
{
	cout << "This is indegree" << endl;
	for (int i = 1; i <= V; ++i)
		cout << indegree[i] << " ";
	cout << endl;
}

void show_res()
{
	cout << "This is res" << endl;
	for (int i = 1; i <= V; ++i)
		cout << res[i] << ' ';
	cout << endl;
}

void setDataStructures()
{
	indegree.resize(V + 1);
	adj.resize(V + 1);
	weight.resize(V + 1, 0);
	res.resize(V + 1,0);
}

void init()
{
	for (size_t i = 1; i <= V; ++i)
	{
		ull input;
		cin >> input; 
		weight[i] = res[i] = input;

		while (1)
		{
			cin >> input;
			if (input == -1)
				break;
			++indegree[i];
			adj[input].push_back(i);
		}
	}
}

void topologicalSort()
{
	queue<int> q;
	
	for (size_t i = 1; i <= V; ++i)
	{
		if (!indegree[i])
			q.push(i);
	}

	while (!q.empty())
	{
		int from = q.front();
		q.pop();

		for (auto& to : adj[from])
		{
			res[to] = max(res[to], res[from] + weight[to]);
			--indegree[to];
			if (!indegree[to])
				q.push(to);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V;
	setDataStructures();
	init();
	topologicalSort();
	
	for (size_t i = 1; i <= V; ++i)
		cout << res[i] << endl;
	return (0);
}