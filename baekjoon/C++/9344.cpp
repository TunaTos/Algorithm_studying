#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERT 10001
#define MAX_EDGE 20001
using namespace std;


class Edge
{
public:
	int from;
	int to;
	int weight;

	Edge(int input1, int input2, int inpu3) : from(input1), to(input2), weight(inpu3) {}
	
	bool operator < (Edge& other)
	{
		return this->weight < other.weight;
	}
	friend  ostream& operator << (ostream& os, Edge& e) 
	{
		os << e.from << " " << e.to << " " << e.weight;
		return os;
	}
};
int parents[MAX_VERT];
int weight[MAX_VERT];
int Tcase, V, E, t_start, t_end;
vector<Edge> vec;


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

	if (a == b) return;

	else if (weight[a] > weight[b])
		swap(a, b);

	parents[a] = b;
	weight[b] += weight[a];
	
}



// Function For Kruskal
void InputAndSort()
{
	int a, b, c;

	cin >> V >> E >> t_start >> t_end;
	
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vec.emplace_back(a, b, c);
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i <= V; i++)
	{
		parents[i] = i;
		weight[i] = 1;
	}
}

bool Solve()
{
	for (int i = 0; i < vec.size(); i++)
	{
		int a = vec[i].from;
		int b = vec[i].to;
		int c = vec[i].weight;


		if (Find(a) != Find(b))
		{
			Union(a, b);
			if (a == t_start && b == t_end)
				return true;
		}
	}
	return false;
}

void Reset()
{
	vec.clear();

}



int main()
{
	cin >> Tcase;
	for (int i = 0; i < Tcase; i++)
	{
		InputAndSort();
		if (Solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		Reset();

	}



	return 0;
}