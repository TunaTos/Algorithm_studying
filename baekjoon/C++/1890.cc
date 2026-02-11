#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;

int N;
vector<vector<ll>> matrix, dp;
const vector<int> x_move{1,0}, y_move{0,1};

// Function for Debug
template<typename M>
void show_matrix(const M& m) {
    for (int i = 1; i <= N; ++i) {
        for (int j =1; j <= N; ++j) {
            cout << m[i][j] << " ";
        }cout << endl;
    }
}

void input() noexcept {
    cin >> N;

    // init container
    matrix.assign(N+1, vector<ll>(N+1, 0));
    dp.assign(N+1, vector<ll>(N+1, -1));  

    for (int i = 1; i <= N; ++i) 
        for (int j = 1; j <= N; ++j)
            cin >> matrix[i][j];

    dp[N][N] = 1;
}

bool in_the_matrix(int xpos, int ypos) {
    return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
}

ll dfs(int xpos, int ypos) {
    if (dp[xpos][ypos] != -1) return dp[xpos][ypos];
    
    ll sum = 0;

    for (int i = 0; i < 2; ++i) {
        if (matrix[xpos][ypos] != 0) {
            int x = xpos + matrix[xpos][ypos] * x_move[i];
            int y = ypos + matrix[xpos][ypos] * y_move[i];
            
            if (!in_the_matrix(x,y)) continue;
            sum += dfs(x,y);
        }
    }
    dp[xpos][ypos] = sum;
    return dp[xpos][ypos];
}


void solve() {
    input();
    // show_matrix(matrix);
    dfs(1,1);
    // show_matrix(dp);
    cout << dp[1][1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return (0);
}