#include <bits/stdc++.h>
#define endl '\n'
#define INF 98765432123456789ULL 
using namespace std;
using ull = unsigned long long;
using pui = pair<ull, int>; // {weight, node}

int V, E, K;
vector<vector<pui>> adj;
vector<priority_queue<ull>> dist; 

void input() {
    cin >> V >> E >> K;
    adj.resize(V + 1);
    dist.resize(V + 1);

    for (int i = 0; i < E; ++i) 
	{
        int from, to;
        ull w;
        cin >> from >> to >> w;
        adj[from].push_back({w, to});
    }
}

void solve() {
    priority_queue<pui, vector<pui>, greater<pui>> pq;
    pq.push({0, 1}); 
    dist[1].push(0); 

    while (!pq.empty())
	{
        ull w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto& [cost, next] : adj[node]) 
		{
            ull nextCost = w + cost;

            if (dist[next].size() < K) 
			{
                dist[next].push(nextCost);
                pq.push({nextCost, next});
            } else if (dist[next].top() > nextCost) 
			{
                dist[next].pop();
                dist[next].push(nextCost);
                pq.push({nextCost, next});
            }
        }
    }

    for (int i = 1; i <= V; ++i) 
	{
        if (dist[i].size() < K) 
		{
            cout << -1 << endl;
        } else 
		{
            cout << dist[i].top() << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}
