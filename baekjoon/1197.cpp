#include <iostream>
#include <vector>
#include <algorithm>	
#define MAX_VERT 10001
#define MAX_EDGE 100001
using namespace std;

class Edge
{
public:
	int s_node;
	int e_node;
	int weight;

	Edge(int s_input, int e_input, int w_input) : s_node(s_input), e_node(e_input), weight(w_input) {}

	bool operator <(const Edge& other) const
	{
		return this->weight < other.weight;
	}
};

int parents[MAX_VERT];
int weight[MAX_VERT];
int V, E;
long long res;
vector<Edge> vec;

void show_vec();
void Input()
{
	int a, b, c;

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vec.emplace_back(a, b, c);
	}

	for (int i = 1; i <= V; i++)
	{
		parents[i] = i;
		weight[i] = 1;
	}
}

int Find(int a)
{
	if (parents[a] == a) return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	int roota = Find(a);
	int rootb = Find(b);

	if (roota == rootb) return;

	else if (weight[roota] < weight[rootb])
	{
		parents[rootb] = roota;
		weight[rootb] += weight[roota];
	}
	else
	{
		parents[roota] = rootb;
		weight[roota] += weight[rootb];
	}
}

void Solve()
{
	for (int i = 0; i < vec.size(); i++)
	{
		int s = vec[i].s_node;
		int e = vec[i].e_node;
		int w = vec[i].weight;

		if (Find(s) != Find(e)) // 아직 연결되지 않았더라면
		{
			Union(s, e);
			res += w;
		}
	}
}

int main()
{
	Input();
	sort(vec.begin(), vec.end());
	Solve();

	cout << res;


}

void show_vec()
{
	for (auto& ele : vec)
		cout << ele.s_node << " " << ele.e_node << " " << ele.weight << endl;
}