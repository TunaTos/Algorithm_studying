#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class AlpaNum
{
public:
	int a_num, c_num, g_num, t_num;
	AlpaNum() {
		a_num = 0;
		c_num = 0;
		g_num = 0;
		t_num = 0;
	}
	
	AlpaNum operator += (AlpaNum& other) noexcept
	{
		this->a_num += other.a_num;
		this->c_num += other.c_num;
		this->g_num += other.g_num;
		this->t_num += other.t_num;
		return *this;
	}

	AlpaNum operator - (AlpaNum& other) noexcept
	{
		AlpaNum result;
		result.a_num = this->a_num - other.a_num;
		result.c_num = this->c_num - other.c_num;
		result.g_num = this->g_num - other.g_num;
		result.t_num = this->t_num - other.t_num;
		return result;
	}


	friend ostream& operator << (ostream& out, const AlpaNum& a) noexcept
	{
		out << a.a_num << " " << a.c_num << " " << a.g_num << " " << a.t_num;
		return out;
	}
};

int Len, subLen, res;
string str;
AlpaNum stand{};
vector<AlpaNum> dp;

void show_vec() noexcept
{
	for(auto&ele: dp)
		cout << ele << endl;
}

void input() noexcept
{
	cin >> Len >> subLen;
	cin >> str;
	cin >> stand.a_num;
	cin >> stand.c_num;
	cin >> stand.g_num;
	cin >> stand.t_num;
	dp.resize(Len+1);
}

void set_dp() noexcept
{
	for (int i = 0; i < Len; i++)
	{
		if (str[i] == 'A')
			dp[i+1].a_num++;
		if (str[i] == 'C')
			dp[i+1].c_num++;
		if (str[i] == 'G')
			dp[i+1].g_num++;
		if (str[i] == 'T')
			dp[i+1].t_num++;
		dp[i+1] += dp[i];
	}
}

long long get_result() noexcept
{
	long long res{0};
	for (int i = subLen; i <= Len; i++)
	{
		int rear = i - subLen;
		auto a = dp[i] - dp[rear];
		if (a.a_num >= stand.a_num && a.c_num >= stand.c_num &&
			a.g_num >= stand.g_num && a.t_num >= stand.t_num 	)
			++res;
	}
	return res;
}


void solve() noexcept
{
	input();
	set_dp();
	// show_vec();
	cout << get_result();

}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}