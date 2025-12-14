#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
deque<int> myDq;
void show_dq() noexcept
{
	for(const auto&ele: myDq)
		cout << ele << " ";
	cout << endl;
}

void input() noexcept
{
	cin >> N;
	myDq.resize(N+1, 0);
	iota(myDq.begin(), myDq.end(), 0);
	//reverse(myDq.begin(), myDq.end());
	myDq.pop_front();
	// show_dq();
}

void solve() noexcept
{
	while (myDq.size() != 1)
	{
		myDq.pop_front();
		int num = myDq[0];
		myDq.pop_front();
		myDq.push_back(num);
	}
	cout << myDq[0];
}




int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	solve();
	return (0);
}