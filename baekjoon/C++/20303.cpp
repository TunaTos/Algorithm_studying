#include <bits/stdc++.h>
#define MAX_N 30001
#define MAX_M 100001
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N, M, K, Len;
vector<ull> weight(MAX_N,0), parents(MAX_N,0), son(MAX_N,1);
vector<ull> k_weight, k_price;
ull dp[MAX_N];

void showVector(vector<ull>& v)
{
	for (int i = 1; i <= min((int)v.size(),N); i++)
	{
		cout << v[i] << " ";
	}cout << endl;
}

void setParents() noexcept
{
	for (int i = 1; i <= N; i++)
		parents[i] = i;
}

int Find(const int& a) noexcept
{
	if (parents[a] == a) return (a);
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b) noexcept
{
	a = Find(a); b = Find(b);
	
	if (a ==b) 
		return;
	else if (weight[a] <= weight[b])
	{
		parents[a] = b;
		weight[b] += weight[a];
		son[b] += son[a];
	}
	else
	{
		parents[b] = a;
		weight[a] += weight[b];
		son[a] += son[b];
	}
}


void input() noexcept
{
	int a, b;
	cin >> N >> M >> K;
	setParents();
	for (int i = 1; i <= N; i++)
		cin >> weight[i];
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Union(a,b);
	}
}

void setLen() noexcept
{
	k_weight.push_back(0); k_price.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		if (parents[i] == i)
		{
			++Len; 
			k_weight.push_back(son[i]);
			k_price.push_back(weight[i]);
		}
	}
}

void getDp() noexcept
{
	for (int i = 1; i <= Len; i++)
	{
		for (int j = K; j >= k_weight[i]; j--)
			dp[j] = max(dp[j], dp[j - k_weight[i]] + k_price[i]);
	}
	cout << dp[K - 1];
}


void solve() noexcept
{
	input();
	setLen();
	getDp();
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();
	return (0);
}