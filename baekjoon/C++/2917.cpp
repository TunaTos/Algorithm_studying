#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
#define MAX_LEN 501
using namespace std;

bool visited[MAX_LEN][MAX_LEN];
int Dis[MAX_LEN][MAX_LEN],Row,Col;
int x_move[] = { -1,1,0,0 }, y_move[] = { 0,0,-1,1 }; // 상하좌우
char Matrix[MAX_LEN][MAX_LEN];
pair<int, int> start, target;

queue<pair<int, int>> q;

void show_Matrix();
void show_visited();
void show_Dis();
void show_queue();

void Input()
{
	string input;
	cin >> Row >> Col;

	for (int i = 0; i < Row; i++)
	{
		cin >> input;
		for (int j = 0;  j < input.size();  j++)
		{
			Matrix[i + 1][j + 1] = input[j];
			if (input[j] == '+') {
				q.push({ i + 1,j + 1 });
				visited[i + 1][j + 1] = true;
			}
			else if (input[j] == 'V')
				start.first = i + 1, start.second = j + 1;
			else if (input[j] == 'J')
				target.first = i + 1, target.second = j + 1;
		}
	}
}
bool InTheMatrix(int& xpos, int& ypos)
{
	if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col)
		return true;
	else
		return false;
}

void setDistance()
{
	int cnt = 0;
	while (!q.empty())
	{

		int Len = q.size();
		
		for (int i = 0; i < Len; i++)
		{
			int x_stand = q.front().first;
			int y_stand = q.front().second;
			Dis[x_stand][y_stand] = cnt;
			q.pop();

			for (int j = 0; j < 4; j++)
			{
				int x = x_stand + x_move[j];
				int y = y_stand + y_move[j];

				if (visited[x][y]) continue;
				if (!InTheMatrix(x, y)) continue;

				visited[x][y] = true; // 방문처리
				q.push({ x,y });
			}
		}
		cnt++;
	}
}

int getResult()
{
	//cout << start.first << " " << start.second << endl;
	//cout << target.first << " " << target.second << endl;

	priority_queue < pair<int, pair<int, int>>> pq;
	auto [x, y] = start;
	int val = Dis[x][y];
	pq.push({ val,{x,y} });
	visited[x][y] = true;

	while (!pq.empty())
	{
		int x_stand = pq.top().second.first;
		int y_stand = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if (cost < val) val = cost;
		if (x_stand == target.first && y_stand == target.second) return val;



		for (int i = 0; i < 4; i++)
		{
			int x = x_stand + x_move[i];
			int y = y_stand + y_move[i];

			if (visited[x][y]) continue;
			if (!InTheMatrix(x,y)) continue;

			pq.push({ Dis[x][y],{x,y} });
			visited[x][y] = true;

		}
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	Input();
	//show_Matrix();
	setDistance();
	memset(visited, false, sizeof(visited));
	cout << getResult();




	return 0;
}

void show_Matrix()
{
	cout << "This is Matrix" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << Matrix[i][j] << " ";
		}cout << endl;
	}
}
void show_visited()
{
	cout << "This is visited" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << visited[i][j] << " ";
		}cout << endl;
	}
}
void show_Dis()
{
	cout << "This is distance" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << Dis[i][j] << " ";
		}cout << endl;
	}
}
void show_queue()
{
	cout << "This is queue" << endl;
	while (!q.empty())
	{
		cout << q.front().first << " " << q.front().second << endl;
		q.pop();
	}
}