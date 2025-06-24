#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_VERT 10001
#define INF 1e15
#define endl '\n'
using namespace std;
typedef long long ll;

int Vert, Edge, Mec, Mec_con, Star, Star_con;
vector<pair<int, ll>> adj[MAX_VERT]; // {to,weight}
vector<ll> star_dis(MAX_VERT, INF), mec_dis(MAX_VERT,INF);
bool is_Mec[MAX_VERT], is_Star[MAX_VERT];
priority_queue < pair <ll, int>> mec_pq, star_pq;

//Function For Debug()
void show_dis();



void Input();

void Dijkstra(vector <ll>& dis, priority_queue <pair<ll,int>>& pq)
{
	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (weight > dis[from]) continue;

		for (auto& ele : adj[from])
		{
			int to = ele.first;
			ll cost = ele.second;

			if (dis[to] > dis[from] + cost)
			{
				dis[to] = dis[from] + cost;
				pq.push({ -dis[to],to });
			}
		}
	}
}

ll getResult()
{
	ll res = INF*2;

	for (int i = 1; i <= Vert; i++)
	{
		if (!star_dis[i] || !mec_dis[i]) continue; // 집이 아닌 경우

		else if (star_dis[i] > Star_con) continue;

		else if (mec_dis[i] > Mec_con) continue;

		res = min(res, mec_dis[i] + star_dis[i]);
	}

	return res;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Dijkstra(mec_dis, mec_pq);
	Dijkstra(star_dis, star_pq);
	//show_dis();
	ll res = getResult();

	if (res == INF * 2) res = -1;
	cout << res;


	return 0;
}


void Input()
{
	int from, to, weight, input;
	cin >> Vert >> Edge;

	for (int i = 0; i < Edge; i++)
	{
		cin >> from >> to >> weight;
		adj[from].push_back({ to,weight });
		adj[to].push_back({ from,weight });
	}

	cin >> Mec >> Mec_con;
	for (int i = 0; i < Mec; i++)
	{
		cin >> input; is_Mec[input] = true;
		mec_pq.push({ 0,input });
		mec_dis[input] = 0;
	}
	cin >> Star >> Star_con;
	for (int i = 0; i < Star; i++)
	{
		cin >> input; is_Star[input] = true;
		star_pq.push({ 0,input });
		star_dis[input] = 0;
	}

}

void show_dis()
{
	cout << "This is star" << endl;
	for (int i = 1; i <= Vert; i++)
		cout << star_dis[i] << " ";
	cout << endl;
	cout << "This is Mec" << endl;
	for (int i = 1; i <= Vert; i++)
		cout << mec_dis[i] << " ";
	cout << endl;
}