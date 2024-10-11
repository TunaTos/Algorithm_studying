#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
	int u;
	int v;
	int w;
	Edge(const int& u_input, const int& v_input, const int& w_input) :
		u(u_input), v(v_input), w(w_input) {}
	bool operator < (const Edge& other) const
	{
		return this->w < other.w;
	}
	ostream& operator << (ostream& out)
	{
		out << this->u << " " << this->v << " " << this->w;
		return out;
	}
};
int V, E;
vector<int> parent;
vector<int> weight;
vector<vector<int>> matrix;
vector<Edge> edges;

void show_edges()
{
	cout << "This is Edges" << endl;
	for (const auto ele : edges)
		cout << ele.u << " " << ele.v << " " << ele.w << endl;
}

int Find(const int& a)
{
	if (parent[a] == a) return a;
	else
		return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	if (a == b) return;
	else if (weight[a] > weight[b])
	{
		parent[b] = a;
		weight[a] += weight[b];
	}
	else
	{
		parent[a] = b;
		weight[b] += weight[a];
	}
}


void Init()
{
	matrix.resize(V + 1);
	for (size_t i = 1; i <= V; ++i)
		matrix[i].resize(V + 1);
	parent.resize(V + 1);
	for (int i = 0; i <= V; i++)
		parent[i] = i;
	weight.resize(V + 1, 1);
}

void set_edges()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			cin >> matrix[i][j];
			if (i < j)
				edges.emplace_back(i, j, matrix[i][j]);
		}
	}
}

void mst()
{
	sort(edges.begin(), edges.end());
	int e = 0;
	unsigned long long res = 0;
	for (auto& ele : edges)
	{
		if (Find(ele.u) != Find(ele.v))
		{
			res += ele.w;
			Union(ele.u, ele.v);
		}
	}
	cout << res;
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V;
	Init();
	set_edges();
	mst(); cout << endl;
	//show_edges();
	return 0;
}