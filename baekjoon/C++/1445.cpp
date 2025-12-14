/*
return값 : 지나가는 쓰레기, 쓰레기 주변을 지나가는 칸

S와 F는 count하지 않는다

F는 모서리에 있지 않는다.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define START 1
#define GARBAGE 2
#define	G_ADJ 3
#define TARGET 4
using namespace std;

int x_move[] = { -1,1,0,0 }, y_move[] = { 0,0,-1,1 };
int Matrix[51][51];
bool visited[51][51];

int Row, Col;
vector<pair<int, int>> g_pos;
pair<int, int> s_pos;

void show_matrix();
void Input();

bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col) return true;
	else return false;
}
void setMatrix()
{
	for (int i = 0; i < g_pos.size(); i++)
	{
		auto [x_stand, y_stand] = g_pos[i];
		
		for (int j = 0; j <4; j++)
		{
			int x = x_stand + x_move[j];
			int y = y_stand + y_move[j];

			if (!InTheMatrix(x, y)) continue;
	
			if (Matrix[x][y] == 0) Matrix[x][y] = G_ADJ;
		}
	}
}

pair<int,int> Dijkstra()
{
	priority_queue < pair<int, pair<int, pair<int, int>>>> pq;
	// -Garbage, -g_adj, 
	pq.push({ 0,{0,{s_pos.first,s_pos.second}}});
	visited[s_pos.first][s_pos.second] = true; // 방문처리


	while (!pq.empty())
	{
		int garbage = -pq.top().first;
		int g_adj = -pq.top().second.first;
		int x_stand = pq.top().second.second.first;
		int y_stand = pq.top().second.second.second;
		pq.pop();

		if (Matrix[x_stand][y_stand] == TARGET) return { garbage,g_adj };

		for (int i = 0; i < 4; i++)
		{
			int x = x_stand + x_move[i];
			int y = y_stand + y_move[i];

			if (!InTheMatrix(x, y) || visited[x][y]) continue;

			if (Matrix[x][y] == GARBAGE)
				pq.push({ -garbage - 1,{-g_adj,{x,y}} });
			

			else if (Matrix[x][y] == G_ADJ)
				pq.push({ -garbage,{-g_adj-1,{x,y}} });

			else if (Matrix[x][y] == 0 || Matrix[x][y] == TARGET)
				pq.push({ -garbage,{-g_adj,{x,y}} });


			visited[x][y] = true; // 방문처리
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	setMatrix();
	//show_matrix();
	auto [res1, res2] = Dijkstra();
	cout << res1 << " " << res2;


	return 0;
}

void show_matrix()
{
	cout << "This is Matrix" << endl;

	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << Matrix[i][j] << " ";
		
		cout << endl;
	}
}


void Input()
{
	char input;
	cin >> Row >> Col;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cin >> input;
			if (input == '.') Matrix[i][j] = 0;
			if (input == 'g') Matrix[i][j] = GARBAGE, g_pos.push_back({ i,j });
			if (input == 'S')
			{
				Matrix[i][j] = START; s_pos = make_pair(i, j);
			}
			if (input == 'F') Matrix[i][j] = TARGET;
		}
	}
}

