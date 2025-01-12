#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

int V, E, maxNode{-1};
vector<int> adj[10001];
vector<int> nodeNum(10001, 0);

template<typename Container>
void showContainer(const Container& c)
{
    for (int i = 1; i <= V; i++)
    {
        cout << c[i] << ' ';
    }cout << endl;
}

void input()
{
    cin >> V >> E;
    int start, to;
    
    for (int i = 0; i < E; i++)
    {
        cin >> start >> to;
        adj[to].emplace_back(start);
    }
}

void dfs(const int& node, vector<bool>& visited, int& cnt)
{
    visited[node] = true;
    
    for (const auto& next: adj[node])
    {
        if (!visited[next])
            dfs(next, visited, ++cnt);
    }
}
void setNodeNum()
{
    for (int i = 1; i <= V; i++)
    {
        vector<bool> visited(V+1, false);
        dfs(i, visited, nodeNum[i]);
        maxNode = max(nodeNum[i], maxNode);
    }    
}

void printResult()
{
    for (int i = 1; i <= V; i++)
    {
        if (nodeNum[i] == maxNode)
            cout << i << ' ';
    }cout << endl;
}


void solve()
{
    input();
    setNodeNum();
    // showContainer(nodeNum);
    printResult();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}