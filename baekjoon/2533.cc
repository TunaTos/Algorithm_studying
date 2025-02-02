#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

/**
 * graoh는 트리이다
 * 사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 아니다
 * 아닌 사람들은 내 친구들이 모두 얼리 아답터일 떄 아이디어를 받아들인다.
 * 친구 관계가 있는 경우 필요한 "최소 얼리 어답터의 수"
 */

int V;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> dp; // 0 -> 얼리 아답터가 아닌 경우, 얼리 아답터인 경우

void input()
{
    cin >> V;
    int from, to;

    adj.resize(V+1, vector<int>());
    visited.resize(V+1, false);
    dp.resize(V+1, vector<int>(2, 0));

    for (int i = 0; i < V -1; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

void dfs(int node)
{
    visited[node] = true; // 방문처리
    dp[node][0] = 0; // 얼리 어답터가 아닌 경우
    dp[node][1] = 1; // 얼리 어답터가 맞는 경우

    for (const auto& next: adj[node])
    {
        if (visited[next])
            continue;
        dfs(next);
        
        dp[node][0] += dp[next][1];
        dp[node][1] += (min(dp[next][0], dp[next][1]));
    }
}

void solve()
{
    input();
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);

    // for (int i = 1; i <= V; i++)
    // {
    //     cout << dp[i][0] << " ";
    // }cout << endl;

    // for (int i = 1; i <= V; i++)
    // {
    //     cout << dp[i][1] << " ";
    // }
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return (0);
}