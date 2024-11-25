#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<long,long>;

ll res = LLONG_MIN;
int N;
vector<ll> number, add_num;
vector<pll> min_num;


ostream& operator << (ostream& out, const pair<long, long>& p)
{
	out << p.first << " " << p.second;
	return out;
}

void show_vec(const auto str, const auto container)
{
	cout << str << " ";
	for(auto&ele: container)
		cout << ele << " ";
	cout << endl;
}

void input() 
{
	cin >> N;
	ll input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		number.emplace_back(input);
	}	
}

void set_vectors() noexcept
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			ll num1 = number[i];
			ll num2 = number[j];

			add_num.emplace_back(num1 + num2);
			min_num.emplace_back(make_pair(num1 - num2, j));
			min_num.emplace_back(make_pair(num2 - num1, i));
		}
	}
	sort(min_num.begin(), min_num.end());
}

void get_result() noexcept
{
    for (size_t i = 0; i < add_num.size(); i++) {
        ll num = add_num[i];

        auto iter = upper_bound(
            min_num.begin(), 
            min_num.end(), 
            make_pair(num, LLONG_MAX), 
            [](const pll& a, const pll& b) {
                return a.first < b.first; 
            }
        );

        if (iter != min_num.begin()) {
            --iter; 
            if (iter->first == num) {
                res = max(res, num + number[iter->second]); 
            }
        }
    }
}
int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	set_vectors();
	// show_vec("This is sum : ", add_num);
	// show_vec("This is min : ", min_num);

	get_result();
	cout << res;
	return (0);
}