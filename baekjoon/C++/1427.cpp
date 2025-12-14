#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;
	sort(input.begin(), input.end(), greater<char>());
	cout << input;
	
	return (0);
}