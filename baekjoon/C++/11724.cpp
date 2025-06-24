#include <iostream>
#include <vector>
#include <queue>
#define MAX_VERT 1001
#define endl '\n'
using namespace std;

int V, E;
vector<int> adj[MAX_VERT];
vector<bool> visited(MAX_VERT, false);

void input()
{   
    cin >> V >> E;
    int from, to;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

void bfs(int& node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int from = q.front();
        q.pop();

        for(const auto& next: adj[from])
        {
            if (visited[next]) continue;

            q.push(next);
            visited[next] = true;
        }
    }
}



void solve()
{
    int res = 0;
    input();
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            ++res;
            bfs(i);
        }
    }
    
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
            +res;
    }
    cout << res;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return (0);
}