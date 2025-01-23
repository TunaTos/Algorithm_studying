#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;


class Graph
{
private:
    int V, E;
    vector<vector<int>> adj;
public:
    Graph() = default;
    Graph(const int& v_input, const int& e_input):
        V(v_input), E(e_input), adj(V+1, vector<int>()) {
            int start, to;

            for (int i = 0; i < E; i++)
            {
                cin >> start >> to;
                adj[start].emplace_back(to);
            }
        };
    int getV()
    {
        return this->V;
    }
    void showAdj()
    {
        for (int i = 1; i <= V; i++)
        {
            cout << "i : ";
            
            for(const auto& ele: adj[i])
                cout << ele << endl;
        }
    }
    vector<vector<int>>& getAdj()
    {
        return this->adj;
    }
};

class BFS
{
private:
    int targetDistance, startNode;
public:
    BFS() = default;
    BFS(const int& t_input, const int& s_input):
        targetDistance(t_input), startNode(s_input) {};
    void bfs(vector<vector<int>>& adj, const int& V)
    {
        bool flag{false}; // to check targetDistance
        int d{};
        vector<bool> visited(V+1, false);
        vector<int> dis(V+1, 0);

        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty())
        {    
            int qSize = q.size();
            
            for (int i = 0; i < qSize; i++)
            {
                int start = q.front();
                q.pop();
            
                for (const auto& next: adj[start])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        dis[next] = dis[start] + 1;
                        q.push(next);
                    }                    
                }
            }
        }
        for (int i = 1; i <= V; i++)
        {
            if (dis[i] == targetDistance)
            {
                flag = true;
                cout << i << endl;
            }
        }
        
        if (!flag)
            cout << -1;
    }
};


void solve()
{
    int v, e, targetDistance, startNode;
    cin >> v >> e >> targetDistance >> startNode;

    auto G = Graph{v,e};
    auto B = BFS{targetDistance, startNode};

    B.bfs(G.getAdj(), G.getV());
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}