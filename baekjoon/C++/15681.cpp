#include <bits/stdc++.h>
#define MAX_VERT 100001
#define endl '\n'
using namespace std;

int V, R, Q; // Vert, Root, Query
vector<int> weight(MAX_VERT,0), adj[MAX_VERT];
vector<bool> visited(MAX_VERT,false);

void showWeight()
{
    for (int i = 1; i <= V; i++)
    {
        cout << weight[i] << " ";    
    }
    cout << endl;
}

void showAdj()
{
    for (int i = 1; i <= V; i++)
    {
        cout << "I am i : " << i << " / ";
        for(const auto& ele: adj[i])
            cout << ele << ' ';
        cout << endl;
    }
}


void input()
{
    cin >> V >> R >> Q;
    int from, to;
    for (int i = 0; i < V-1; i++)
    {
        cin  >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

int DFS(int node)
{       
    if(visited[node]) return weight[node];

    visited[node] = true;
    weight[node] = 1;

    for(const auto next: adj[node])
        if(!visited[next])
            weight[node] += DFS(next);

    return weight[node];
}


void solve()
{
    int node;
    for (int i = 0; i < Q; i++)
    {
        cin >> node;
        cout << weight[node] << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    //showAdj();
    DFS(R);
    //showWeight();
    solve();
    
    return (0);
}