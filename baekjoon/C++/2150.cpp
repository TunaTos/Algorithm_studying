#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define endl '\n'
using namespace std;

int V, E, sccNumber;

class Graph
{
public:
    vector<vector<int>> adj;
    vector<vector<int>> revAdj;

    Graph(const int& v_input) :
        adj(v_input + 1), revAdj(v_input + 1) {};

    void addEdge(const int& from, const int& to)
    {
        adj[from].push_back(to);
        revAdj[to].push_back(from);
    }

    void dfsInAdj(const int& node, vector<bool>& visited, stack<int>& Stack)
    {
        visited[node] = true;

        for (auto& next : adj[node])
            if (!visited[next])
                dfsInAdj(next, visited, Stack);

        Stack.push(node); // 종료 시간 순으로 스택에 푸시
    }

    void dfsInRev(const int& node, vector<bool>& visited, vector<int>& component)
    {
        visited[node] = true;
        component.push_back(node);
        for (auto& next : revAdj[node])
            if (!visited[next])
                dfsInRev(next, visited, component);
    }

    void findSCC()
    {
        stack<int> Stack;
        vector<bool> visited(V + 1, false);

        // 첫 번째 DFS: 원본 그래프에서 탐색
        for (int i = 1; i <= V; ++i)
            if (!visited[i])
                dfsInAdj(i, visited, Stack);

        
        fill(visited.begin(), visited.end(), false);

        vector<vector<int>> sccs;

        
        while (!Stack.empty())
        {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v])
            {
                sccNumber++;
                vector<int> component;
                dfsInRev(v, visited, component);
                sort(component.begin(), component.end());
                sccs.push_back(component);
            }
        }


        sort(sccs.begin(), sccs.end());


        cout << sccNumber << endl;
        for (const auto& scc : sccs)
        {
            for (const int& node : scc)
                cout << node << " ";
            cout << -1 << endl;
        }
    }
};

void initObject(Graph& g)
{
    int from, to;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to;
        g.addEdge(from, to);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    Graph g(V);
    initObject(g);
    g.findSCC();

    return 0;
}
