#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
vector<pair<int, int>> A;

void solve() noexcept
{
    cin >> N;
    A.reserve(N);

    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        A.emplace_back(tmp, i);
    }

    sort(A.begin(), A.end());

    int max_move = 0;

    for (int i = 0; i < N; i++) {
        max_move = max(max_move, A[i].second - (i + 1));
    }

    cout << max_move + 1 << '\n';
}

int main() noexcept 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
