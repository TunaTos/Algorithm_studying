#include <bits/stdc++.h>
#define endl '\n'
#define MAX_VERT 100001
#define MAX_EDGE 300001
#define INF 1e14
using namespace std;
using ull = unsigned long long;
using pui = pair<unsigned long long, int>;

class Edge
{
public:
	ull weight;
	int from, to;

	Edge(const ull& w_input, const int& f_input, const int& t_input):
		weight(w_input), from(f_input), to(t_input) {};
	bool operator >(const Edge& other)
	{
		return weight > other.weight;
	}
	friend ostream& operator <<(ostream& out, const Edge& e)
	{
		out << e.from << " " << e.to << e.weight;
		return out;
	}
};

int start_node, target_node, V, E;
vector<pui> adj[MAX_VERT]; // weight to

template<typename T>
void showVector(const T& t) noexcept
{
	for (int i = 1; i <= V; i++)
		cout << t[i] << " ";
	cout << endl;
}

void showAdj() noexcept
{
	for (int i = 1; i <= V; i++)
	{
		cout << "This is i : " << i << " : ";
		for(auto& ele: adj[i])
		{
			cout << ele.second << " " << ele.first << " / ";
		}cout << endl;
	}
}

void input() noexcept
{
	int from, to;
	ull weight;
	cin >> V >> E;
	cin >> start_node >> target_node;


	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		adj[from].emplace_back(make_pair(weight,to));
		adj[to].emplace_back(make_pair(weight,from));
	}
}

bool dijkstra(const int& thresh) noexcept
{
	priority_queue<pui,vector<pui>,greater<pui>> pq;
	pq.push({0,start_node});
	vector<ull> Distance(MAX_VERT,INF);
	Distance[start_node] = 0;

	while (!pq.empty())
	{
		auto node = pq.top();
		ull dis = node.first;
		int from = node.second;
		pq.pop();

		if (Distance[from] < dis)
			continue;

		for(auto& next: adj[from])
		{
			ull cost = next.first;
			int to = next.second;
			if (cost < thresh)
				continue;
			if (Distance[to] > Distance[from] + cost )
			{
				Distance[to] = Distance[from] + cost;
				pq.push({Distance[to], to});
			}
			//showVector(Distance);
		}
	}
	//cout << "I am thresh : " << thresh << endl;
	//showVector(Distance);
	return Distance[target_node] != INF;
}

int b_searching() noexcept
{
	int left = 1;
	int right = 1000000;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (dijkstra(mid))
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return right;
}


void solve() noexcept
{
	input();
	//showAdj();
	int res = b_searching();
	cout << res;
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
	
	return (0);
}