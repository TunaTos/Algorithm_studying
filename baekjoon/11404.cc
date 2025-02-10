#include <bits/stdc++.h>
#define INF 987654321
#define endl '\n'
using namespace std;

int V, E;
vector<vector<int>> matrix;

void showMatrix() {
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (matrix[i][j] == INF)
				cout << 0 << " ";
			else
				cout << matrix[i][j] << " ";
		}cout << endl;	
	}
}

void Folyd() {
	for (int k = 1; k <= V; k++)
		for (int s = 1; s <= V; s++)
			for (int e = 1; e <= V; e++)
				if (matrix[s][e] > matrix[s][k] + matrix[k][e])
					matrix[s][e] = matrix[s][k] + matrix[k][e];
}




void input() 
{
	cin >> V >> E;

	matrix.resize(V+1, vector<int>(V+1, INF));
	for (int i = 1; i <= V; ++i)
		matrix[i][i] = 0;
	

	int from, to, cost;
	for (size_t i = 0; i < E; i++)
	{
		cin >> from >> to >> cost;
		if (cost < matrix[from][to])
			matrix[from][to] = cost;
	}
	//showMatrix();
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	input();
	Folyd();
	showMatrix();
	return (0);
}