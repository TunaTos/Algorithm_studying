#include <bits/stdc++.h>
using namespace std;

const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1};
int Row, Col;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

template<typename container>
void show_matrix(const container& c)
{
	
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
}

void input() noexcept
{
	string str;
	cin >> Row >> Col;
	matrix.assign(Row+1, vector<int>(Col+1, 0));
	visited.assign(Row+1, vector<bool>(Col+1, 0));
	
	for (int i = 1; i <= Row; i++)
	{
		cin >> str;
		for (int j = 0; j < Col; j++)
		{
			if (str[j] == '1')
				matrix[i][j+1] = 0;
			if (str[j] == '0')
				matrix[i][j+1] = -1;
		}
	}
}

bool inTheMatrix(const int& xpos, const int& ypos) noexcept
{
	return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
}

void bfs() noexcept
{
	int cnt = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(1,1));
	visited[1][1] = true;
	matrix[1][1] = 1;

	while (!q.empty())
	{
		++cnt;
		size_t q_size = q.size();
		for (size_t i = 0; i < q_size; i++)
		{
			int xpos = q.front().first;
			int ypos = q.front().second;
			q.pop();


			for (int j = 0; j < 4; j++)
			{
				int x = xpos + x_move[j];
				int y = ypos + y_move[j];


				if (!inTheMatrix(x,y) || visited[x][y] || matrix[x][y] == -1)
					continue;

				visited[x][y] = true;
				q.push(make_pair(x,y));
				matrix[x][y] = cnt;	
			}
		}
	}
}


void solve() noexcept
{
	input();
	bfs();
	cout << matrix[Row][Col];
}



int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}