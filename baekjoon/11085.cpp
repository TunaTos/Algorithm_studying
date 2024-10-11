#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_VERT 1001
#define MAX_EDGE 50001

using namespace std;
class Edge
{
public:
	int start;
	int end;
	int weight;

	Edge(int input1, int input2, int input3) : start(input1), end(input2), weight(input3)
	{}

	bool operator < (Edge& e) const
	{
		return this->weight > e.weight;
	}
};

int parents[MAX_VERT];
int V, E, c, v;
vector<Edge> vec;
// Function For UnionFind
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

	else if (a < b)
		parents[b] = a;

	else
		parents[a] = b;
}


// Function For Debug
void show_vec()
{
	for (auto& ele : vec)
		cout << ele.start << " " << ele.end << " " << ele.weight << endl;
}

//Function For Input
void Input()
{
	cin >> V >> E;
	cin >> c >> v;
	int a, b, c;

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vec.emplace_back(a, b, c);
	}

	sort(vec.begin(), vec.end());

	for (int i = 1; i <= V; i++)
		parents[i] = i;
}


int Solve()
{
	int res = 1000000;

	for (size_t i = 0; i < vec.size(); i++)
	{
		int a = vec[i].start;
		int b = vec[i].end;
		int f = vec[i].weight;


		if (Find(a) != Find(b))
		{
			Union(a, b);
			if (Find(c) == Find(v))
				return f;
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	//show_vec();
	cout << Solve();


}