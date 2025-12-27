#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

const ull INF = 987654321;

vector<int> x_pos, y_pos;
int v, k;

void input() noexcept {
    cin >> v >> k;

    x_pos.assign(v + 1, 0);
    y_pos.assign(v + 1, 0);

    for (int i = 1; i <= v; i++)
        cin >> x_pos[i] >> y_pos[i];
}

auto dist = [](int a, int b) -> ull {
    return abs(x_pos[a] - x_pos[b]) + abs(y_pos[a] - y_pos[b]);
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    vector<vector<ull>> dp(v + 1, vector<ull>(k + 1, INF));
    dp[1][0] = 0;

    for (int i = 2; i <= v; ++i) {
        for (int j = 1; j < i; ++j) {
            int skip = (i - j - 1);
            for (int z = skip; z <= k; ++z) {
                if (dp[j][z - skip] == INF)
                    continue;
                dp[i][z] = min(dp[i][z],
                               dp[j][z - skip] + dist(j, i));
            }
        }
    }

    ull res = INF;
    for (int i = 0; i <= k; ++i)
        res = min(res, dp[v][i]);

    cout << res << endl;
    return 0;
}
