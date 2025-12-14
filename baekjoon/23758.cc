/**
 * N개의 수 중 0이 등장할 떄까지 반복
 * 
 * 중앙값을 2로 나누고 너머지는 버린다
 * 
 * 오름차순으로 정렬할 때 [N+1 / 2] 
 * 
 * N은 10 ^ 6
 * 각자의 수는 10 ^ 9 (1 <= x <= 10 ^ 9)
 * 
 * 언제 되는가? 
 *      중앙값이 1인 경우에 정답이 나온다
 * 
 * 부르트포스로 가능한가?
 *      불가능하다 -> 연산마다 정렬해야하는데?
 * 규칙을 찾아볼까?
 *      절반 나눈거 오른쪽은 신경쓰지 않아도 됨
 *      하나의 수를 0으로 만드는 연산의 수 : [log(2) N] + 1
 *      맨 앞의 경우가 1인 경우는
 *          (2 <= i <= [N+1 / 2]) 
 *              각 항마다 log(2) N + 1
 *      맨 앞의 경우가 1이 아닌 경우는?
 *          맨 앞을 1로 만드는 경우의 수는 뭐지?
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl '\n'
using namespace std;
using ull = unsigned long long;
ull N, res;
vector<ull> nums;


template<typename container>
void show_vec(const container& con) {
    for (int i = 1; i <= N; i++)
    {
        cout << con[i] << " ";
    }cout << endl;
}


void solve() {
    for (int i = (N+1) / 2; i >= 1; --i)
        res += (ull) abs(log2(nums[i]));
    
    cout << ++res << endl;
    
}
void input() noexcept {
    cin >> N;
    nums.assign(N+1, 0);

    for (int i = 1; i <= N; i++)
        cin >> nums[i];
    
        
    sort(nums.begin() + 1, nums.end());
        
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    input();
    solve();
    
    return (0);
}