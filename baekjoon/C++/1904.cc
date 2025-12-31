/**
 * 0이 쓰여진 낱장의 타일을 붙인다
 * 00
 * 
 * 1하나만이랑 or 00dmfh skarp ehldjTek.
 * 
 * N이 1일 때는 -> 1만 가능
 * N이 2일 때는 -> 00, 11
 * 
 * 만들 수 있는 가짓수는 어떻게 되느냐? 
 * dp[0] = 1
 * dp[1] -> 하나로 만들 수 있는 가짓 수
 *      1 => 1
 * dp[2] -> 2개로 만들 수 있는 가짓 수
 *      11 => dp[1]
 *      00 -> dp[0]
 * dp[3]
 *      111 -> dp[n] = dp[n-1] + dp[n-2];
 *      001
 *      100
 * 
 * dp[4]
 *      1111
 *      0011
 *      1001
 *      1100
 *      0000
 *     
 */


#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define DIV 15746
using namespace std;
using ull = unsigned long long;

vector<ull> dp;
int N;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp.assign(N+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }

    cout << dp[N] << endl;

    return (0);
}