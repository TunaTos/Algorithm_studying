#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	vector<int> vec;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.emplace_back(input);
	}

	sort(vec.begin(), vec.end());
	for (int i = 1; i < N; i++)
		vec[i] += vec[i-1];
	
	cout << std::accumulate(vec.begin(), vec.end(), int{0});
	

	return (0);
}