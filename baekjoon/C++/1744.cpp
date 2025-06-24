#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, res;
priority_queue<int> plusNumbers, zeroNumbers;
priority_queue<int, vector<int>, greater<int>> minusNumbers;


void showPq(auto& q)
{
	cout << "==================================" << endl;
	auto tmp = q;
	while (!tmp.empty())
	{
		int num = tmp.top();
		cout << num << endl;
		tmp.pop();
	}
}

void input()
{
	cin >> N;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input > 0) plusNumbers.emplace(input);
		if (input == 0 ) zeroNumbers.emplace(input);
		if (input < 0) minusNumbers.emplace(input);
	}
}

void trimming(auto& q)
{
	while (q.size() >= 2)
	{
		int first = q.top();
		q.pop();
		int second = q.top();
		q.pop();
		int tmp = max(first*second, first + second);
		res += tmp;
	}
}


void checkLast()
{
	if (!zeroNumbers.empty()) // 0이 하나라도 있는 경우
	{
		if (!plusNumbers.empty())
			res += plusNumbers.top();
	}
	else // 0이 아무것도 없는 경우
	{
		int num1{}, num2{};
		if (!minusNumbers.empty())
			num1 = minusNumbers.top();
		if (!plusNumbers.empty())
			num2 = plusNumbers.top();
		res += (num1 + num2);
	}
}

void solve()
{
	input();
	trimming(zeroNumbers);
	trimming(plusNumbers);
	trimming(minusNumbers);
	checkLast();
	cout << res << endl;
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}