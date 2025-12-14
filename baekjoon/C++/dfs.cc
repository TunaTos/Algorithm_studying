#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void input()
{
	visited.assign(10+1, false);
	adj.assign(10+1, vector<int>());

	adj[1].push_back(2);
	adj[2].push_back(1); 

	adj[2].push_back(3);
	adj[3].push_back(2); 
	//////


	adj[1].push_back(4);
	adj[4].push_back(1); 

	adj[4].push_back(5);
	adj[5].push_back(4); 

	adj[5].push_back(6);
	adj[6].push_back(5); 
//////////////////////

	adj[1].push_back(7);
	adj[7].push_back(1); 

	adj[7].push_back(8);
	adj[8].push_back(7); 

	adj[8].push_back(9);
	adj[9].push_back(8); 

	adj[9].push_back(10);
	adj[10].push_back(9); 

}


int dfs(int x, int depth) 
{	
	visited[x] = true;
	int maxDepth = depth;

	for (const auto& next : adj[x]) {
		if (visited[next])
			continue;
		visited[next] = true;
		maxDepth = max(maxDepth, (next, depth+1));
	}
	visited[x] = false;
	return maxDepth; 
}


int main(void)
{
	//ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	cout << dfs(1, 0);

	return (0);
}