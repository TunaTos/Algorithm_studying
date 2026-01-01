/**
 * 어제 받은 떡 + 그제 받은 떡
 * 
 * 오늘 호랑이에게 몇개의 떡을 주었는가?
 * 며칠이 지났는가?
 * 
 * D째 날에 준 떡의 개수 K
 * 
 * 출력)
 * 처음 만난 날 떡의 개수 A 다음날 B
 * 
 * A와 B가 1개 이상 있는 경우는 아무거나 출력 ㄱㄱ
 * 
 * 1) a -> (1,0)
 * 2) a b -> (1,1) 
 * 3) aa b -> (2,1)
 * 4) aaa bb -> (3,2)
 * 5) aaaaa bbb -> (5,3)
 * 6) aaaaaaaa bbbbb -> (8,5)
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

int D;
ull a,b,K;

vector<pair<int,int>> dp;

void solve() 
{
    dp.assign(D+1, make_pair(0,0));

    dp[1] = make_pair(1,0);
    dp[2] = make_pair(0,1);

    for (int i = 3; i <= D; ++i) {
        dp[i] = make_pair(dp[i-1].first + dp[i-2].first,
            dp[i-1].second + dp[i-2].second
        );
    }

    int n2 = dp[D].second;
    int n1 = dp[D].first;
    int k1, k2;


    //cout << n1 << " " << n2 << endl;
    for (k1 = 1; n1 * k1 < K; ++k1) {
        for (k2 = k1; n1 * k1 + n2 * k2 <= K; ++k2) {
            //cout << n1 * k1 << " " << n2 * k2 << endl;
            if (n1 * k1 + n2 * k2 == K) {
                cout << k1 << endl << k2;
                return ;
            }
        }
    }


}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> D >> K;
    solve();

    return (0);
}