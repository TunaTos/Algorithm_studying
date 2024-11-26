#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void println(const auto str, const auto container)
{
	cout << str << " ";
	for(auto&ele: container)
		cout << ele << endl;
	cout << endl;
}

class Edge
{
public:
	int from, to, weight;
	Edge(const int& f_input, const int& t_input, const int& w_input):
		from(f_input), to(t_input), weight(w_input) {};
	bool operator < (const Edge& other)
	{
		return this->weight < other.weight;
	}
	friend ostream& operator << (ostream& out, const Edge& e)
	{
		out << e.from << " " << e.to << " " << e.weight;
		return out;
	}
};


int V, E;
ll max_weight, mst_sum;
vector<Edge> edges;
vector<int> parents, weights;

// Function For Union-Find
int Find(int& a)
{
	if (parents[a] == a)
		return a;
	else 
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);

	if (a == b) return;

	else if (weights[a] <= weights[b])
	{
		weights[b] += weights[a];
		parents[a] = parents[b];
	}
	else
	{
		weights[a] += weights[b];
		parents[b] = parents[a];
	}
}


void input()
{
	int from, to, weight;
	cin >> V >> E;

	parents.resize(V+1, 0);
	std::iota(parents.begin(), parents.end(), 0);
	weights.assign(V+1 , 1);

	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> weight;
		edges.emplace_back(Edge{from, to, weight});
		max_weight += weight;
	}
	
	sort(edges.begin(), edges.end());

	// println("This is edges", edges);
}


bool kruskal()
{ 
	ll edge_num = 0;

	for(auto[from, to, weight]: edges)
	{
		// cout << from << " " << to << " " << weight;
		from = Find(from); to = Find(to);

		if (from == to) continue;

		Union(from, to);
		mst_sum += weight;
		++edge_num;

		if (edge_num == V-1)
			return true;
	}

	return edge_num == (V-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	if (kruskal())
		cout << max_weight - mst_sum;
	else
		cout << -1;
	cout << endl;
	// cout << max_weight << " " << mst_sum;

	return (0);
}