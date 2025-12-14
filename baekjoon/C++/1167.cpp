#include <iostream>
#include <algorithm>	
#include <vector>
#include <queue>
#include <cstring>
#define MAX_VERT 100001

using namespace std;
int V;
bool visited[MAX_VERT];
vector<pair<int, int>> adj[MAX_VERT]; // <To,Weight>
unsigned long long Distance[MAX_VERT];

void show_adj();

int is_possible()
{
	bool flag = false;

	for (int i = 1; i <= V; i++)
	{
		if (adj[i].size() != 0) return i;
	}


	return -1;

}
void Input()
{
	int start, end, weight;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		cin >> start;

		while (true)
		{
			cin >> end;
			
			if (end == -1) break;
			
			cin >> weight;
			adj[start].push_back({ end,weight });
			adj[end].push_back({ start,weight });
		}
	}
}


int BFS(int& node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	unsigned long long Max = 0;
	int max_pos = node;

	while (!q.empty())
	{
		int from = q.front();
		unsigned long long Cost = Distance[from];
		q.pop();
		

		for (auto& ele : adj[from]) // to weight
		{
			int target = ele.first;
			unsigned long long weight = ele.second;

			if (visited[target]) continue;

			else
			{
				visited[target] = true;
				q.push(target);
				Distance[target] = Cost + weight;
				if (Distance[target] > Distance[max_pos])
					max_pos = target;
			}
		}
	}
	return max_pos;


}

void Reset()
{
	memset(visited, false, sizeof(visited));
	memset(Distance, 0, sizeof(Distance));


}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	


	Input();
	int a = is_possible();
	if (a == -1)
	{
		cout << 0;
		return 0;
	}

	int start = BFS(a);
	Reset();

	int res_pos = BFS(start);
	cout << Distance[res_pos];






	return 0;
}



void show_adj()
{
	cout << "This is adj :" << endl;

	for (int i = 1; i <= V; i++)
	{
		cout << i << " ";
		for (auto& ele : adj[i])
			cout << ele.first << " " << ele.second << " ";
		cout << endl;
	}
}