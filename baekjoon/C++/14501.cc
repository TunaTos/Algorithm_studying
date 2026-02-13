#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int N, R;
vector<ll> times, prices;
vector<bool> visited;
vector<int> selected;
ll res;

void input() {
	cin >> N;
	times.assign(N+1, 0); prices.assign(N+1, 0), visited.assign(N+1, false);

	for (int i =1; i <= N; ++i) {
		cin >> times[i] >> prices[i];
	}
}

void dfs(int dpt, int idx) {

	if (dpt == R+1) {
		ll sum = 0;
		


		for (int i = 0; i < selected.size(); ++i) {
			if (i == selected.size()-1) {
					if (selected[i] + times[selected[i]] - 1 > N) 
						return ;
			} 
			else {
				if (selected[i] + times[selected[i]] - 1 >= selected[i+1]) 
					return ;
			}
		}

		for (int i = 0; i < selected.size(); ++i) {
			sum += prices[selected[i]];
		}
		res = max(sum, res);
		return ;
	}

	for (int i = idx; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			selected.push_back(i);

			dfs(dpt+1, i +1);

			selected.pop_back();
			visited[i] = false;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();

	for (int i = 1; i <= N; ++i) {
		R = i;
		dfs(1,1);
	}

	cout << res << endl;

	return (0);
}