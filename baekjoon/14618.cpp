/*
동물들의 수(총깡, 짝폴) K마리 씩 키움

맡길 수 있는 집 -> A, B

총깡을 더 좋아함 -> 각 집에서 진서네 집으로 가장 빨리 오는 거
찾고싶어함 (총깡이가)


return값 
1.동물이 A형 집에서 와야하냐, B형을 와야하냐
2. 가장 빨리 오는 총깡이가 얼마나 떨어져있느냐
if 총깡이가 A형이나 B형이나 상관 없으면 A형이라고 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_VERT 5001
#define INF 2e9
using namespace std;
typedef long long ll;

int House, Vert, Edge, K; // K is number if Animal
vector<int> A_pos, B_pos;
vector<pair<int, ll>> adj[MAX_VERT]; // to weight

void show_dis(vector <ll> dis);

void Input()
{
	int input, from, to;
	ll weight;
	cin >> Vert >> Edge;
	cin >> House;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> input; A_pos.push_back(input);

	}
	for (int i = 0; i < K; i++)
	{
		cin >> input; B_pos.push_back(input);
	}

	
	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}
}

void Dijkstra(vector<int>& pos, vector<ll>& Dis) 
{
	/*
	기준이 되는 pos를 넣고 Dis를 구한다.
	*/

	priority_queue <pair<int, ll>> pq; // weight, from

	for (auto& ele : pos)
	{
		Dis[ele] = 0;
		pq.push({ 0,ele });
	}

	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

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
	vector<ll> A_Dis(Vert+1, INF);
	vector<ll> B_Dis(Vert+1, INF);

	Dijkstra(A_pos, A_Dis);
	Dijkstra(B_pos, B_Dis);

	//show_dis(A_Dis);
	//show_dis(B_Dis);

	ll A_val = A_Dis[House];
	ll B_val = B_Dis[House];

	if (A_val == INF && B_val == INF)
	{
		cout << -1;
	}
	else if (A_val != INF && B_val == INF)
	{
		cout << 'A' << '\n';
		cout << A_val;
	}
	else if (A_val == INF && B_val != INF)
	{
		cout << "B" << '\n';
		cout << B_val;
	}
	else
	{
		if (A_val <= B_val)
			cout << 'A' << '\n';
		else
			cout << 'B' << '\n';

		cout << min(A_val, B_val);
	}


	return 0;
}

void show_dis(vector<ll> dis)
{
	for (int i = 1; i <= Vert; i++)
	{
		cout << dis[i] << " ";
	}cout << endl;
}