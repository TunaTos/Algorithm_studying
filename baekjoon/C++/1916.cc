#include <bits/stdc++.h>
#define endl '\n'
#define MAX_V 1001
#define INF 987654321
using namespace std;
using ull = unsigned long long;
using pui = pair<ull,int>; // weight, node


template<typename T>
void showContainer(const T& container)
{
	for (const auto& ele: container)
		cout << ele << ' ';
	cout << endl;
}

class Solver
{
private:
	int V, E;
	vector<vector<pui>> adj;
	vector<ull> dis;

public:
	Solver() = default;
	Solver(const int& v_input, const int& e_input):
		V(v_input), E(e_input), adj(V+1, vector<pui>()), dis(V+1, INF) {
			int from, to;
			ull w;
			for (int i = 0; i < this->E; i++)
			{
				cin >> from >> to >> w;
				adj[from].push_back(make_pair(w,to));
				// adj[to].push_back(make_pair(w, from));	
			}
		};
	vector<ull> getDistance() {return this->dis;}
	ull dijkstra(const int& s, const int& e)
	{
		priority_queue<pui, vector<pui>, greater<pui>> pq;
		pq.push(make_pair(0, s));
		dis[s] = 0;

		while (!pq.empty())
		{
			auto [weight, startNode] = pq.top();
			pq.pop();

			if (dis[startNode] < weight) continue;

			for (auto [cost, nextNode]: adj[startNode])
			{
				if (dis[nextNode] > dis[startNode] + cost)
				{
					dis[nextNode] = dis[startNode] + cost;
					pq.push(make_pair(dis[nextNode], nextNode));
				}
			}
		}
		return dis[e];
	}

};


void solve()
{
	
	int v, e, start, end;
	cin >> v >> e;
	
	auto S = Solver{v,e};
	cin >> start >> end;

	cout << S.dijkstra(start,end);

}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}