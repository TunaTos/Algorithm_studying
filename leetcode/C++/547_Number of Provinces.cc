class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    int V, Res;

    void AdjInit(vector<vector<int>>& isConnected) {
        V = isConnected.size();
        adj.assign(V+1, vector<int>());

        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);

    }
    void dfs(int node) {
        visited[node] = true;

        for (const auto& nextNode: adj[node])
            if (!visited[nextNode])
                dfs(nextNode);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //get connected component
        AdjInit(isConnected);
        visgi
        for (int i = 1; i <= V; ++i)
        {
            if (adj[i].size() != 0 && !visited[i]) 
            {
                dfs(i);
                ++Res;
            }
        }

        return Res;
    }

};