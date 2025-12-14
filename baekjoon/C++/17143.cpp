#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define UPPER 1	
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define MAX_LEN 200
using namespace std;

class shark
{
public:
	int xpos;
	int ypos;
	int speed;
	int dir;
	int size;


	shark(int a, int b, int c, int d, int e)
	{
		xpos = a, ypos = b, speed = c, dir = d, size = e;
	}
	bool operator < (shark& other)
	{
		return this->size > other.size;
	}
	friend ostream& operator << (ostream& os, shark& s)
	{
		os << s.xpos << " " << s.ypos << " " << s.dir;
		return os;
	}
};


deque<shark> q;
int Row, Col, s_num, pos = 1, res;
int Matrix[MAX_LEN][MAX_LEN];
int x_move[] = { -1,1,0,0 }; // 상 하 우 좌
int y_move[] = { 0,0,1,-1 };

void show_matrix();

void Input()
{

	cin >> Row >> Col >> s_num;

	int a, b, c, d, e;
	for (int i = 0; i < s_num; i++)
	{
		cin >> a >> b >> c >> d >> e;
		q.push_back({ a,b,c,d,e });
		Matrix[a][b] = d;
	}
	sort(q.begin(), q.end());

}


void change_dir(shark& s)
{
	if (s.dir == UPPER) s.dir = DOWN;
	else if (s.dir == DOWN) s.dir = UPPER;
	else if (s.dir == LEFT) s.dir = RIGHT;
	else if (s.dir == RIGHT) s.dir = LEFT;
}


void SharkMove(shark& s)
{
	if (s.dir == UPPER || s.dir == DOWN)
	{
		s.speed %= ((Row - 1) * 2);
	}

	else if (s.dir == LEFT || s.dir == RIGHT)
	{
		s.speed %= ((Col - 1)*2);
	}

	for (int i = 0; i < s.speed; i++)
	{
		if (s.dir == UPPER && s.xpos == 1) change_dir(s);
		else if (s.dir == DOWN && s.xpos == Row) change_dir(s);
		else if (s.dir == RIGHT && s.ypos == Col) change_dir(s);
		else if (s.dir == LEFT && s.ypos == 1) change_dir(s);
		s.xpos += x_move[s.dir - 1];
		s.ypos += y_move[s.dir - 1];
	}


}

void MoveAndKill() // 상어를 다른 수조로 옮김과 동시에 죽인다
{
	int x_target = 0;
	int y_target = 0;


	while (!q.empty())
	{
		// get_pos
		bool flag = false; // 죽일 것이 있는지 없는지 찾는다
		int Len = q.size();

		for (int i = 1; i <= Row; i++)
		{
			if (Matrix[i][pos])
			{
				flag = true;
				x_target = i;
				y_target = pos;
				break;
			}
		}

		memset(Matrix, 0, sizeof(Matrix)); // 메트릭스 초기화

		for (int i = 0; i < Len; i++)
		{
			shark s_stand = q.front();
			q.pop_front();


			if (flag && s_stand.xpos == x_target && s_stand.ypos == y_target) // 낚시꾼이 잡는 것
			{
				res += s_stand.size;
				continue;
			}

			else
			{
				SharkMove(s_stand); // 상어가 움직임

				int xpos = s_stand.xpos;
				int ypos = s_stand.ypos;

				if (Matrix[xpos][ypos]) continue; // 큰 상어가 잡아먹는 case
				else
				{
					Matrix[xpos][ypos] = s_stand.dir;
					q.push_back(s_stand); // 뒤에 넣는다
				}
			}

		}
		pos++;
		if (pos == Col + 1) break;

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//cout << "xpos ypos speed dir size" << endl;

	Input();


	MoveAndKill();
	//show_matrix();
	cout << res;




	return 0;
}

void show_matrix()
{
	cout << "This is Matrix1" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << Matrix[i][j] << " ";
		}cout << endl;
	}
}




