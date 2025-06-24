#define _CRT_SECURE_NO_WARNINIGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[32001];
int Tcase, Edges;
bool visited[32001];
int directed[32001];
vector<int> res;

struct compare {
	bool operator() (pair<int,int> p1, pair<int,int> p2)
	{
		if (p1.second == p2.second)
			return p1.first > p2.first;
		else
			return p1.second < p2.second;

	}
};

priority_queue<pair<int, int>,vector<pair<int,int>>,compare> q;


void Debug()
{
	for (int i = 1; i <= Edges; i++)
	{
		cout << i << " ";
		for (auto& ele : adj[i])
			cout << ele << " ";
		cout << endl;
	}


	cout << "This is directed" << endl;
	for (int i = 1; i <= Edges; i++)
	{
		cout << directed[i] << " ";
	}
	cout << endl;

}

void Init()
{
	cin >> Edges >> Tcase;
	int start, end;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> start >> end;
		adj[start].push_back(end);
		directed[end]++;
	}
}

void Solve() {
	
	for (int i = 1; i <= Edges; i++)
	{
		if (directed[i] == 0)
		{
			pair<int, int> p1 = make_pair(i, 0);
			q.push(p1);
			visited[i] = true;
		}
	}

	while (!q.empty())
	{
		int dpt = 1;
		int stand = q.top().first;
		q.pop();
		res.push_back(stand);

		for (auto& ele : adj[stand])
		{
			directed[ele]--;
			if (directed[ele] == 0)
			{
				pair<int, int> p1 = make_pair(ele, dpt);
				q.push(p1);
				visited[ele] = true;
			}
		}

		
		
		dpt++;
	}



}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	//Debug();
	Solve();
	for (auto& ele : res)
		cout << ele << " ";




	return 0;
}