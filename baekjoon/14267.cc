#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;


vector<vector<int>> adj;
int V, T; 
vector<ull> weights;
vector<bool> visited;


void showMap(unordered_map<int,int> map)
{
	for (const auto&ele: map)
		cout << ele.first << "  " << ele.second << endl;
	cout << endl;
}	

void input() 
{
	cin >> V >> T;
	adj.resize(V+1, vector<int>());
	weights.resize(V+1, 0);
	visited.resize(V+1, false);
	for (int i = 1; i <= V; i++)
	{
		int num;
		cin >> num;
		if (num == -1)
			continue;
		adj[num].push_back(i);
	}
}


void dfs(int node, const int& cost)
{
	visited[node] = true;
	weights[node] += cost;

	for (const auto& next: adj[node])
	{
		if (!visited[next])
			dfs(next, cost);
	}
}

void solve()
{
	input();

	int node; ull cost;
	unordered_map<int,int> map;



	for (int i = 0; i < T; i++)
	{
		cin >> node >> cost;
		if (map.find(node) == map.end()) // map에 없는 경우
			map[node] = cost;
		else
		{
			int val = map.at(node);
			map[node] += cost; // update
		}
	}
	// showMap(map);

	for (const auto& ele: map)
	{
		fill(visited.begin(), visited.end(),false);
		dfs(ele.first, ele.second);
	}
	
	for (int i = 1; i <= V; ++i)
		cout << weights[i] << " ";
	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}