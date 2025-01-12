#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define RED 1
#define BLUE 2
#define NOT_VISITED 0
using namespace std;

int Tcase, V, E;

class Graph
{
private:
    int V, E;
    vector<vector<int>> adj;
    vector<int> visited;
public:
    Graph() = default;
    Graph(const int& v_input, const int& e_input):
        V(v_input), E(e_input), adj(V+1, vector<int>()), visited(V+1, NOT_VISITED) 
        {
            int node1, node2;
        
            for (int i = 0; i < E; i++)
            {
                cin >> node1 >> node2;
                adj[node1].emplace_back(node2);
                adj[node2].emplace_back(node1);        
            }
        }
    
    
    void bfs(const int& node)
    {

        queue<int> q;
        q.push(node);
        visited[node] = RED;

        while (!q.empty())
        {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++)
            {
                int stand = q.front();
                q.pop();
                for (const auto& next: adj[stand])
                {
                    if (visited[next] == NOT_VISITED)
                    {
                        if (visited[stand] == RED)
                            visited[next] = BLUE;
                        else if (visited[stand] == BLUE)
                            visited[next] = RED;
                        q.push(next);
                    }                    
                }
            }
        }
    }
    void coloring()
    {
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == NOT_VISITED)
                bfs(i);
        }
    }  

    bool checkBipartite()
    {
        for (int i = 1; i <= V; i++)
        {
            int standColor = visited[i];
            for (const auto& next: adj[i])
            {
                if (standColor == visited[next])
                    return false;
            }
        }
        return true;
    }
    void showVisitied()
    {
        for (int i = 1; i <= V; i++)
        {
            cout << visited[i] << ' ';
        }cout << endl;
        
    }
};




void solve() noexcept
{
    cin >> Tcase;
    for (int i = 0; i < Tcase; i++)
    {
        cin >> V >> E;
        Graph G{V,E};
        G.coloring();
        if (G.checkBipartite())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    
}

int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return (0);
}