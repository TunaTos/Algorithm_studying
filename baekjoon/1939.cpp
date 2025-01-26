#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_ISLAND 10001

using namespace std;

class Edge
{
public:
	int xpos;
	int ypos;
	int weight;
	
	Edge(int x_input, int y_input, int w_input)
	{
		this->xpos = x_input;
		this->ypos = y_input;
		this->weight = w_input;
	}

	bool operator < (Edge& other) const
	{
		return this->weight > other.weight;
	}	
	friend ostream& operator <<  (ostream& os, Edge e) 
	{
		os << e.xpos << " " << e.ypos << " " << e.weight;
		return os;
	}
};

int weight[MAX_ISLAND];
int parents[MAX_ISLAND];
int N, M,from,to;
long res1 = 2000000000;
long res2;


vector<Edge> v;
void show_vector();
void show_weight();
void show_parents();

void InputAndSort()
{

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v.emplace_back(a, b, c);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
	{
		parents[i] = i;
		weight[i] = 1;
	}
	cin >> from >> to;
}
// Function for Union Find
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
	{
		weight[a] += weight[b];
		parents[b] = parents[a];
	}
	else
	{
		weight[b] += weight[a];
		parents[a] = parents[b];
	}
}

bool SameParents(int a, int b)
{
	if (Find(a) == Find(b)) return true;
	else
		return false;
}


bool Solve()
{


	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].xpos;
		int b = v[i].ypos;
		int c = v[i].weight;
		if (a == from && b == to || a==to && b==from)
			continue;
		
		else if (!SameParents(a, b))
		{
			Union(a, b); 
			res1 = min(res1, (long)c);
		}
		if (SameParents(from, to))
		{
			return true;
		}
	}
	return false;
}

void getRes2()
{
	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].xpos;
		int b = v[i].ypos;
		int c = v[i].weight;

		if (a == from && b == to || a == to && b == from)
		{
			res2 = max(res2, (long)c);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	InputAndSort();
	bool flag = Solve();
	getRes2();
	
	if (flag)
	{
		cout << max(res1, res2);
	}
	else
		cout << res2;








	return 0;
}


void show_vector()
{
	cout << "This is vector" << endl;
	for (auto& ele : v)
		cout << ele << endl;

}

void show_weight()
{
	cout << "This is weight" << endl;
	for (int i = 1; i <= N; i++)
		cout << weight[i] << " ";
}
void show_parents()
{
	cout << "This is parents" << endl;
	for (int i = 1; i <= N; i++)
		cout << parents[i] << " ";
	
}