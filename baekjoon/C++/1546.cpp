#include <bits/stdc++.h>
using namespace std;

int N;
double sum, max_val;

void input()
{
	double input = 0.0 ;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		max_val = max(max_val, input);
		sum += input;
	}
}



void solve()
{
	input();
	cout << sum / N / max_val * 100;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	solve();
	return (0);
}