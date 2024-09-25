#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VERT 301
#define endl '\n'
using namespace std;
class Edge
{
public:
    int a, b;
    long long w;

    Edge(const int& a_input, const int& b_input, const int& w_input) :
        a(a_input), b(b_input), w(w_input) {};

    bool operator < (const Edge& other) const
    {
        return this->w > other.w;
    }
    friend ostream& operator << (ostream& out, const Edge& E)
    {
        out << E.a << " " << E.b << " " << E.w << endl;
        return out;
    }
};

int V;
priority_queue<Edge, vector<Edge>> pq;
vector<int> cost(MAX_VERT, 0);
vector<bool> visited(MAX_VERT, false);
long long matrix[MAX_VERT][MAX_VERT];

void input()
{
    cin >> V;
    for (int i = 1; i <= V; ++i)
    {
        cin >> cost[i];
        pq.emplace(Edge{ i,i,cost[i] });
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
            cin >> matrix[i][j];
    }
}


void solve()
{
    int cnt = 0;
    long long res = 0;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        if (node.a == node.b) // 땅을 파는 경우
        {
            if (visited[node.a]) continue; // 방문한 경우 지나간다.
            visited[node.a] = true; // 방문처리

            ++cnt;
            res += node.w;

            for (int i = 1; i <= V; i++)
            {
                if (i == node.a) continue;
                pq.push(Edge(node.a, i, matrix[node.a][i]));
            }
        }

        else
        {
            if (visited[node.b] == true) continue;
            visited[node.b] = true;

            ++cnt;
            res += node.w;

            for (int i = 1; i <= V; i++)
            {
                if (i == node.b) continue;
                pq.push(Edge(node.b, i, matrix[node.b][i]));
            }
        }

        if (cnt == V)
        {
            cout << res;
            return;
        }
    }


}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return (0);
}