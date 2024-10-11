#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#define WATER 0
using namespace std;
int Row, Col, Time;
int Matrix[301][301];
bool visited[301][301];
int x_move[] = { -1,1,0,0 };
int y_move[] = { 0,0,-1,1 };
vector<tuple<int, int, int>> melted_pos;

void showVector();
void showMatrix();
void showVisited();
void Init()
{
	cin >> Row >> Col;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cin >> Matrix[i][j];
	}
}

void melting()
{
	for (auto& ele : melted_pos)
	{
		int xpos = get<0>(ele);
		int ypos = get<1>(ele);
		int m = get<2>(ele);

		if (m > Matrix[xpos][ypos]) Matrix[xpos][ypos] = 0;
		else
			Matrix[xpos][ypos] -= m;
	}

	melted_pos.clear();
}

void reset_visited(){ memset(visited, false, sizeof(visited)); }

bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col)
		return true;
	else
		return false;
}
bool bfs(int xpos, int ypos)
{
	queue<pair<int, int>> q;
	q.push({ xpos,ypos });
	visited[xpos][ypos] = true;
	
	while (!q.empty())
	{
		int Len = q.size();
		int melt_num = 0;

		for (int i = 0; i < Len; i++)
		{
			int x_stand = q.front().first;
			int y_stand = q.front().second;
			q.pop();


			for (int j = 0; j < 4; j++)
			{
				int x = x_stand + x_move[j];
				int y = y_stand + y_move[j];

				if (!InTheMatrix(x, y)) continue;

				if (Matrix[x][y] == WATER)
					melt_num++;

				if (Matrix[x][y] != WATER && !visited[x][y])
				{
					q.push({ x,y });
					visited[x][y] = true;
				}
			}

			if (melt_num != 0)
				melted_pos.push_back(make_tuple(x_stand, y_stand, melt_num));

			melt_num = 0;
		}
	}
	return true;
}


bool Solve()
{
	/*
	두 덩이 이상으로 분리되는 최초의 시간을 구해라
	전부 다 녹을 때 까지 분리되지 않으면 0을 출력한다
	*/

	int b_ice_num = 0;
	int ice_num = 0;



	while (true)
	{
		bool is_bfs = false;
		int b_cnt = 0;
		
		for (int i = 1; i <= Row; i++)
		{
			for (int j = 1; j <= Col; j++)
			{
				if (Matrix[i][j] != WATER && !visited[i][j])
				{
					is_bfs = bfs(i, j);
					b_cnt++;
				}
			}
		}

		if (Time == 0 && b_cnt == 0)
		{
			return false;
		}

		else if (Time != 0)
		{
			if (b_ice_num == 1 && b_cnt == 0)
				return false;

			if (b_cnt >= 2)
				return true;
		}

		b_ice_num = b_cnt;
		Time++;

		melting();
		reset_visited();
		//showMatrix();
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();

	Init();
	if (!Solve())
	{
		cout << 0;
		return 0;
	}
	cout << Time;





	return 0;
}

void showMatrix()
{
	cout << "This is Matrix : " << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << Matrix[i][j] << " ";

		cout << endl;
	}
}
void showVisited()
{
	cout << "This is visited : " << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << visited[i][j] << " ";

		cout << endl;
	}

}

void showVector()
{
	cout << "This is vector : " << endl;

	for (auto& ele : melted_pos)
		cout << get<0>(ele) << " " << get<1>(ele) << " " << get<2>(ele) << endl;
}