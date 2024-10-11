#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 201;

int parent[MAX_N];

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;
    parent[u] = v;
    Find(u);
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= MAX_N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) Union(i, j);
        }
    }

    int past, here;
    bool canTrip = true;
    cin >> past;

    for (int i = 1; i < M; i++) {
        cin >> here;
        if (!canTrip) continue;
        if (Find(past) != Find(here)) canTrip = false;
        past = here;
    }

    if (canTrip) cout << "YES";
    else cout << "NO";

    return 0;
}