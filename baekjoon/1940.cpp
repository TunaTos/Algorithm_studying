#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int N, res;
vector<ull> my_vec;
ull M;

void show_vec() noexcept
{
	for(const auto&ele: my_vec)
		cout << ele << ' ';
	cout << endl;
}


void input() noexcept
{
	cin >> N >> M;
	my_vec.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> my_vec[i];
}

void get_result() noexcept
{
	for (int i = 0; i < my_vec.size() - 1; i++)
	{
		ull stand = my_vec[i];
		ull target = M - stand;

		if (std::binary_search(my_vec.begin() + i + 1, my_vec.end(), target))
			++res;
	}
}

void solve() noexcept
{
	input();
	sort(my_vec.begin(), my_vec.end());
	// show_vec();	
	get_result();
	cout << res;
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}