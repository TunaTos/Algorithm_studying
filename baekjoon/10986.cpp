#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N, M;
vector<ull> my_vec;
vector<ull> fuck;
ull zero_count{0};


void input() noexcept
{
	ull tmp{0};
	cin >> N >> M;
	my_vec.emplace_back(ull{0});
	fuck.assign(N+1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		my_vec.emplace_back(tmp);
		my_vec[i] = (my_vec[i-1] % M + my_vec[i] % M) % M;
		fuck[my_vec[i]]++;
	}
	// for (int i = 0; i < N-1; i++)
	// {
	// 	cout << fuck[i] << " ";
	// }cout << endl;
	// for(auto&ele: my_vec)
	// 	cout << ele << ' ';
	// cout << endl;

	// for (int i = 0; i < N; i++)
	// {
	// 	cout << fuck[i] << " ";
	// }cout << endl;
	
	for (int i = 0; i < N; i++)
	{
		if (i ==0)
		{
			zero_count += fuck[i];
			zero_count += fuck[i] * (fuck[i]-1) / 2;
		}
		else
		{
			if (fuck[i] < 2)
				continue;
			else
				zero_count += fuck[i] * (fuck[i]-1) / 2;
		}
	}
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	cout << zero_count;

	return (0);
}