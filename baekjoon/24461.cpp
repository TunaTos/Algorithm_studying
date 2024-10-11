#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_EDGE 200000

int Directed[MAX_EDGE];
vector<int> adj[MAX_EDGE];
int E, s_vert = 300000, e_vert = -1;
queue<int> Leaf;
bool Node[MAX_EDGE]; 

void show_adj();
void show_directed();



void Input()
{

	cin >> E;
	int from, to;

	for (int i = 0; i < E-1; i++)
	{
		cin >> from >> to;
		if (from > to) swap(from, to);

		if (s_vert > from) s_vert = from;
		if (e_vert < to) e_vert = to;

		adj[from].push_back(to);
		adj[to].push_back(from);

		Directed[from]++;
		Directed[to]++;
	}
	memset(Node, true, sizeof(Node));

}

bool is_lined()
{
	int cnt = 0;

	for (int i = s_vert; i <= e_vert; i++)
	{
		if (Directed[i] >= 2) return false;
		if (Directed[i] == 1) cnt++;
	}
	if (cnt <= 2) return true;
	else
		return false;
}


void cutLeaf()
{
	

	while (Leaf.size()>2)
	{
		int Len = Leaf.size();
		for (int i = 0; i < Len; i++)
		{
			int from = Leaf.front();
			int to = adj[from][0];
			
			Leaf.pop();

			Directed[from]--;
			Directed[to]--;


			if (Directed[from] == 0) Node[from] = false;
			if (Directed[to] == 1) Leaf.push(to);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	for (int i = s_vert; i <= e_vert; i++)
	{
		if (Directed[i] == 1) Leaf.push(i);
	}

	cutLeaf();
	for (int i = s_vert; i <= e_vert; i++)
	{
		if (Node[i]) cout << i << " ";
	}

	return 0;
}


void show_adj()
{
	cout << "This is adj : " << endl;
	for (int i = s_vert; i <= e_vert; i++)
	{
		cout << i << " ";
		for (auto& ele : adj[i])
			cout << ele << " ";
		cout << endl;
	}
}


void show_directed()
{
	cout << "This is directed : " << endl;
	for (int i = s_vert; i <= e_vert; i++)
	{
		cout << Directed[i] << " ";
	}cout << endl;

}
