/*
10,000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어진다. 
이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 
가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)가 주어진다. 
둘째 줄에는 수열이 주어진다. 수열의 각 원소는 공백으로 구분되어져 있으며, 10,000이하의 자연수이다.

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ull;


vector<ull> v;
vector<ull> dp;
int Len, front = 1, back = 0, res = 987654321;
ull Target;

void show_dp();
void show_v();

void Init()
{
	cin >> Len >> Target;
	v.push_back(0); 
	dp.push_back(0);

	ull input;

	for (int i = 1; i <= Len; i++)
	{
		cin >> input;
		v.push_back(input);
		dp.push_back(input);
		dp[i] += dp[i - 1];
	}

}


ull getSum(int pos1, int pos2)
{
	return dp[pos2] - dp[pos1];
}

void Solve()
{

	while (true)
	{
		int distance = front - back;
		ull Sum = dp[front] - dp[back];
		//cout << "distance " << distance << " back " << back << " front " << front << " Sum : " << Sum << " res : " << res << endl;
		
		
		if (back == front) return;
		if (front > Len) return;
		if (front == Len && back == Len) return;


		if (Sum < Target) // Sum이 Target보다 작은 경우
		{
			if (front == Len) break;			
			front++;
		}
		else if (Sum == Target)
		{
			res = min(res, distance);
			if (front == Len) break;
			front++;
		}	
		else if (Sum > Target) // Sum이 Target보다 큰 경우	
		{
			res = min(res, distance);
			back++;
		}
		
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	//show_v();
	//show_dp();
	Solve();
	if (res == 987654321)
		cout << 0;
	else
		cout << res;




	return 0;
}


void show_dp()
{
	cout << "This is dp" << endl;
	for (auto& ele : dp)
		cout << ele << " ";
	cout << endl;
}
void show_v()
{
	cout << "This is v" << endl;
	for (auto& ele : v)
		cout << ele << " ";
	cout << endl;
}