#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>
using namespace std;
int x_move[] = { -1,1,0,0 };
int y_move[] = { 0,0,-1,1 };
int Len, s, e;
int Matrix[101][101];
bool visited[101][101];
int res;
vector<pair<int, int>> vec;

void Debug();
void init()
{
	cin >> Len >> s >> e;

	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
			cin >> Matrix[i][j];
	}
}

bool InTheMatrix(int xpos, int ypos) // 좌표를 넣어야함
{
	if (xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len)
		return true;
	else
		return false;
}

bool GetDistance(int v1, int v2) // Value를 넣어야함
{
	if (abs(v1 - v2) >= s && abs(v1 - v2) <= e)
		return true;
	else
		return false;
}


void bfs()
{
	long long sum =0;
	queue<pair<int, int>> q;
	for (auto& ele : vec)
	{
		q.push({ ele.first,ele.second });
		sum += Matrix[ele.first][ele.second];
	}




	while (!q.empty())
	{
		int Len = q.size();
		int x_stand = q.front().first;
		int y_stand = q.front().second;
		visited[x_stand][y_stand] = true;
		q.pop();


		for (int i = 0; i < Len; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int x = x_stand + x_move[j];
				int y = y_stand + y_move[j];
				
				if (InTheMatrix(x, y) && visited[x][y] != true && GetDistance(Matrix[x_stand][y_stand], Matrix[x][y]))
				{
					q.push({ x,y });
					vec.push_back({ x,y });
					sum += Matrix[x][y];
					visited[x][y] = true;
				}
			}
		}
	}

	int value = sum / vec.size();

	for (auto& ele : vec)
		Matrix[ele.first][ele.second] = value;
	
	vec.clear();
} 

void Solve()
{
	
	int tmp = 0; // if tmp ==0 return


	while (1)
	{
		for (int i = 1; i <= Len; i++)
		{
			for (int j = 1; j <= Len; j++)
			{
				for (int a = 0; a < 4; a++)
				{
					int x = i + x_move[a];
					int y = j + y_move[a];

					if (InTheMatrix(x, y) && visited[x][y] == false && GetDistance(Matrix[i][j], Matrix[x][y]))
						vec.push_back({ x,y });
					
					if (!vec.empty())
					{
						bfs();
						tmp++;
					}
				}
			}
		}
		

		if (tmp == 0)
			break;
		res++;
		tmp = 0;
		memset(visited, false, sizeof(visited));
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();

	init();

	Solve();
	cout << res;


	return 0;
}


void Debug()
{
	cout << "This is Matrix : " << endl;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
			cout << Matrix[i][j] << " ";
		
		cout << endl;
	}

	cout << "This is visited : " << endl;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
			cout << visited[i][j] << " ";

		cout << endl;
	}

}