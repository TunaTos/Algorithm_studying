#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LEN 100001
using namespace std;

int Tcase, Range, Len, s_pos, e_pos;
unsigned long long arr[MAX_LEN], dp[MAX_LEN], Limit;
long long Sum;
void Init()
{
	cin >> Len >> Range >> Limit;

	for (unsigned int i = 1; i <= Len; i++)
	{
		cin >> arr[i]; dp[i] = arr[i]; dp[i] += dp[i - 1];
	}
	s_pos = 1; e_pos = Range;
}

int NextPos(int& pos)
{
	if (pos == Len)
		return 1;
	else
		return pos+1;
}


int getResult()
{
	int res = 0;

	for (int i = 1; i <= Len; i++)
	{
		if (s_pos <= e_pos)
		{
			Sum = dp[e_pos] - dp[s_pos - 1];
			//cout << Sum << " " << s_pos << " " << e_pos << endl;
			if (Sum < Limit)
				res++;
		}

		else if (e_pos < s_pos)
		{
			Sum = Sum + arr[e_pos] - arr[s_pos - 1];
			//cout << Sum << endl;


			if (Sum < Limit)
				res++;
		}

		s_pos = NextPos(s_pos); e_pos = NextPos(e_pos);
	}

	return res;
}

void Debug()
{
	cout << "Dp is : " << '\n';
	for (int i = 1; i <= Len; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << "arr is : " << '\n';
	for (int i = 1; i <= Len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> Tcase;

	for (int i = 0; i < Tcase; i++)
	{
		Init();
		//Debug();
		if (Len == Range)
		{
			if (dp[Range] < Limit)
			{
				cout << 1 << '\n';
				continue;
			}
			else
			{
				cout << 0 << '\n';
				continue;
			}

			
			
		}
		cout << getResult() << "\n";
	}

	return 0;
}