#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#define MAX_VERT 100001
using namespace std;

vector<int> adj[MAX_VERT],revAdj[MAX_VERT], sccNum(MAX_VERT,0), indegree;
vector<bool> visited(MAX_VERT,false);
stack<int> Stack;
int V, E, scc;

void input()
{
    cin >> V >> E;
    int from, to;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to;
        adj[++from].push_back(++to);
        revAdj[to].push_back(from);
    }
}

void dfsINAdj(const int& node)
{
    visited[node] = true;

    for(const auto next: adj[node])
    {
        if(!visited[next])
            dfsINAdj(next);
    }
    Stack.push(node);
}

void dfsInRev(const int& node, const int& s)
{
    visited[node] = true;
    sccNum[node] = s;

    for(const auto& next: revAdj[node])
        if(!visited[next])
            dfsInRev(next, s);

}

void getScc()
{
    for (int i = 1; i <= V; i++)
        if(!visited[i])
            dfsINAdj(i);

    for (int i = 1; i <= V; i++)
        visited[i] = false;
    
    

    while(!Stack.empty())
    {
        auto start = Stack.top();
        Stack.pop();
        if(!visited[start])
            dfsInRev(start,++scc);
    }
}

int getIndex(const int& node)
{
    return sccNum[node];
}

void solve()
{
    input();
    getScc();
    indegree.resize(V+1,0);
    for (int i = 1; i <= V; i++)
        visited[i] = false;
    
    for (int i = 1; i <= V; i++)
    {
        for(const auto& next: adj[i])
        {
            if(getIndex(next) != getIndex(i))
                indegree[getIndex(next)]++;
        }
    }
    
    int res = 0;
    for (int i = 1; i <= scc; i++)
    {
        if(indegree[i]==0)
            ++res;
    }
    cout << res;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}