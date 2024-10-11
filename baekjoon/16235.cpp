/*
입력으로 주어지는 나무의 위치는 모두 다르다
입력으로 주어지는 나무의 나이 <=10
A[r][c] <= 100


*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_LEN 11

using namespace std;
int Len, t_num, Year;
int x_move[] = { -1,-1,-1,0,0,1,1,1 }; // 시계방향
int y_move[] = { -1,0,1,-1,1,-1,0,1 };


deque < pair<int, pair<int, int>>> dq;
queue<pair<int, pair<int, int>>> dead;

int energy[MAX_LEN][MAX_LEN], add_energy[MAX_LEN][MAX_LEN];

void Input()
{
	cin >> Len >> t_num >> Year;
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cin >> add_energy[i][j];
			energy[i][j] = 5;
		}
	}

	for (int i = 0; i < t_num; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		dq.push_back({ c,{a,b} });
	}
	sort(dq.begin(), dq.end());

}


void Spring()
{

	int Len = dq.size();

	for (int i = 0; i < Len; i++)
	{
		int age = dq.front().first;
		int xpos = dq.front().second.first;
		int ypos = dq.front().second.second;
		dq.pop_front();

		if (energy[xpos][ypos] < age) // 나무가 죽는 경우
		{
			dead.push({ age,{xpos,ypos} });
			continue;
		}
		else if (energy[xpos][ypos] >= age)
		{
			energy[xpos][ypos] -= age;
			age++;
			dq.push_back({ age,{xpos,ypos} });
		}
	}
}

void Summer()
{
	while (!dead.empty())
	{
		int age = dead.front().first;
		int xpos = dead.front().second.first;
		int ypos = dead.front().second.second;

		energy[xpos][ypos] += age / 2;
		dead.pop();
	}
}
bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len)
		return true;
	else
		return false;
}
void Fall()
{
	int Len = dq.size();
	queue < pair<int, pair<int, int>>> add_pos;

	for (int i = 0; i < Len; i++)
	{
	
		int age = dq.front().first;
		int x_stand = dq.front().second.first;
		int y_stand = dq.front().second.second;
		dq.pop_front();

		if (age % 5 == 0) // 5의 배수인 경우
		{
			for (int j = 0; j < 8; j++)
			{
				int x = x_stand + x_move[j];
				int y = y_stand + y_move[j];

				if (!InTheMatrix(x, y)) continue; // 메트릭스 밖으로 넘어가는 경우

				else // 심어야하는것
				{
					add_pos.push({ 1,{x,y} });
				}		
			}
		}
		dq.push_back({ age,{x_stand,y_stand} });
	}

	while (!add_pos.empty())
	{
		dq.push_front(add_pos.front());
		add_pos.pop();
	}
}

void Winter()
{
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			energy[i][j] += add_energy[i][j];
		}
	}
}

void Solve()
{
	for (int i = 0; i < Year; i++)
	{
		Spring();
		Summer();
		Fall();
		Winter();
	}
	cout << dq.size();
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solve();



	return 0;
}