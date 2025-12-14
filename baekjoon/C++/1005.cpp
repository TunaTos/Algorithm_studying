#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int Tcase, Target, Nodes, Edges;
int Time[1001], visited[1001], directed[1001], dp[1001];
vector<int> adj[1001];

void Debug();

void Init()
{
	int start, end;
	cin >> Nodes >> Edges;
	for (int i = 1; i <= Nodes; ++i)
	{
		cin >> Time[i];
		dp[i] = Time[i];
	}

	for (int i = 0; i < Edges; i++)
	{
		cin >> start >> end;
		adj[start].push_back(end);
		directed[end]++;
	}
	cin >> Target;

}

int Solve()
{
	queue<int> q;

	for (int i = 1; i <= Nodes; i++)
	{
		if (directed[i] == 0)
		{
			q.push(i); visited[i] = true;
		}
	}

	while (!q.empty())
	{
		int stand = q.front();
		q.pop();
		//cout << stand << " ";

		for (auto& ele : adj[stand])
		{
			if (directed[ele] == 0)
				continue;
			else
			{	
				dp[ele] = max(dp[ele], Time[ele] + dp[stand]);	
				directed[ele]--;
				if (directed[ele] == 0)
				{
					q.push(ele);
					visited[ele] = true;
				}
			}
		}
	}
	return dp[Target];
}

void Reset()
{
	for (int i = 1; i <= Nodes; i++)
	{
		Time[i] = 0; visited[i] = false; dp[i] = 0;
		adj[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Tcase;
	for (int i = 0; i < Tcase; i++)
	{
		Init();
		cout <<  Solve() << endl;
		Reset();

		//Debug();
	}





	return 0;
}

void Debug()
{
	cout << "This is Time : ";
	for (int i = 1; i <= Nodes; i++)
		cout << Time[i] << " ";
	cout << endl;

	cout << "This is visited : ";
	for (int i = 1; i <= Nodes; i++)
		cout << visited[i] << " ";
	cout << endl;

	cout << "This is directed : ";
	for (int i = 1; i <= Nodes; i++)
		cout << directed[i] << " ";
	cout << endl;

	cout << "This is dp : ";
	for (int i = 1; i <= Nodes; i++)
		cout << dp[i] << " ";
	cout << endl;
	cout << "This is adj : " << endl;
	
	for (int i = 1; i <= Nodes; i++)
	{
		cout <<  i << " ";
		for (auto& ele : adj[i])
			cout << ele << " ";
		cout << endl;
	}
	cout << "This is Target : " << Target << endl;

}