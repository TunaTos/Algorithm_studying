#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERT 1001
#define INF 987654321
#define endl '\n'
using namespace std;


int Vert, Edge;
vector<pair<int, int>> adj[MAX_VERT]; // {to, weight}
vector<int> dis(MAX_VERT, INF);
vector<int> From(MAX_VERT, 0);

void Debug();

void Input()
{
	cin >> Vert >> Edge;

	int from, to, weight;
	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}

}

void Dijkstra()
{
	priority_queue<pair<int, int>> pq; // {-weight, from}
	pq.push({ 0,1 });
	From[1] = 1;
	dis[1] = 0;

	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dis[from]) continue;


		for (auto& ele : adj[from])
		{
			int to = ele.first;
			int cost = ele.second;

			if (dis[to] > dis[from] + cost)
			{
				dis[to] = dis[from] + cost;
				From[to] = from;

				pq.push({ -dis[to],to });
			}
		}
	}
}

vector<pair<int,int>> getResult()
{
	vector<pair<int, int>> res;


	for (int i = 2; i <= Vert; i++)
	{
		if (From[i] == 0) continue;
		
		if (From[i] != i)
		{
			res.push_back({ i,From[i] });
		}
	}
	return res;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	Input();
	Dijkstra();
	vector<pair<int, int>> R = getResult();
	cout << R.size() << endl;
	for (auto& ele : R)
		cout << ele.first << " " << ele.second << endl;



	return 0;
}

void Debug()
{
	cout << "This is Dis" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << dis[i] << " ";
	}cout << endl;
	cout << "This is from" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << From[i] << " ";
	}cout << endl;
}