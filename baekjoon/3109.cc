#include <bits/stdc++.h>
using namespace std;

constexpr int x_move[] = {-1, 0, 1}; // ↗ → ↘
constexpr int y_move[] = {1, 1, 1};
int Row, Col;
vector<vector<char>> matrix;

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

void input() {
    cin >> Row >> Col;
    matrix.assign(Row + 1, vector<char>(Col + 1));

    for (int i = 1; i <= Row; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= Col; j++)
            matrix[i][j] = str[j - 1];
    }
}

bool dfs(int x, int y) {

    matrix[x][y] = 'x'; // 방문 처리
	if (y == Col) return true; // 목적지 도착

    for (int i = 0; i < 3; i++) {
        int nx = x + x_move[i], ny = y + y_move[i];

        if (nx >= 1 && nx <= Row && ny <= Col && matrix[nx][ny] != 'x') {
            if (dfs(nx, ny)) return true;
        }
    }
    return false;
}

void solve() {
    input();
    int res = 0;
    
    for (int i = 1; i <= Row; i++) {
        if (dfs(i, 1)) res++;

		showMatrix(matrix);
		cout << endl;
    }
    
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
