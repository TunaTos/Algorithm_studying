#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solver
{
private:
	int N, K;
	priority_queue<int, vector<int>, greater<int>> pq;

public:
	Solver(istream& in)  {
		in >> N >> K;
		int input;
		for (int i = 0; i < N; i++)
		{
			cin >> input;
			pq.emplace(input);
		}
	}
	
	void show_pq() 
	{
		// Function For Debugging
		auto tmp_pq = pq;
		while (!tmp_pq.empty())	
		{
			cout << tmp_pq.top() << " ";
			tmp_pq.pop();
		}
		cout << endl;
	}

	void get_result()
	{
		for (int i = 0; i < K; i++)
		{
			if (i == K-1)
				cout << pq.top();
			pq.pop();
		}
		
	}
};


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto solver = Solver(cin);
	solver.get_result();

	return (0);
}