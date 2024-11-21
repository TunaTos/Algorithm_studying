// Algorithm : meet in the middle
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;

int N, leftLen, rightLen;
ll target, res;
vector<ll> left_sum, right_sum;

template<typename T>
void show_vector(const T& t) noexcept
{
	for(auto&ele: t)
		cout << ele << " ";
	cout << endl;
}

void input() noexcept
{
	cin >> N >> target;
	leftLen = N / 2;
	rightLen = N - leftLen;
}

vector<ll> make_sum(int len) noexcept
{
	ll input;
	vector<ll> numbers;
	vector<ll> res;
	vector<int> bits(len, 0);

	for (int i = 0; i < len; i++)
	{
		cin >> input;
		numbers.emplace_back(input);
	}
	res.push_back(0);

	// make all of combination
	for (int i = 1; i <= len; i++)
	{
		std::fill(bits.begin(), bits.begin() + i, 1);
		// show_vector(bits);

		do
		{
			ll res_input = 0;
			for(int i =0; i < len; ++i)
			{
				if (bits[i])
					res_input += numbers[i];
			}
			res.emplace_back(res_input);
		} while (prev_permutation(bits.begin(), bits.end()));
	
		//std::fill(bits.begin(), bits.end(), 0); // reset 
	}
	// cout << "This is res";
	// show_vector(res);
	
	return res;
}


void solve() noexcept
{
	assert(is_sorted(left_sum.begin(), left_sum.end()));
	assert(is_sorted(right_sum.begin(), right_sum.end()));

	for (int i = 0; i < left_sum.size(); i++)
	{
		ll val = target - left_sum[i];
		auto lower_iter = lower_bound(right_sum.begin(), right_sum.end(), val);
		auto upper_iter = upper_bound(right_sum.begin(), right_sum.end(), val);
		res += std::distance(lower_iter, upper_iter);
		
	}
}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	left_sum = make_sum(leftLen);
	right_sum = make_sum(rightLen);
	sort(left_sum.begin(), left_sum.end());
	sort(right_sum.begin(), right_sum.end());
	// show_vector(left_sum);
	// show_vector(right_sum);

	solve();
	if (target == 0)
		--res;
	cout << res << endl;

	

	return (0);
}