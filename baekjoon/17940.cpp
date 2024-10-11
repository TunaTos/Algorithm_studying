#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654
#define MAX_VERT 1001

using namespace std;

int Vert, Target;
int color[MAX_VERT];
vector<int> dis(MAX_VERT, INF);
vector<pair<int, int>> adj[MAX_VERT]; // {to,weight}



void show_color();
void show_adj();
void show_dis();

void Input()
{
	cin >> Vert >> Target;
	Target++;

	for (int i = 1; i <= Vert; i++)
		cin >> color[i];
	
	int val;
	for (int i = 1; i <= Vert; i++)
	{
		for (int j = 1; j <= Vert; j++)
		{
			cin >> val;
			if (!val) continue;
			else
			{
				adj[i].push_back({ j,val });
			}
		}
	}
}

pair<int,int> Dijkstra()
{
	priority_queue < pair<int, pair<int, int>>> pq; // 몇 번 바꾸었는지, weight, from
	pq.push({ 0,{0,1} });
	dis[1] = 0;
	
	while (!pq.empty())
	{
		int cnt = -pq.top().first;
		int weight = -pq.top().second.first;
		int from = pq.top().second.second;
		pq.pop();
		
		if (from == Target) return { cnt, dis[from] };


	
			
			for (auto& ele : adj[from])
			{
				int to = ele.first;
				int cost = ele.second;

				if (dis[to] > dis[from] + cost)
				{
					dis[to] = dis[from] + cost;
					
					if (color[from] == color[to]) // 색상이 같은 경우
						pq.push({ -cnt,{-dis[to],to} });
					else if (color[from] != color[to])
						pq.push({ -cnt - 1,{-dis[to],to} });	
				}
			}
		
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	pair<int, int> res = Dijkstra();
	cout << res.first << " " << res.second;

	//show_color();
	//show_dis();




	return 0;
}


void show_color()
{
	cout << "This is color" << endl;
	for (size_t i = 1; i <= Vert; i++)
	{
		cout << color[i] << " ";
	}cout << endl;
}
void show_adj()
{
	cout << "This is adj" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << i << " ";
		for (auto& ele : adj[i])
			cout << ele.first << " " << ele.second << " ";
		cout << endl;

	}
}

void show_dis()
{
	cout << "This is dis" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << dis[i] << " ";
	}cout << endl;
}