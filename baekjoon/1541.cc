#include <bits/stdc++.h>
using namespace std;

string line;
vector<string> expressions;

void showVec()
{
	for(const auto&ele: expressions)
		cout << ele << endl;
}

void splitLine()
{
	cin >> line;
	stringstream ss(line);

	string tmp{};
	while (getline(ss, tmp,'-'))
	{
		expressions.emplace_back(tmp);
	}
}

int parsing(string& str)
{
	int res{};
	stringstream ss(str);
	string tmp{};
	while (getline(ss, tmp, '+'))
	{
		res += stoi(tmp);
	}
	return res;
}

void solve()
{
	splitLine();
	int res{};
	for (int i = 0; i < expressions.size(); i++)
	{
		if (i == 0)
			res = parsing(expressions[i]);
		else
			res -= parsing(expressions[i]);
	}
	cout << res;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cin.tie(0);

	solve();

	return 0;
}