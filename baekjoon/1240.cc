#include <bits/stdc++.h>
#define MAX_VERT 1001
#define endl '\n'
using namespace std;
using ull = unsigned long long;
using pui = pair<ull, int>;

int V, T;
vector<vector<pui>> adj;

void input()
{
	cin  >> V >> T;
	int from, to;
	ull w;
	adj.resize(V+1, vector<pui>());
	for (int i = 0; i < V - 1; i++)
	{
		cin >> from >> to >> w;
		adj[from].push_back(make_pair(w, to));
		adj[to].push_back(make_pair(w,from));
	}	
}

ull showDistance(const int& node1, const int& node2)
{
	// node1에서 node2의 distance를 구하는 함수
	
	vector<ull> dis(V+1, 0);
	vector<bool> visited(V+1, false);

	queue<pui> q;
	q.push(make_pair(0, node1));
	visited[node1] = true;


	while (!q.empty())
	{
		auto [weight, node] = q.front();
		q.pop();
		for (const auto& next: adj[node])
		{
			if (visited[next.second]) continue;

			dis[next.second] = dis[node] + next.first;
			visited[next.second] = true;
			q.push(make_pair(dis[next.second], next.second));	
		}
	}
	
	// for (int i = 1; i <= V; i++)
	// {
	// 	cout << dis[i] << " ";
	// }cout << endl;
	
	return dis[node2];
}



void solve()
{
	input();


	int node1, node2;
	for (int i = 0; i < T; i++)
	{
		cin >> node1 >> node2;
		cout << showDistance(node1, node2) << endl;
	}
	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}