#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int ALPHA_LEN = 27;
const int x_move[] = { -1,1,0,0 }; // 상 하 좌 우
const int y_move[] = { 0,0,-1,1 };

int Row, Col, res = -100;
int Matrix[21][21];
int visited[ALPHA_LEN];


// Function For Debugging
void show_matrix();

void Input();

bool InTheMatrix(int& row, int& col)
{
	if (row >= 1 && row <= Row && col >= 1 && col <= Col)
		return true;
	else
		return false;
}


void traverse(int row, int col, int dpt)
{
	res = max(res, dpt);
	if (dpt + (Row * Col - dpt) <= res) return;
	

	for (int i = 0; i < 4; i++)
	{
		int x = row + x_move[i];
		int y = col + y_move[i];
		int next_val = Matrix[x][y];
		//cout << "I am row and col" << row << " " << col << endl;
		//cout << "I am x and y" << x << " " << y << endl;
		if (!InTheMatrix(x, y) || visited[next_val]==1) continue;

		visited[next_val]++;
		traverse(x, y, dpt+1);
		visited[next_val]--;

	}

	//if (!flag)
	//{
		//cout << "accepted! " << dpt << endl;
		//res = max(res, dpt);
//	}

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	//show_matrix();
	visited[Matrix[1][1]]++;
	traverse(1, 1, 1);


	cout << res;

	return 0;
}

void show_matrix()
{
	cout << "This is matrix" << endl;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << Matrix[i][j] << " ";
		}cout << endl;
	}
}

void Input()
{
	cin >> Row >> Col;
	
	string input;

	for (int i = 0; i < Row; i++)
	{
		cin >> input;

		for (int j = 0; j < input.size(); j++)
			Matrix[i + 1][j + 1] = input[j] - 'A' + 1;	
	}

}