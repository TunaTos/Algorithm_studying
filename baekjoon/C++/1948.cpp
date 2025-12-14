#include <bits/stdc++.h>
#define MAX_VERT 10001
#define endl '\n'
using namespace std;
using ull = unsigned long long;
using pui = pair<unsigned long, int>; // weight to

int V, E, From, To;
vector<pui> adj[MAX_VERT], r_adj[MAX_VERT];
vector<int> indegree, r_indegree;


void show_vec(const auto& vec) noexcept
{
	for (int i = 1; i <= V; i++)
	{
		cout << vec[i] << " ";
	}cout << endl;
}

void input() noexcept
{
	int from, to;
	ull weight;
	cin >> V >> E;
	indegree.assign(V+1, 0); r_indegree.assign(V+1, 0);
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		++indegree[to];
		++r_indegree[from];
		adj[from].push_back(make_pair(weight, to));
		r_adj[to].push_back(make_pair(weight, from));
	}
	cin >> From >> To;
}

vector<ull> get_distance(vector<pui> adj[],vector<int>& indegree,  int& start) noexcept
{
	
	vector<ull> res(V+1,0);
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for(auto& ele: adj[node])
		{	
			ull cost = ele.first;
			int to = ele.second;
	
			res[to] = max(res[to], res[node] + cost);
			indegree[to]--;
			if (indegree[to] == 0)
				q.push(to);
		}
	}
	return res;
}

int get_result(vector<ull>& distance, vector<ull>& r_distance) noexcept
{
	int res = 0;
	for (int i = 1; i <= V; i++)
	{
		for(auto&ele: adj[i])
		{	
			int j = ele.second;
			ull v = ele.first;

			if (distance[i] + r_distance[j] + v == distance[To])
				++res;
		}
	}
	return res;
}

void solve() noexcept
{
	input();
	// show_vec(indegree);
	// show_vec(r_indegree);
	auto Distance = get_distance(adj,indegree ,From);
	auto R_Distance = get_distance(r_adj,r_indegree, To);
	// show_vec(Distance);
	// show_vec(R_Distance);
	auto edge_num = get_result(Distance, R_Distance);

	cout << Distance[To] << endl << edge_num << endl;
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}