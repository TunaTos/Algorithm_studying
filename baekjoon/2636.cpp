#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define CHEESE 1
#define AIR 0
using namespace std;

int Matrix[101][101], Air[101][101];
vector<pair<int, int>> pos;
bool visited[101][101];
int Row, Col, c_num, res;
int x_move[] = { -1,1,0,0 };
int y_move[] = { 0,0,-1,1 };

void Debug1(); // Air
void Debug2(); // Matirx
void Debug3(); // Visited

void Init()
{
	cin >> Row >> Col;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cin >> Matrix[i][j];
			if (Matrix[i][j] == CHEESE) c_num++;
		}	
	}
}

bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col)
		return true;
	else
		return false;
}
bool IsMelted(int xpos, int ypos)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = xpos + x_move[i];
		int y = ypos + y_move[i];
		if (Air[x][y])
		{
			return true;
		}
	}
	return false;
}

void setAir()
{
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visited[1][1] = true;
	Air[1][1] = 1;

	while (!q.empty())
	{
		int x_stand = q.front().first;
		int y_stand = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int x = x_stand + x_move[i];
			int y = y_stand + y_move[i];

			if (!InTheMatrix(x, y))
				continue;

			if (!visited[x][y] && Matrix[x][y]==0)
			{
				q.push({ x,y });
				visited[x][y] = true;
				Air[x][y] = 1;
			}

		}
	}
}

int bfs(int xpos, int ypos)
{
	queue<pair<int, int>> q;
	q.push({ xpos,ypos });
	visited[xpos][ypos] = true;
	Matrix[xpos][ypos] = 0;
	int cnt = 1;
	

	while (!q.empty())
	{
		int x_stand = q.front().first;
		int y_stand = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int x = x_stand + x_move[i];
			int y = y_stand + y_move[i];

			if (!InTheMatrix(x, y))
				continue;

			if (!visited[x][y] && Matrix[x][y] == 1 && !Air[x][y])
			{
				q.push({ x,y });
				visited[x][y] = true;
				if (IsMelted(x,y))
				{
					Matrix[x][y] = 0;
					cnt++;
				}
			}
		}
	}
	return cnt;
}



void Solve()
{
	
	int tmp = 0;

	while (c_num)
	{
		setAir();

		for (int i = 1; i <= Row; i++)
		{
			for (int j = 1; j <= Col; j++)
			{
				if (Matrix[i][j] == CHEESE && !visited[i][j])
				{
					tmp += bfs(i, j);
				}
			}
		}
		

		res++;
		if (tmp == c_num)
		{
			cout << res << '\n';
			cout << tmp;
			return;
		}
		c_num -= tmp;
		tmp = 0;

		memset(visited, false, sizeof(visited));
		memset(Air, false, sizeof(Air));
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	Solve();








	return 0;
}


void Debug1()
{
	cout << "This is Air" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << Air[i][j] << " ";

		cout << endl;

	}
}
void Debug2()
{
	cout << "This is Matrix" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << Matrix[i][j] << " ";

		cout << endl;

	}


}
void Debug3()
{
	cout << "This is visited" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << visited[i][j] << " ";

		cout << endl;

	}



}