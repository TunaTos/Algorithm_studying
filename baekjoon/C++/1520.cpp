#include <bits/stdc++.h>
#define MAX_LEN 501
#define endl '\n'
using namespace std;
const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1}; 
int Row, Col, res;
int matrix[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];

template<typename T>
void showMatrix(const T& t)
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
			cout << t[i][j] << " ";
		cout << endl;
	}
}

bool inTheMatrix(const int& x,const int& y) noexcept
{
	if(x >= 1 && x <= Row && y >= 1 && y <= Col)
		return true;
	else
		return false;
}

int dfs(const int& xpos, const int& ypos) noexcept
{
	if(dp[xpos][ypos] != -1) return dp[xpos][ypos];
	if(xpos==1 && ypos== 1) return 1;

	dp[xpos][ypos] = 0;
	for (int i = 0; i < 4; i++)
	{
		int next_x = xpos + x_move[i];
		int next_y = ypos + y_move[i];

		if(!inTheMatrix(next_x,next_y)) continue;
		if(matrix[xpos][ypos] >= matrix[next_x][next_y]) continue;

		dp[xpos][ypos] += dfs(next_x,next_y);
	}
	return dp[xpos][ypos];
}

void input() noexcept
{
	cin >> Row >> Col;
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++) {
			cin >> matrix[i][j];
			dp[i][j] = -1;
		}
	}
}

int main(void)
{
	//ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	//showMatrix(dp);
	res = dfs(Row,Col);
	cout << res << endl;
	//showMatrix(dp);
	return (0);
}