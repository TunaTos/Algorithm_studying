/**
 * 선택을 안한다
 *      -> dp[i-1][j];
 *      -> dp[i][j-k] + cost[k];
 * 
 * 최소 값을 구하기 위해서는
 *      어떤 파일의 최소값 + 어떤 파일의 최소 값
 * 최적의 값을 구하기 위해서는, 이전의 최적의 값으로 구해진다
 *      최적 부분 구조
 * 
 * 
 * dp[a][b] -> a에서 b까지를 선택했을 때의 최소 파일 구조
 * dp[1][1] = 40
 * dp[1][2]
 *      dp[1][1] + dp[2][2] 
 * dp[1][3]
 *      dp[1][2] + dp[3][3]
 *      dp[]
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int tcase;
int n;
vector<vector<ull>> dp; // (i,j) i랑 j를 선택했을 때의 파일 생성의 최소값
vector<ull> files;
vector<ull> f_sum;



template<typename T>
void show_vector(const T& t) {
    for (int i = 0; i < t.size(); ++i) {
        cout << t[i] << " ";
    }cout << endl;
}

void show_matrix() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }
}

void input() {
    cin >> n;
    dp.assign(n+1, vector<ull>(n+1, ULLONG_MAX));
    
    for (int i = 1; i <= n; ++i)
        dp[i][i] = 0;

    files.assign(n+1, 0);
    f_sum.assign(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> files[i];
        f_sum[i] = files[i];
        f_sum[i] += f_sum[i-1];
    }
}



ull dfs(int i, int j) {
    if (dp[i][j] != ULLONG_MAX) return dp[i][j];

    for (int k = i; k < j; ++k) {
        ull num1 = dfs(i,k);
        ull num2 = dfs(k + 1, j);
        
        dp[i][j] = min(dp[i][j], num1 + num2 + f_sum[j] - f_sum[i-1]);
    }

    return dp[i][j];
}





int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> tcase;
    for (int i = 0; i < tcase; i++)
    {
        input();
        // show_vector(files);
        dfs(1,n);
        cout << dp[1][n] << endl;
    }
    

    return (0);
}