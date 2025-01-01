#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int K;
class Coins
{
private:
	int N;
	priority_queue<int> pq; // pq is max_heap

public:
	Coins(const int& n_input): N(n_input)
	{
		int input;
		for (int i = 0; i < N; i++)
		{
			cin >> input;
			if (input <= K)
				pq.emplace(input);			
		}
	}
	void showPq()
	{
		auto dummy = this->pq;
		while (!dummy.empty())
		{
			cout << dummy.top() << endl;
			dummy.pop();
		}
	}
	int getResult()
	{
		int res{};
		
		while (!pq.empty() && K != 0)
		{
			auto tmp = pq.top();
			res += (K / tmp);			
			K %= tmp;
			pq.pop();
		}
		return res;
	}
};


void solve()
{
	int n;
	cin >> n >> K;
	Coins C(n);
	
	//C.showPq();
	std::cout << C.getResult();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	
	return (0);
}