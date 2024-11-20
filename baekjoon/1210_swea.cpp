#include <bits/stdc++.h>
#define MAX_LEN 100
#define endl '\n'
using namespace std;

int matrix[MAX_LEN+1][MAX_LEN+1], test_num, start_pos, res;
bool visited[MAX_LEN+1][MAX_LEN+1];
const int x_move[] = {0,0, -1}; // 좌 우 상
const int y_move[] = {-1,1, 0}; 


template<typename T>
void debug(const T& t) noexcept
{
	for (int i = 1; i <= MAX_LEN; i++)
	{
		for (int j = 1; j <= MAX_LEN; j++)
		{
			cout << t[i][j] << " ";
		}cout << endl;
	}
}

bool inTheMatrix(const int x, const int y) noexcept
{
	if(x >= 1 && x <= MAX_LEN && y >=1 && y <= MAX_LEN)
		return true;
	return false;
}

void input() noexcept
{
	cin >> test_num;
	for (int i = 1; i <= MAX_LEN; i++)
	{
		for (int j = 1; j <= MAX_LEN; j++)
		{
			cin >> matrix[i][j];
			if(matrix[i][j] == 2)
				start_pos = j;
		}		
	}
}

void reset() noexcept
{
	for (int i = 1; i <= MAX_LEN; i++)
	{
		for (int j = 1; j <= MAX_LEN; j++)
			visited[i][j] = false;
	}
}


void dfs(int x_pos, int y_pos) noexcept
{
	visited[x_pos][y_pos] = true;
	if (x_pos == 1)
	{
		cout <<y_pos -1 << endl;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int x = x_pos + x_move[i];
		int y = y_pos + y_move[i];

		if (!visited[x][y] && inTheMatrix(x,y) && matrix[x][y] == 1)
			dfs(x,y);
	}
}


void solve() noexcept
{
	input();
	// debug(matrix);
	dfs(MAX_LEN, start_pos);
	// debug(matrix);
	// cout << "---------------------------------" << endl;
	// debug(visited);
	cout << "#" << test_num << " ";
	cout << res << endl;
	reset();
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// solve();
	for (int i = 0; i < 10; i++)
	{
		solve();
	}
	
	return (0);
}