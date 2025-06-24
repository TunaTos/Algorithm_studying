#define _CRT_SECURE_NO_WARNINIGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int Tcase;
priority_queue<int, vector<int>, greater<int>> pq;
void Debug();
void Init()
{
	cin >> Tcase;
	int input;
	for (int i = 0; i < Tcase; i++)
	{
		cin >> input;
		pq.push(input);
	}
}

int Solve()
{
	int res = 0;

	while (pq.size()>1)
	{
		int tmp = 0;

		tmp += pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();
		res += tmp;
		pq.push(tmp);
	}
	return res;

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Init();
	if (Tcase == 1)
	{
		cout << 0;
		return 0;
	}
	cout << Solve();
	









	return 0;
}


void Debug()
{
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}


}