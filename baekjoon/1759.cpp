#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int L, C;
vector<char> vec;

template<typename T>
void show_vec(const T& t)
{
	for ( auto i = vec.begin() + 1; i != vec.end(); ++i)
		cout << *i << ' ';
	
	
	cout << endl;
}

void inputAndSort()
{
	cin >> L >> C;
	
	vec.resize(C+1, '0');
	for (int i = 1; i <= C; i++)
		cin >> vec[i];
	sort(vec.begin() + 1, vec.end());
}

void solve()
{
	inputAndSort();
	show_vec(vec);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();


	return (0);
}