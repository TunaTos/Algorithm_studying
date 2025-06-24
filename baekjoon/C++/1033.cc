#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;



int V;
vector<int> dis;
vector<vector<int>> adj;

int getGcd(int num1, int num2)
{
    while (num2 != 0)
    {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    return num1;
}


void input()
{
    cin >> V;
    dis.assign(V+1, 1);
    adj.assign(V+1, vector<int>());
}

void dfs(int node, vector<bool>& visited, const int& gcd)
{
    visited[node] = true;
    dis[node] *= gcd;

    for(const auto& next: adj[node])
    {
        if (!visited[next])
            dfs(next, visited, gcd);
    }
}

void dfs2(int node, vector<bool>& visited, const int& gcd)
{
    visited[node] = true;
    dis[node] /= gcd;

    for(const auto& next: adj[node])
    {
        if (!visited[next])
            dfs2(next, visited, gcd);
    }
}

void runCase()
{
    vector<bool> visited(V+1, false);
    int node1, node2, num1, num2;  
    cin >> node1 >> node2 >> num1 >> num2;

    int gcd = getGcd(num1, num2);
    
    dfs(node1, visited, num1);
    fill(visited.begin(), visited.end(), false);
    dfs(node2, visited, num2);
    adj[node1].emplace_back(node2);
    adj[node2].emplace_back(node1);
    fill(visited.begin(), visited.end(), false);
    dfs2(node1, visited, gcd);
    
}
void solve()
{
    input();
    for (int i = 0; i < V - 1; i++)
        runCase();
    
    for (int i = 0; i < V; i++)
    {
        cout << dis[i] << ' ';
    }
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}