#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int,int>;


int t_index, Len, target, res = 1;
vector<int> my_vec, left_num, right_num;
vector<pii> left_dp, right_dp; // {less, more}


// void show_vector(const auto& fmt, const auto& con) noexcept
// {
// 	cout << fmt << " ";
// 	for(auto&ele: con)
// 		cout << ele <<  " ";
// 	cout << endl;
// }

void input() noexcept
{
	int input;
	cin >> Len >> target;
	for (int i = 0; i < Len; i++)
	{
		cin >> input;
		if (input == target)
			t_index = i;
		my_vec.push_back(input);		
	}
	// cout << "This is index : " << t_index << endl;
}

void set_dp(const vector<int>& num, vector<pii>& dp) noexcept
{
	dp.assign(num.size(), make_pair(0,0));
	for (int i = 0; i < num.size(); i++)
	{
		if (i > 0)
		{
			dp[i].first = dp[i-1].first;
			dp[i].second = dp[i-1].second;
		}
		if (num[i] < target)
			++dp[i].first;
		else
			++dp[i].second;
	}		
}

void edge_case() noexcept
{
	assert(t_index == 0 || t_index == my_vec.size() -1);
	if (t_index == 0)
		left_num = vector<int>{my_vec.begin() + 1, my_vec.end()};
	
	if (t_index == my_vec.size() - 1)
		left_num = vector<int>{my_vec.rbegin() + 1, my_vec.rend()};

	set_dp(left_num, left_dp);

	// for(auto&ele: left_dp)
	// {
	// 	cout << ele.first << " " << ele.second << " / ";
	// }cout << endl;
	
	res += std::count_if(left_dp.begin(), left_dp.end(), [](pair<int,int> a) {
		return a.first == a.second;
	});
	//cout << res;
}

void normal_case() noexcept
{
	left_num = vector<int>{my_vec.begin(), my_vec.begin() + t_index};
	std::reverse(left_num.begin(), left_num.end());
	right_num = vector<int>{my_vec.begin() + t_index + 1, my_vec.end()};
	set_dp(left_num, left_dp);
	set_dp(right_num, right_dp);

	// for(auto&ele: left_dp)
	// {
	// 	cout << ele.first << " " << ele.second << " / ";
	// }cout << endl;

	// cout << "===========================" << endl;
	// for(auto&ele: right_dp)
	// {
	// 	cout << ele.first << " " << ele.second << " / ";
	// }cout << endl;

	auto val1 = std::count_if(left_dp.begin(), left_dp.end(), [](pair<int,int> a) {
		return a.first == a.second;
	});
	auto val2 = std::count_if(right_dp.begin(), right_dp.end(), [](pair<int,int> a) {
		return a.first == a.second;
	});
	res = res + val1 + val2;

	for (int i = 0; i < left_dp.size(); i++)
	{
		if ((i + 1) % 2 == 0) // 짝수 인덱스인 경우
		{
			for (int j = 1; j < right_dp.size(); j = j + 2)
			{
				if ((left_dp[i].first + right_dp[j].first) == (left_dp[i].second + right_dp[j].second))
					++res;
			}
		}
		else
		{
			for (int j = 0; j < right_dp.size(); j = j + 2)
			{
				if ((left_dp[i].first + right_dp[j].first) == (left_dp[i].second + right_dp[j].second))
					++res;
			}
		}
	}
}


void solve() noexcept
{
	input();
	if (t_index == 0 || t_index == my_vec.size() - 1)
	{
		edge_case();
	}
	else
	{
		normal_case();
	}
	cout << res << endl;
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//input();
	//show_vector("This is my_vec", my_vec);
	solve();
	return (0);
}