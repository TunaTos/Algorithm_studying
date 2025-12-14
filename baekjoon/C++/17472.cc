#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_LEN 11
#define MAX_COM 7
#define endl '\n'
using namespace std;
class Edge
{
public:
	int u;
	int v;
	int weight;

	Edge(const int& u_input, const int& v_input, const int& w_input) :
		u(u_input), v(v_input), weight(w_input) {}

	bool operator < (const Edge& other) const
	{
		return this->weight < other.weight;
	}
};

const int x_move[] = { -1,1,0,0 }; // 상 하 좌 우
const int y_move[] = { 0,0,-1,1 };
int Row, Col, Com;
vector<pair<int, int>> outer;
vector<Edge> edges;
vector<int> parents(MAX_COM), weight(MAX_COM, 1);
vector<vector<int>> matrix(MAX_LEN, vector<int>(MAX_LEN, -1));
vector<vector<bool>> visited(MAX_LEN, vector<bool>(MAX_LEN));

void showMatrix()
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
void showVisited()
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << visited[i][j] << " ";
		cout << endl;
	}
}
void showOuter()
{
	for (auto& ele : outer)
		cout << ele.first << " " << ele.second << endl;
}
void showEdge()
{
	for (auto& ele : edges)
	{
		cout << ele.u << " " << ele.v << " " << ele.weight << endl;
	}cout << endl;
}
int Find(const int& a)
{
	if (parents[a] == a) return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);

	if (a == b) return;

	if (weight[a] <= weight[b])
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

void input()
{
	cin >> Row >> Col;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cin >> matrix[i][j];
	}
}

bool inTheMatrix(const int& row, const int& col)
{
	if (row >= 1 && row <= Row && col >= 1 && col <= Col)
		return true;
	else
		return false;
}

void dfs(const int& row, const int& col)
{

	visited[row][col] = true;
	matrix[row][col] = Com;

	int x, y;
	for (int i = 0; i < 4; i++)
	{
		x = row + x_move[i];
		y = col + y_move[i];

		if (!inTheMatrix(x, y)) continue;
		if (visited[x][y]) continue;
		if (matrix[x][y] == 1)
			dfs(x, y);
	}
}

bool isInner(const int& x, const int& y)
{
	for (int i = 0; i < 4; i++)
	{
		int row = x + x_move[i];
		int col = y + y_move[i];

		if (!inTheMatrix(row, col)) continue;
		if (matrix[row][col] == 0)
			return false;
	}
	return true;
}

void dfsGraph()
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			if (matrix[i][j] != 0 && !isInner(i, j))
				outer.push_back({ i, j });
			if (!visited[i][j] && matrix[i][j] == 1)
			{
				++Com;
				dfs(i, j);
			}
		}
	}
}

int isVerticle(pair<int, int> pos1, pair<int, int> pos2)
{
	if (pos1.first != pos2.first && pos1.second != pos2.second)
		return -1;
	else
	{
		int res = abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second) - 1;
		if (res > 1)
			return res;
		else
			return -1;
	}
}

void setEdges() {
	int L = outer.size();

	for (int i = 0; i < L; i++) {
		for (int j = i + 1; j < L; j++) {
			pair<int, int> pos1 = outer[i];
			pair<int, int> pos2 = outer[j];

			if (matrix[pos1.first][pos1.second] == matrix[pos2.first][pos2.second])
				continue;

			if (pos1.first == pos2.first) {
				int min_col = min(pos1.second, pos2.second);
				int max_col = max(pos1.second, pos2.second);
				bool canBuild = true;

				for (int col = min_col + 1; col < max_col; col++) {
					if (matrix[pos1.first][col] != 0) {
						canBuild = false;
						break;
					}
				}

				if (canBuild && (max_col - min_col - 1) >= 2) {
					int u = matrix[pos1.first][pos1.second];
					int v = matrix[pos2.first][pos2.second];
					int w = max_col - min_col - 1;
					edges.emplace_back(u, v, w);
				}
			}

			if (pos1.second == pos2.second) {
				int min_row = min(pos1.first, pos2.first);
				int max_row = max(pos1.first, pos2.first);
				bool canBuild = true;

				for (int row = min_row + 1; row < max_row; row++) {
					if (matrix[row][pos1.second] != 0) {
						canBuild = false;
						break;
					}
				}

				if (canBuild && (max_row - min_row - 1) >= 2) {
					int u = matrix[pos1.first][pos1.second];
					int v = matrix[pos2.first][pos2.second];
					int w = max_row - min_row - 1;
					edges.emplace_back(u, v, w);
				}
			}
		}
	}
}


void mst()
{
	sort(edges.begin(), edges.end());
	//showEdge();
	//return;
	int edge_number = 0;
	int res = 0;

	for (auto& ele : edges)
	{
		int u = ele.u;
		int v = ele.v;
		int w = ele.weight;

		if (Find(u) == Find(v)) continue;
		Union(u, v);
		res += w;
		++edge_number;
		if (edge_number == Com - 1)
			break;
	}
	if (edge_number != Com - 1)
		res = -1;
	cout << res;
}

int main(void)
{
	input();
	dfsGraph();
	//showMatrix();
	//cout << endl;
	//showVisited();
	//cout << Com << endl;
	for (int i = 1; i <= Com; i++)
		parents[i] = i;
	//cout << endl;
	//showOuter();
	setEdges();
	mst();
	return (0);
}