#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int N, L;
vector<ll> my_vec;
vector<ll> res;
deque<int> my_deq;

void show_vec(const auto& container) noexcept
{
    for (int i = 1; i <= N; i++)
    {
        cout << container[i] << " ";
    }
    cout << endl;
}

void init_res()
{
	ll num = my_vec[1];
	for (int i = 1; i <= L-1; i++)
	{
		num = min(num, my_vec[i]);
		res[i] = num;
	}
}


void input() noexcept
{
    cin >> N >> L;
    my_vec.resize(N + 1);
    res.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> my_vec[i];
    
	init_res();
}

void pop_deque(ll num) noexcept
{
    if (!my_deq.empty() && my_deq.front() == num) {
        my_deq.pop_front();
    }
}

void push_target(ll num) noexcept
{
    while (!my_deq.empty() && my_deq.back() > num) {
        my_deq.pop_back();
    }
    my_deq.push_back(num);
}

void set_result() noexcept
{
    for (int i = 1; i <= L; ++i)
        push_target(my_vec[i]);

    res[L] = my_deq.front();

    int tail = 1;
    int head = L;

    while (head < N) {
        ++head;
        push_target(my_vec[head]);  
        pop_deque(my_vec[tail]);    
        ++tail;

        res[head] = my_deq.front();
    }
}

void solve() noexcept
{
    input();
    set_result();
    show_vec(res);
}

int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return (0);
}
