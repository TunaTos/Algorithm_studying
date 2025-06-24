#include <bits/stdc++.h>
using namespace std;

const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1};
int Row, Col, limit, row, col;
vector<vector<int>> matrix;

template<typename matrix>
void showMatrix(matrix& m)
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void input()
{

	cin >> Row >> Col >> limit;
	matrix.resize(Row+1, vector(Col+1, 0));
	
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 2)
			{
				row = i;
				col = j;
			}
		}
	}
}

bool inTheMatrix(int xpos, int ypos)
{
	return xpos >=1 && xpos <= Row && ypos >= 1 && ypos <=Col;
}

int getDistance(int sRow, int sCol, int tRow, int tCol, vector<vector<int>> matrix)
{
	vector<vector<bool>> visited(Row+1, vector<bool>(Col+1, false));

	queue<pair<int,pair<int,int>>> q;
	q.push({1,{sRow,sCol}});
	visited[sRow][sCol] = true;
	matrix[sRow][sCol] = 0;

	while (!q.empty())
	{
		int w = q.front().first;
		int xpos = q.front().second.first;
		int ypos = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];

			if (!inTheMatrix(x,y)) continue;
			if (visited[x][y]) continue;
			if (matrix[x][y] == 1) continue;
			
			matrix[x][y] = matrix[xpos][ypos] + 1;
			visited[x][y] = true;
			if (x == tRow && y == tCol)
				return matrix[xpos][ypos] + 1; 
			q.push({matrix[xpos][ypos] + 1,{x,y}});
		}
	}
	return -1;
}



void solve()
{
	input();
	
	
	vector<vector<int>> m1 = matrix;
	vector<vector<int>> m2 = matrix;
	int tmp1 = getDistance(1, 1, Row, Col, m1);
	int tmp2 = getDistance(1, 1, row, col, m2);
	int tmp3 = getDistance(row, col, Row, Col, vector<vector<int>>(Row+1, vector<int>(Col+1, 0)));

	
	if (tmp1 == -1 && tmp2 == -1)
		cout << "Fail";
	else if (tmp1 == -1 && tmp2 != -1)
	{
		if (tmp2 + tmp3 <= limit)
			cout << tmp2 + tmp3;
		else
			cout << "Fail";
	}
	else if (tmp1 != -1 && tmp2 == -1)
	{
		if (tmp1 <= limit)
			cout << tmp1;
		else
			cout << "Fail";
	}
	else 
	{
		int res = min(tmp1, tmp2 + tmp3);

		if (res <= limit)
			cout << res;
		else
			cout << "Fail";	
	}
}

int main(void)
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}