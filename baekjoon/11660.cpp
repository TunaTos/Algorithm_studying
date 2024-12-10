#include <bits/stdc++.h>
#define MAX_LEN 1025
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int Len, Tcase;
vector<vector<ull>> matrix(MAX_LEN+1, vector<ull>(MAX_LEN+1, 0));

void show_matrix()  noexcept
{
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void input() noexcept
{
	cin >> Len >> Tcase;
	
	for (int i = 1; i <= Len; i++)
	{
		for (int j = 1; j <= Len; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] = matrix[i][j] + matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
		}
	}
}

void solve() noexcept
{
	input();
	// show_matrix();
	int x1,x2,y1,y2;
	for (int i = 0; i < Tcase; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << matrix[x2][y2] - matrix[x1 -1][y2] - matrix[x2][y1 -1] + matrix[x1-1][y1-1] << endl;
	}
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}