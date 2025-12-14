#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dijkstra(int n, const vector<int>& stores) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> min_dis(n + 1, INT_MAX);
    for (int store : stores) {
        pq.push({ 0, store });
        min_dis[store] = 0;
    }

    while (!pq.empty()) {
        int cur_dis = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (min_dis[cur_node] < cur_dis)
            continue;

        for (const auto& edge : graph[cur_node]) {
            int next_node = edge.first;
            int next_dis = edge.second;
            if (min_dis[next_node] > next_dis + cur_dis) {
                min_dis[next_node] = next_dis + cur_dis;
                pq.push({ next_dis + cur_dis, next_node });
            }
        }
    }

    return min_dis;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int p, q;
    cin >> p >> q;
    vector<int> homes(p);
    for (int& h : homes)
        cin >> h;
    sort(homes.begin(), homes.end());

    vector<int> stores(q);
    for (int& s : stores)
        cin >> s;

    int ans = INT_MAX;
    vector<int> t = dijkstra(n, stores);
    int result;
    for (int i : homes) {
        if (ans > t[i]) {
            ans = t[i];
            result = i;
        }
    }

    cout << result << endl;

    return 0;
}
