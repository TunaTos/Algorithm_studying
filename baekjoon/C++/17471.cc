/**
 * 1번부터 N번까지 정해져있음
 * (1 <= N <= 10)
 * 
 * 조건)
 * 모든 선거구는 두 집합 중 하나에 포함
 * 집합의 크기는 x >= 1
 * 집합은 연결되어야
 * 
 * 인구수의 최솟값을 출력하라
 * 없으면 -1
 * 
 * 인접한 구역이 없을 수도 있음!
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <math.h>
#define endl '\n'
using namespace std;
int n, sel_sum, non_sel_sum, res = INT_MAX;
vector<int> p_count; // 인구수
vector<vector<int>> adj;
vector<bool> visited, selected;


void input() noexcept {
    cin >> n;

    // init container
    p_count.assign(n+1, 0);
    visited.assign(n+1, false); selected.assign(n + 1, false);
    adj.assign(n+1, vector<int>());
    int m, node;

    for (int i = 1; i <= n; ++i) {
        cin >> p_count[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> m;
    
        for (int j = 0; j < m; ++j) {
            cin >> node;
            adj[i].push_back(node);
            adj[node].push_back(i);
        }    
    }
}
void solve(bool flag, int node) {
    // flag -> selected의 상태
    // node -> node

    visited[node] = true;
    if (flag) {
        sel_sum += p_count[node];
    } else {
        non_sel_sum += p_count[node];
    }
    
    for (int n_node: adj[node]) 
        if (!visited[n_node] && flag == selected[n_node]) 
            solve(flag, n_node);
}



void permutation(int r) {

    vector<bool> tmp(n, false);
    fill(tmp.begin(), tmp.begin() + r, true);

    do
    {
        for (int i = 0; i < n; ++i) 
            if (tmp[i])
                selected[i+1] = true;
        


        // solve();
        // selected된 것을 r
        int s_count = 0;
        int ns_count = 0;

        for (int i = 1; i <= n; ++i) {
            if (selected[i] && !visited[i]) {
                solve(selected[i], i);
                ++s_count;
            } else if (!selected[i] && !visited[i]) {
                solve(selected[i], i);
                ++ns_count;
            }
        }

        if (s_count == 1 && ns_count == 1) {
            res = min(res, abs(sel_sum - non_sel_sum));
        }

        // init
        fill(selected.begin(), selected.end(), false);
        fill(visited.begin(), visited.end(), false);
        s_count = 0; ns_count = 0;
        sel_sum = 0;    
        non_sel_sum = 0;
    } while (prev_permutation(tmp.begin(), tmp.end()));
}




int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    input();

    for (int i = 1; i <= n / 2; ++i) {
        permutation(i);
    }

    res == INT_MAX ? res = -1 : res = res;

    cout << res;
    return (0);
}