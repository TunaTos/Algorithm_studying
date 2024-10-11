#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
const int MAX_PARENTS = 1000001;
const int r_move[] = { -1,1,0,0 }; // 상 하 좌 우
const int c_move[] = { 0,0,-1,1 };

int Row, Col, res;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<int> parents;
vector<int> weight;

void show_matrix();
void show_visited();
void show_parents();
// Function for union-find
int Find(const int& a)
{
	if (parents[a] == a)
		return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b) return;

	if (weight[a] < weight[b])
	{
		weight[b] += weight[a];
		parents[a] = b;
	}
	else
	{
		weight[a] += weight[b];
		parents[b] = a;
	}
}



void Init()
{
	cin >> Row >> Col;
	matrix.resize(Row + 1);
	visited.resize(Row + 1);
	parents.resize(Row * Col + 1);
	weight.resize(Row * Col + 1, 1);
	for (int i = 0; i <= Row * Col; i++)
		parents[i] = i;

	for (size_t i = 0; i <= Row; ++i)
	{
		matrix[i].resize(Col + 1);
		visited[i].resize(Col + 1, false);
	}

	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			char c; cin >> c;
			if (c == 'N')
				matrix[i][j] = 0;
			if (c == 'S')
				matrix[i][j] = 1;
			if (c == 'W')
				matrix[i][j] = 2;
			if (c == 'E')
				matrix[i][j] = 3;
		}
	}
}

int getIndex(const int& row, const int& col)
{
	return (row - 1) * Col + col;
}


void dfs(int row, int col)
{
	//cout << "row col : " << row << col << endl;
	const int add_v = matrix[row][col];
	// 방문처리
	visited[row][col] = true;
	//show_visited();

	auto [next_r, next_c] = make_pair(row + r_move[add_v],col + c_move[add_v]);
	//Union(getIndex(row,col),getIndex(next_r, next_c));
	
	if (!visited[next_r][next_c])
	{
		Union(getIndex(row, col), getIndex(next_r, next_c));
		dfs(next_r, next_c);
	}
	else if (visited[next_r][next_c])
	{
		Union(getIndex(row, col), getIndex(next_r, next_c));
		return;
	}
}


void Solve()
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			if (!visited[i][j])
				dfs(i, j);			
		}
	}
	for (int i = 1; i <= Row * Col; ++i)
	{
		if (parents[i] == i)
			res++;
	}
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	Solve();
	//show_parents();
	//show_matrix();
	//show_visited();
	cout << res;

	return(0);
}

void show_matrix()
{
	cout << "This is matrix" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void show_visited()
{
	cout << "This is visited" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << visited[i][j] << " ";
		cout << endl;
	}


}
void show_parents()
{
	cout << "This is parents :" << endl;
	for (int i = 1; i <= Row * Col; ++i)
		cout << parents[i] << " ";
}
