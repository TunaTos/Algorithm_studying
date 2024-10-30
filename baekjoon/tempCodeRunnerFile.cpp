#include <bits/stdc++.h>
#define endl '\n'
#define MAX_VERT 501
using namespace std;

int Tcase, V, E;
vector<int> parents(MAX_VERT), weight(MAX_VERT,1), isCycle(MAX_VERT,false);

void showVector(const auto& v)
{
	for (int i = 1; i <= V; i++)
		cout << v[i] << " ";
}

int Find(const int& a)
{
	if(parents[a] == a)
		return (a);
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	if(a==b)
		return;
	else if (weight[a] <= weight[b])
	{
		parents[a] = b;
		weight[b] += weight[a];
	}
	else
	{
		parents[b] = a;
		weight[a] += weight[b];
	}
}

void resetParentsAndWeight()
{
	for (int i = 1; i <= V; i++)
	{
		parents[i] = i;
		weight[i] = 1;
		isCycle[i] = false;
	}
}

bool isValid()
{
	cin >> V >> E;
	if (V == 0 && E == 0)
		return false;
	return true;
}

void input()
{
	int a, b;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b;
		a = Find(a); b = Find(b);
		if (a==b)
		{
			isCycle[a] = isCycle[b] = true;
			continue;
		}
		else
			Union(a,b);
	}

}

void getResult(const int& cnt)
{
	//showVector(parents);
	int res = 0;
	for (int i = 1; i <= V; i++)
	{
		if (parents[i]==i && !isCycle[i])
			++res;
	}
	if(res==0)
		cout << "Case " << cnt  << ": No trees." << endl;
	else if(res==1)
		cout << "Case " << cnt  << ": There is one tree." << endl;
	else
		cout << "Case " << cnt  << ": A forest of " << res << " trees." << endl;
}

void solve()
{
	int cnt = 0;
	while(isValid())
	{
		++cnt;
		resetParentsAndWeight();
		input();
		getResult(cnt);
	}	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}