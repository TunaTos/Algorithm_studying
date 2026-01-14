/**
 * N개의 지역이 있음
 * 
 * 횡단보도에 파란풀을 알고 있음
 * 
 * 주기는 M분이다. 1분마다 신호가 밖뀐다.
 * 
 * 1분동안 Ai와 Bi 지역의 횡단보도가 파란불이 들어온다.
 * 한 주기동안 같은 횡단보도에 파란불이 여러번 가능
 * 
 * 파란불이 오면 반대편으로 갈 수 있으며 1분 걸린다.
 * 건너는 도중에 빨간불이 되면 안된다.
 * 
 * 0분에 시작해서 1번지역에서 N번 지역까지 가는 최소 시간은? 
 * 
 * 
 * 그래프 탐색을 해서 1에서 4로 가는 경로들을 모두 구한다?
 * 각각의 경로들이 주기에 얼마나 빨리 가는지를 구한다
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define endl '\n'
using namespace std;
using pii = pair<int,int>;
using ull = unsigned long long;


int N, M, idx;
vector<vector<int>> adj, paths;
vector<pii> signals;
vector<bool> visited;
vector<int> path;
ull r = LLONG_MAX;

void input()
{
    cin >> N >> M;
    int n1, n2;

    // init container
    adj.assign(N+1, vector<int>());
    visited.assign(N+1, false);

    for (int i = 0; i < M; ++i) {
        cin >> n1 >> n2;
        signals.push_back(make_pair(n1,n2));
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void dfs(int node) {
    visited[node] = true;
    path.push_back(node);
    if (node == N)
        paths.push_back(path);
    else {
        for (const auto& next: adj[node])
            if (!visited[next])
                dfs(next);
    }
    visited[node] = false;
    path.pop_back();
}

ull get_result(const vector<int>& vec)
{
    if (vec.size() <= 1) return 0;
    int edge = 0;           
    ull time = 0;

    while (edge < (int)vec.size() - 1) {
        const auto& s = signals[time % M];

        if ((s.first == vec[edge] && s.second == vec[edge + 1])
        ||
        (s.second == vec[edge] && s.first == vec[edge + 1])) {
            edge++; 
        }
        time++; 
    }

    return time;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    dfs(1);
    
    for (int i = 0; i < paths.size(); ++i) {
        r = min(r, get_result(paths[i]));
    }
    cout << r << endl;
    return (0);
}