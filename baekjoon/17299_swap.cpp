#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int Tcase;
string str;

ull getNumberString(const string& str) noexcept
{
	ull res = 0;
	for (int i = 0; i < str.length(); i++)
	{
		res = (res * 10) + (str[i] - '0');
	}
	//cout << res;
	return res;
}

ull get_result_one() noexcept
{
	assert(str.length() % 2 == 0);
	string str1 = string(str.begin(),str.begin() + str.length() / 2);
	string str2 = string(str.begin() +str.length() / 2 , str.end());
	// cout << str1 << endl;
	// cout << str2;

	return getNumberString(str1) + getNumberString(str2);	
}

ull get_result_two() noexcept
{
	assert(str.length() % 2 == 1);
	
	string str1 = string(str.begin(),str.begin() + str.length() / 2);
	string str2 = string(str.begin() +str.length() / 2 , str.end());
	// cout << str1 << endl;
	// cout << str2;
	return getNumberString(str1) + getNumberString(str2);
}

ull get_result_three() noexcept
{
	assert(str.length() % 2 == 1);
	
	string str1 = string(str.begin(),str.begin() + str.length() / 2 + 1);
	string str2 = string(str.begin() +str.length() / 2 + 1 , str.end());
	// cout << str1 << endl;
	// cout << str2;
	return getNumberString(str1) + getNumberString(str2);
}

void solve() noexcept
{
	for (int i = 1; i <= Tcase; i++)
	{
		cin >> str;
		cout << "#" << i << " ";
		if (str.length()==1)
			cout << getNumberString(str) << endl;
		
		else if (str.length() % 2 == 0)
			cout << get_result_one() << endl;
		else
		{
			ull res1 = get_result_two();
			ull res2 = get_result_three();

			if(res1 <= res2)
				cout << res1 << endl;
			else
				cout << res2 << endl;
		}
	}
	

}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> Tcase;
	solve();
	// str = "10004";
	// getNumberString("004");
	// get_result_three();
	return (0);
}