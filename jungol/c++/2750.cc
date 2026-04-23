#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll K, N, M, res;

void input() {
    cin >> K >> N >> M;
}

void solve() {
    if (K * N > M) {
        res = K * N - M;
    } else {
        res = 0;
    }

    cout << res;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input(); 
    solve();
    return (0);
}