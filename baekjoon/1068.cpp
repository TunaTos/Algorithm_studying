#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERT 51
#define endl '\n'
using namespace std;


int root, node, erasedNode, res;

vector<int> adj[MAX_VERT]; // mother -> son
vector<bool> visited(MAX_VERT, false);

void showAdj()
{
	for (int i = 1; i <= node; i++)
	{
		cout << "I am node : i " << i << "//";
		for(auto& ele: adj[i])
		{
			cout << ele << " ";
		}
		cout << endl;
	}
	cout << "I am erased_node : " << erasedNode << endl;
	cout << "I am root node : " << root << endl;
}

void showVisited()
{
	cout << "I am visited : ";
	for(int i = 1; i <= node; i++)
	{
		cout << visited[i] << ' ';
	}cout << endl;
}

void input()
{
	int input;
	cin >> node;
	for (int i = 1; i <= node; i++)
	{
		cin >> input;
		if(input== -1)
			root = i;
		else
			adj[++input].push_back(i);
	}
	cin >> erasedNode;
	++erasedNode;
}

void dfs(const int& node)
{
	visited[node] = true;

	for(const auto& next: adj[node])
	{
		if (visited[next])
			continue;
		dfs(next);		
	}
}

void getResult()
{
	for (int i = 1; i <= node; i++)
	{
		if (visited[i]) continue;
		if (adj[i].size() == 0)
		{
			++res;
			continue;
		}
		int cnt = 0;
		for(const auto& ele: adj[i])
		{
			if (visited[ele])
				++cnt;
		}
		if(cnt ==adj[i].size())
			++res;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	//showAdj();
	dfs(erasedNode);
	//showVisited();
	getResult();
	cout << res;
	return (0);
}