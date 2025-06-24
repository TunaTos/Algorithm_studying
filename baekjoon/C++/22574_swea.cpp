#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int Tcase, N, P;
long sum;

void inputAndInit()
{
	sum = 0;
	cin >> N >> P;
}

void solve()
{
	inputAndInit();
	for (int i = 1; i <= N; i++)
	{
		if (sum + i < P) // 폭탄의 범위 안에 없는 경우
			sum += i;
		else if (sum + i == P)
			sum += (i-1);	
		else
			sum += i;
	}
	cout << sum << endl;
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.txt","r",stdin);
	// freopen("output.txt", "w", stdout);
	cin >> Tcase;
	for (int i = 0; i < Tcase; i++)
	{
		solve();
	}
	
	return (0);
}