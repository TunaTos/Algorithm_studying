#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERT 1001

using namespace std;

class Edge
{
public:
	int start;
	int end;
	int weight;

	Edge(int input1, int input2, int input3) : start(input1), end(input2), weight(input3)
	{}
	bool operator < (Edge& e)
	{
		return this->weight < e.weight;
	}	
};

int parents[MAX_VERT];
int weight[MAX_VERT];
int V, E, Case;
vector<Edge> vec;

void show_vec();

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
		parents[b] = a;
		weight[a] += weight[b];
	}
	else
	{
		parents[a] = b;
		weight[b] += weight[a];
	}
}

void Input()
{
	cin >> V >> E >> Case;
	int a, b;

	for (int i = 1; i <= E; i++)
	{
		cin >> a >> b;
		vec.emplace_back(a, b, i);
	}


	sort(vec.begin(), vec.end());

	for (int i = 1; i <= V; i++)
	{
		parents[i] = i; weight[i] = 1;
	}
}

long long Solve(int index)
{
	int v_num = 0;
	long long res = 0;

	for (int i = index; i <vec.size(); i++)
	{
		int a = vec[i].start;
		int b = vec[i].end;
		int c = vec[i].weight;

		if (Find(a) != Find(b))
		{
			Union(a, b);
			v_num++;
			res += c;
			if (v_num == V - 1)
			{
				return res;
			}
		}
	}
	if (v_num != V - 1)
		return 0;
}

void Reset()
{
	for (int i = 1; i <= V; i++)
	{
		parents[i] = i; weight[i] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	for (int i = 0; i < Case; i++)
	{
		cout << Solve(i) << " ";
		Reset();
	}
}
void show_vec()
{
	cout << "This is vec" << endl;
	for (auto& ele : vec)
		cout << ele.start << " " << ele.end << " " << ele.weight << endl;
}