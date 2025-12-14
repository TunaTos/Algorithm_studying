#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int N; // N >= 1 && N <= 100
vector<int> nums(100+1, 0);

/**
 * 2 + 2
 * 4 + 2
 * 7 + 3
 * 10 + 3
 * 14 + 4
 * 19 + 5
 * 24 + 5
 * 30 + 6
 * 
 * 증가하는 수가 짝수인경우 -> 그대로 더함
 * 증가하는 수가 홀수인 경우 -> 그대로 더함 -> 그대로 더함 + 1
 */

void solve() {	
	
	
	
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int add_num = 2;
	int i = 0;

	while (i <= 100) {
		if (add_num % 2 == 0) {
			nums[i + 1] = nums[i] + add_num;
			nums[i+2] = nums[i+1] + add_num;
			i = i + 2;
			add_num = add_num + 1;
		}

		if (add_num % 2 == 1) {
			nums[i+1] = nums[i] + add_num;
			nums[i+2] = nums[i+1] + add_num;
			nums[i+3] = nums[i+2] + add_num  + 1;
			i = i + 3;
			add_num = add_num + 2;
		}
	}

	cout << nums[N];
	
	return (0);
}