/*
도시끼리는 단방향 거리 -> 거리는 서로 다른 수 있음
도시 사이에 도로가 없을 수도, 여러개가 있을수도 있음
어떤 도시에서도 다른 도시로 무조건 연결되어 있음

최대 Weight는 5e10

거리가 가장 큰 도시번호, weight의 값
도시번호가 여러개면 작은 번호 

풀이 : Multisource Dijkstra 사용하고 priority queue사용
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define INF 5e15
#define MAX_VERT 100001
using namespace std;
typedef long long ll;

int Vert, Edge, K;
bool Com[MAX_VERT];
vector<pair<int, ll>> adj[MAX_VERT];
vector<ll> Dis(MAX_VERT, INF);
ll res = -1;

void show_dis();
void show_com();


void Input()
{
	int from, to, weight, input;
	cin >> Vert >> Edge >> K;

	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[to].push_back({ from,weight });
	}
	
	for (int i = 0; i < K; i++)
	{
		cin >> input;
		Com[input] = true;
	}
}

void Dijkstra()
{
	priority_queue<pair<ll, int>> pq; // -weight, from

	for (int i = 1; i <= Vert; i++)
	{
		if (Com[i])
		{
			pq.push({ 0,i });
			Dis[i] = 0;
		}	
	}

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		
		if (weight > Dis[from]) continue;
		if (Dis[from] > res) res = Dis[from];


		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = ele.second;

			if (Dis[to] > Dis[from] + cost)
			{
				Dis[to] = Dis[from] + cost;
				pq.push({ -Dis[to],to });
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	
	Dijkstra();

	//show_dis();
	//show_com();

	for (int i = 1; i <= Vert; i++)
	{
		if (Dis[i] == res)
		{
			cout << i << endl;
			break;
		}
	}
	cout << res;

	return 0;
}


void show_dis()
{
	cout << "This is dis" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << Dis[i] << " ";
	}cout << endl;
}
void show_com()
{
	cout << "This is Com" << endl;
	for (int i = 1; i <= Vert; i++)
	{
		cout << Com[i] << " ";
	}cout << endl;
}