/*
지도 밖으로 나가는 건 없다
유니온 파인드 사용해야할 것 같음
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX_LEN 1001

using namespace std;
int Row, Col,cnt, res;
char Matrix[MAX_LEN][MAX_LEN];
int check[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];

//Function For Debug
void show_matrix();
void show_check();
void show_visited();

int parents[1000001];
int weight[1000001];

//Function For Union-Find
int Find(int a)
{
	if (parents[a] == a) return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
	int roota = Find(a);
	int rootb = Find(b);

	if (roota == rootb) return;

	else if (weight[roota] > weight[rootb])
	{
		parents[rootb] = roota;
		weight[roota] += weight[rootb];
	}
	else
	{
		parents[roota] = rootb;
		weight[rootb] += weight[roota];
	}

}
void Input()
{
	string input;
	cin >> Row >> Col;
	
	for (int i = 1; i <= Row; i++)
	{
		cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			Matrix[i][j + 1] = input[j];
		}
	}

	for (int i = 1; i <= 1000001; i++)
	{
		parents[i] = i;
	}
}

//Function For BFS
bool InTheMatrix(int xpos, int ypos)
{
	if (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col) 
		return true;
	else
		return false;
}
void bfs(int xpos, int ypos)
{
	queue<pair<int, int>> q;
	q.push({ xpos,ypos });
	visited[xpos][ypos] = true;
	check[xpos][ypos] = ++cnt;
	res++;

	while (!q.empty())
	{
		int Len = q.size();
		
		for (int i = 0; i < Len; i++)
		{
			int x_stand = q.front().first;
			int y_stand = q.front().second;
			int x = x_stand;
			int y = y_stand;
			check[x][y] = cnt;

			q.pop();
			
			check[x_stand][y_stand] = cnt;

			if (Matrix[x_stand][y_stand] == 'D')
				x++;
			else if (Matrix[x_stand][y_stand] == 'U')
				x--;
			else if (Matrix[x_stand][y_stand] == 'L')
				y--;
			else if (Matrix[x_stand][y_stand] == 'R')
				y++;

			if (!visited[x][y]) // 방문하지 않았다면
			{
				q.push({ x,y });
				visited[x][y] = true;
			}

			else if (visited[x][y])
			{
				if (check[x][y] != check[x_stand][y_stand])
				{
					Union(check[x_stand][y_stand], check[x][y]);
					res--;
				}
				else
					continue;
			}
			
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			if (!visited[i][j])
				bfs(i, j);
		}
	}
	//show_matrix();
	//show_check();
	/*for (int i = 1; i <= cnt; i++)
	{
		cout << parents[i] << " ";
	}cout << endl;*/

	cout << res;


	
	return 0;
}



void show_matrix()
{
	cout << "This is Matrix : " << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void show_check()
{
	cout << "This is check : " << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << check[i][j] << " ";
		}cout << endl;
	}
}
void show_visited()
{
	cout << "This is visited : " << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << visited[i][j] << " ";
		}cout << endl;
	}
}