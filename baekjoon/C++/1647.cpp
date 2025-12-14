#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VERT 100001
#define MAX_EDGE 1000001

using namespace std;

class Edge
{
public:
	int s_node;
	int e_node;
	int weight;

	Edge(int s, int e, int w) : s_node(s), e_node(e), weight(w) {}

	friend ostream& operator << (ostream& os, const Edge& e)
	{
		os << e.s_node << " " << e.e_node << " " << e.weight << " ";
		return os;
	}

	bool operator < (const Edge& other)
	{
		return this->weight < other.weight;
	}
};


int E, V;
int parents[MAX_VERT];
int weight[MAX_VERT];
unsigned long long res;
vector<int> list;
vector<Edge> vec;

//Function For Debug
void show_vec();

// Function For Init
void InputAndSort()
{
	int a, b, c;

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vec.emplace_back(a, b, c);
	}

	sort(vec.begin(), vec.end());
	for (int i = 1; i <= V; i++)
	{
		weight[i] = 1;
		parents[i] = i;
	}
}
// Function For Union Find
int Find(int a)
{
	if (parents[a] == a) return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (weight[a] > weight[b])
		swap(a, b);

	parents[a] = b;
	weight[b] += weight[a];
}

bool SameRoot(int a, int b)
{
	if (Find(a) == Find(b)) return true;
	else
		return false;
}

void Solve()
{

	for (int i = 0; i < E; i++)
	{
		int s = vec[i].s_node;
		int e = vec[i].e_node;
		int w = vec[i].weight;
		
		
		if (!SameRoot(s, e))
		{
			Union(s, e);
			list.push_back(w);
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	InputAndSort();
	Solve();

	for (int i = 0; i < list.size()-1; i++)
	{
		res += list[i];
	}
	cout << res;



	return 0;
}

void show_vec()
{
	for (auto& ele : vec)
		cout << ele << endl;
}