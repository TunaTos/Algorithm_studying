#include <bits/stdc++.h>
using namespace std;

int N, R;
vector<int> number;
vector<int> selected;

void input()
{
	cin >> N >> R;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num; 
		number.emplace_back(num);
	}
	sort(number.begin(), number.end());

}

void dfs(int idx, int dpt)
{
	if (selected.size() == R)
	{
		for (const auto& ele: selected)
			cout << ele << " ";
		cout << endl;

		return ;
	}

	int prev = -1;
	for (int i = idx; i < N; i++)
	{
		if (prev == number[i])
			continue;
		
		selected.push_back(number[i]);
		prev = number[i];
		dfs(i+1, dpt+1);
		selected.pop_back();
	}
}


void solve()
{
	input();
	dfs(0,0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}