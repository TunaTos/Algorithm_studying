#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>

#define endl '\n'
using namespace std;
using ll = long long;

int N, max_count;
vector<ll> nums;
ll res;
set<ll> my_set;

void input() noexcept {
    cin >> N;
    nums.assign(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        my_set.insert(nums[i]);
    }
    sort(nums.begin(), nums.end());
}

void solve() {
    for (const auto& s: my_set) 
    {
        ll dis = distance(lower_bound(nums.begin(), nums.end(), s), upper_bound(nums.begin(), nums.end(), s));
        if (dis > max_count) {
            max_count = dis;
            res = s;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    cout << res;
    return (0); 
}