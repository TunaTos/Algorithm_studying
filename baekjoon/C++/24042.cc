#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define endl '\n'
using namespace std;

int N, M;
vector<vector<pair<int,int>>> adj;   // {To, phase(i)}
vector<long long> Distance;

void Input() {
    cin >> N >> M;
    adj.assign(N + 1, {});
    Distance.assign(N + 1, LLONG_MAX);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
}

void Dijkstra() {
    priority_queue<pair<long long,int>> pq; // {-cost, node}
    pq.push({0, 1});
    Distance[1] = 0;

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (Distance[node] != cost) continue;

        if (node == N) return;

        for (auto &e : adj[node]) {
            int nextNode = e.first;
            int phase = e.second;

            long long cur = cost % M;
            long long wait = ( (phase - cur) % M + M ) % M;

            long long nextCost = cost + wait + 1;

            if (Distance[nextNode] > nextCost) {
                Distance[nextNode] = nextCost;
                pq.push({-nextCost, nextNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    Dijkstra();
    cout << Distance[N] << endl;
    return 0;
}
