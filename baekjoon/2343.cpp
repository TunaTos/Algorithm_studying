#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> number;

void input()
{
	cin >> N >> M;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		number.emplace_back(input);
	}
}

bool isPossible(long long num)
{
	// num : 블루레이에 들어갈 수 있는 크기
	int tmp{1};
	long long bucket{0};

	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] > num)
			return false;
		if (bucket + number[i] < num)
			bucket += number[i];
		else if (bucket + number[i] == num)
		{
			bucket = 0;
			if (i != number.size() - 1)
				++tmp;
		}
		else
		{
			bucket = number[i];
			++tmp;
		}
		if (tmp > M)
			return false;
	}
	// cout << tmp;
	return true;
}

void parametricSearch()
{
	long long left = 1, right = 1e9;
	long long mid{0};
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (isPossible(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();	
	parametricSearch();
	return 0;
}