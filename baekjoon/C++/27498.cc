#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;


ull totalWeight, mstWeight;
int N, E, mstEdgeCount;
vector<int> parents;
vector<int> weights;

int Find(int a)
{
	if (parents[a] == a)
		return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a), b = Find(b);

	if (a == b)
		return ;
	
	else if (weights[a] <= weights[b])
	{
		weights[b] += weights[a];
		parents[a] = b;
	}
	else
	{
		weights[a] += weights[b];
		parents[b] = a;
	}
}

class Edge
{
public:
	int from, to;
	ull weight;

	Edge(const int& from, const int& to, const ull& weight):
		from(from), to(to), weight(weight) {
		}
	
	bool operator <(const Edge& other)
	{
		return this->weight > other.weight;
	}
	friend ostream& operator << (ostream& out, Edge e)
	{
		out << e.from << " " << e.to << " " << e.weight;
		return out;
	}
};
vector<Edge> edges;


template<typename T>
void showContainer(const T& t)
{
	for (const auto& ele: t)
		cout << ele << endl;
	cout << endl;
}

void input()
{
	cin >> N >> E;
	int from, to; ull w;
	
	parents.resize(N+1, 0);
	weights.resize(N+1, 1);
	iota(parents.begin(), parents.end(), 0);

	
	for (int i = 0; i < E; i++)
	{
		bool isDone;
		cin >> from >> to >> w;
		totalWeight += w;
		Edge E(from, to, w);

		cin >> isDone;
		if (isDone) {
			mstWeight += w;
			mstEdgeCount++;
			Union(from, to);
		}
		else
			edges.push_back(E);
	}
}

void Kruskal()
{
	sort(edges.begin(), edges.end());

	if (mstEdgeCount == N-1)
		return;
	
	for (const auto& edge: edges)
	{
		int from = edge.from;
		int to = edge.to;
		ull w = edge.weight;

		if (Find(from) == Find(to)) // k각
			continue;
		

		Union(from, to);
		mstEdgeCount++;
		mstWeight += w;

		if (mstEdgeCount == N-1)
			return;
		

	}
}


void solve()
{
	input();
	// showContainer(parents);
	// showContainer(weights);
	// showContainer(edges);
	Kruskal();

	cout << totalWeight - mstWeight;
}





int main(void)
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	solve();

	// cout << Edge(1,2,3);
	return 0;
}