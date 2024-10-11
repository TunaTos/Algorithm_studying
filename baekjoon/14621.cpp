#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERT 1001
#define MAX_EDGE 10001
#define WOMAN 'W'
#define MAN 'M'
using namespace std;

class Edge
{
public:
	int start;
	int end;
	int weight;


	Edge(int input1, int input2, int input3) : start(input1), end(input2), weight(input3) {}

	bool operator < (const Edge& e) const
	{
		return this->weight < e.weight;
	}

	friend ostream& operator << (ostream& os, const Edge& e)
	{
		os << e.start << " " << e.end << " " << e.weight;
		return os;
	}
};

int parents[MAX_VERT], weight[MAX_VERT];
char color[MAX_VERT];
bool visited[MAX_VERT];
int V, E, res, tmp;
vector<Edge> vec;

//Function for Debug
void show_vec();
void show_another();
// Function for Union-Find
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

	if (b > a) swap(a, b);

	// a가 더 큰 경우
	parents[b] = a;
	weight[a] += weight[b];
}

// Function for input
void InputAndSort()
{
	int a, b, c;

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
	{
		cin >> color[i];
	}

	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		vec.emplace_back(a, b, c);
	}

	sort(vec.begin(), vec.end());
}

void Init()
{
	for (int i = 1; i <= V; i++)
	{
		weight[i] = 1; parents[i] = i;
	}
}

void Solve()
{
	// 남자와 여자길들만 연결할 수 있음
	// 모든 경로를 만들지 못한다면 false return함
	for (int i = 0; i < vec.size(); i++)
	{
		int a = vec[i].start;
		int b = vec[i].end;
		int c = vec[i].weight;

		if (color[a] == color[b]) continue;

		if (Find(a) != Find(b))
		{
			Union(a, b);
			res += c;
			tmp++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	InputAndSort();
	Init();

	Solve();

	if (tmp != V - 1)
		cout << -1;
	else
		cout << res;



}

void show_vec()
{
	for (auto& ele : vec)
		cout << ele << endl;
}

void show_another()
{
	cout << "This is par" << endl;
	for (int i = 1; i <= V; i++)
		cout << parents[i] << " ";
	cout << endl;

	cout << "This is weight" << endl;
	for (int i = 1; i <= V; i++)
		cout << weight[i] << " ";

	cout << endl;

	
}