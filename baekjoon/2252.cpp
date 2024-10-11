#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_STU 32001
using namespace std;

int Tcase, Len, input1, input2;
vector<int> adj[MAX_STU];
vector<int> res;
int indegree[MAX_STU];
queue<int> Q;

void addEdge()
{
	adj[input1].push_back(input2);
	indegree[input2]++;
}


void Solve()
{
	for (int i = 1; i <= Len; i++)
	{
		if (indegree[i] == 0)
			Q.push(i);
	}

	
	while (!Q.empty())
	{
		int here = Q.front();
		res.push_back(here);
		Q.pop();

		for (int i = 0; i < adj[here].size(); i++)
		{
			int temp = adj[here][i];
			indegree[temp]--;
			if (indegree[temp] == 0)
				Q.push(temp);
		}
	}



	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}

}



void getAdj()
{
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		
		cout << "\n";
	}
}

void getIndegree()
{
	for (int i = 1; i <= Len; i++)
		cout << indegree[i] << " ";

	cout << endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Len >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		cin >> input1 >> input2;
		addEdge();
	}

	//getAdj();
	//getIndegree();
	Solve();



	return 0;
}



