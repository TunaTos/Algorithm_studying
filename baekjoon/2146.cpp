#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

short Matrix[101][101];
short dpt[101][101]; // 거리 담는 Matrix
bool visited[101][101]; // visited 
bool e_visited[101][101]; // Edge담을때 쓰는 visited
int Len;
int x_move[] = { -1,1,0,0 };
int y_move[] = { 0,0,-1,1 };
queue<tuple<int, int, int, int>> Edges; // xpos ypos i_num dpt


void showDpt();
void showQueue();
void showMatrix();
void showVisited();
void Init()
{
	memset(dpt, -1, sizeof(dpt));
	memset(Matrix, -1, sizeof(Matrix));
	cin >> Len;

	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cin >> Matrix[i][j];
		}
	}
}

bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len)
		return true;
	else
		return false;
}

void bfs(int xpos, int ypos, int cnt)
{
	queue<pair<int, int>> q;
	q.push({ xpos,ypos });
	visited[xpos][ypos] = true;

	while (!q.empty())
	{
		int x_stand = q.front().first;
		int y_stand = q.front().second;
		Matrix[x_stand][y_stand] = cnt;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = x_stand + x_move[i];
			int y = y_stand + y_move[i];

			if (!InTheMatrix(x, y))
				continue;

			if (Matrix[x][y] == 1 && !visited[x][y])
			{
				q.push({ x,y });
				visited[x][y] = true;
			}

			if (Matrix[x][y] == 0 && !e_visited[x_stand][y_stand])
			{
				Edges.push(make_tuple(x_stand, y_stand, cnt, 0));
				e_visited[x_stand][y_stand] = true;
				dpt[x_stand][y_stand] = 0;
			}

		}
	}
}



void setIsland()
{
	int cnt = 1;

	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			if (Matrix[i][j] == 1 && !visited[i][j])
			{
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}
}

void Solve()
{
	while (!Edges.empty())
	{
		int Len = Edges.size();

		for (int i = 0; i < Len; i++)
		{
			tuple<int, int, int, int> t = Edges.front();
			Edges.pop();

			int x_stand = get<0>(t);
			int y_stand = get<1>(t);


			for (int i = 0; i < 4; i++)
			{
				int x = x_stand + x_move[i];
				int y = y_stand + y_move[i];
				if (!InTheMatrix(x, y)) continue;
				//if (dpt[x][y] != 0 && Matrix[x][y] != Matrix[x_stand][y_stand])
				//{
				//	cout << dpt[x][y] + dpt[x_stand][y_stand];
				//	return;
				//}

				if (Matrix[x][y] == 0 && !visited[x][y])
				{
					Matrix[x][y] = get<2>(t); // 같은 다리로 칭함
					visited[x][y] = true; // 방문처리
					dpt[x][y] = get<3>(t) + 1; // 다리길이 update
					tuple<int, int, int, int> input_t = make_tuple(x, y, get<2>(t), get<3>(t) + 1);
					Edges.push(input_t);
				}
			}
		}
	}
}


void getResult()
{
	int res = 100000000;
	int xpos, ypos;

	for (int i = 1; i <=Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			for (int a = 0; a < 4; a++)
			{
				int x = i + x_move[a];
				int y = j + y_move[a];

				if(!InTheMatrix(x,y)) continue;

				if (Matrix[i][j] != Matrix[x][y] && dpt[x][y] != -1 && dpt[i][j] != -1)
				{
					res = min(res, dpt[x][y] + dpt[i][j]);
				}
			}
		}
	}
	cout << res;


}


int main() {
	ios::sync_with_stdio(); cin.tie(); cout.tie();

	Init();
	setIsland();
	Solve();
	getResult();




	return 0;
}

void showMatrix()
{
	cout << "This is Matrix : " << endl;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}

}

void showVisited()
{
	cout << "This is visited : " << endl;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void showQueue()
{
	while (!Edges.empty())
	{
		tuple<int, int, int, int> t = Edges.front();
		cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << endl;
		Edges.pop();
	}
}

void showDpt()
{
	cout << "This is dpt : " << endl;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cout << dpt[i][j] << " ";
		}
		cout << endl;
	}

}