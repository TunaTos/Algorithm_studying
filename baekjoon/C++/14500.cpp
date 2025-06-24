#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Matrix[501][501]; // Warning index starts 1
int dp[501][501];
int Row, Col;

int res = -100;

void Init()
{
	cin >> Row >> Col;

	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cin >> Matrix[i][j];
			dp[i][j] = Matrix[i][j];
			dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}


void PrintMatix() // Warning This Function is For Debug
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

void GetSquare()
{
	for (int i = 2; i <= Row; i++)
	{
		for (int j = 2; j <= Col; j++)
		{
			int Base = dp[i][j] - dp[i - 2][j] - dp[i][j - 2] + dp[i - 2][j - 2];
			res = max(Base, res);
			int a1 = Base - Matrix[i][j] + Matrix[i - 2][j];
			res = max(res, a1);
			int a2 = Base - Matrix[i][j - 1] + Matrix[i - 2][j - 1];
			res = max(res, a2);
			int a3 = Base - Matrix[i - 1][j] + Matrix[i-1][j - 2];
			res = max(res, a3);
			int a4 = Base - Matrix[i][j] + Matrix[i][j - 2];
			res = max(res, a4);
			/*cout << i << " " << j << endl;
			cout << a1 << " " << a2 << " " << a3 << " " << a4 <<  endl;
			cout << res << endl;*/
		}
	}
	
}

void GetVertical()
{

	for (int i = 3; i <= Row; i++)
	{
		for (int j = 2; j <= Col; j++)
		{
			int Base = dp[i][j] - dp[i][j - 2] - dp[i - 3][j] + dp[i - 3][j - 2];

			int a1 = Base - Matrix[i][j] - Matrix[i - 2][j];
			res = max(res, a1);
			int a2 = Base - Matrix[i][j - 1] - Matrix[i - 2][j - 1];
			res = max(res, a2);
			int a3 = Base - Matrix[i-1][j] - Matrix[i-2][j];
			res = max(res, a3);
			int a4 = Base - Matrix[i - 1][j - 1] - Matrix[i - 2][j - 1];
			res = max(res, a4);
			int a5 = Base - Matrix[i][j] - Matrix[i - 1][j];
			res = max(res, a5);
			int a6 = Base - Matrix[i][j - 1] - Matrix[i - 1][j - 1];
			res = max(res, a6);
			
			/*cout << i << " " << j << endl;
			cout << Base << " " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
			cout << res << endl;*/

		}
	}	
}


void GetLying()
{
	for (int i = 2; i <= Row; i++)
	{
		for (int j = 3; j <= Col; j++)
		{
			int Base = dp[i][j] - dp[i-2][j] - dp[i][j-3] + dp[i - 2][j - 3];
			int a1 = Base - Matrix[i - 1][j - 2] - Matrix[i - 1][j];
			res = max(res, a1);
			int a2 = Base - Matrix[i][j] - Matrix[i][j-2];
			res = max(res, a2);
			int a3 = Base - Matrix[i-1][j-1] - Matrix[i-1][j];
			res = max(res, a3);
			int a4 = Base - Matrix[i-1][j-2] - Matrix[i-1][j-1];
			res = max(res, a4);
			int a5 = Base - Matrix[i][j] - Matrix[i][j-1];
			res = max(res, a5);
			int a6 = Base - Matrix[i][j-2] - Matrix[i][j-1];
			res = max(res, a6);

			//cout << i << j << endl;
			//cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
		}
	}
}

void getFourVertical()
{
	for (int i = 4; i <= Row; i++)
	{
		for (int j = 1; j <= Col; j++)
		{
			int Base = dp[i][j] - dp[i][j - 1] - dp[i - 4][j] + dp[i - 4][j - 1];
			res = max(Base, res);
		}
	}
}

void getFourLying()
{
	for (int i = 1; i <= Row; i++)
	{
		for (int j = 4; j <= Col; j++)
		{
			int Base = dp[i][j] - dp[i - 1][j] - dp[i][j - 4] + dp[i - 1][j - 4];
			res = max(Base, res);
		}
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Init();
	//PrintMatix();
	GetSquare();
	GetVertical();
	GetLying();
	getFourVertical();
	getFourLying();

	cout << res;





	return 0;
}