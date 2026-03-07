/**
 * V, E (10 ^ 5)
 * C (10 ^ 9)
 * 
 * 중량 제한이 C이다
 * 같은 두 섬 사이에 여러 다리가 있을 수도 있다.
 * 다리는 양방향이다
 * 
 * O(10 ^ 6)
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 1000000000
using namespace std;
using ull = unsigned long long;
using piu = pair<int, ull>;


int V, E, S, En;
vector<vector<piu>> adj; // {node, limit}
vector<bool> visited;


void input() noexcept {
    cin >> V >> E;

    // init container
    adj.assign(V+1, vector<piu>());
    visited.assign(V+1, false);

    int from, to;
    ull limit;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> limit;
        
        adj[from].push_back(make_pair(to, limit));
        adj[to].push_back(make_pair(from, limit));
    }
    
    cin >> S >> En;
}

void dfs(int node, long lmt) {
    
    visited[node] = true;

    for (piu p: adj[node]) {
        int nextNode = p.first;
        long l = p.second;

        if (!visited[nextNode] && lmt <= l) {
            visited[nextNode] = true;
            
            dfs(nextNode, lmt);
        }
    }
}

ull solve() {
    ull left = 1, right = INF;

    while (left <= right) {
        ull mid = (left + right) / 2;
        visited.assign(V+1, false);

        dfs(S, mid);
        
        if (visited[En]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // cout << left << " " << right << endl;
    return right;    
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    cout << solve();

    return (0);
}