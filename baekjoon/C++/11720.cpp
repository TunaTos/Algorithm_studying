#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void input(int&n, string& str)
{
	cin >> n >> str;
}

void solve()
{
	int n; string str;

	input(n, str);
	ll res = accumulate(str.begin(), str.end(), 0, [](int acc, char c) {
		return acc + (c - '0');
	});
	cout << res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}