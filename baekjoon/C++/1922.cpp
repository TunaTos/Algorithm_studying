#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_VERT 1001
#define MAX_EDGES 100001

using namespace std;

class Edge {
public:
    int from, to, w;
    
    Edge(int from, int to, int weight) : from(from), to(to), w(weight) {}

    bool operator<(const Edge& other) const {
        return this->w < other.w;
    }
};

int V, E;
int parents[MAX_VERT];
int weight[MAX_VERT];
vector<Edge> edge;

void Init() {
    fill(parents, parents + MAX_VERT, -1);
    fill(weight, weight + MAX_VERT, 1);
}

int Find(int a) {
    if (parents[a] == -1) return a;
    else return parents[a] = Find(parents[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (weight[a] < weight[b]) {
        parents[a] = b;
        weight[b] += weight[a];
    } else {
        parents[b] = a;
        weight[a] += weight[b];
    }
}

void Input() {
    cin >> V >> E;
    int a, b, c;

    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge.emplace_back(a, b, c);
    }
    sort(edge.begin(), edge.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Init();
    Input();

    int answer = 0;

    for (int i = 0; i < E; i++) {
        int from = edge[i].from;
        int to = edge[i].to;
        int w = edge[i].w;

        if (Find(from) != Find(to)) {
            Union(from, to);
            answer += w;
        }
    }

    cout << answer << endl;

    return 0;
}