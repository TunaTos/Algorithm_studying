#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solver
{
private:
	int N;
	vector<bool> Eratos;

public:
	Solver() = default;
	Solver(const int& n_input): N(n_input), Eratos(2000000, true) {}

	
	void debug(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			if (Eratos[i])
				cout << i << " ";
		}
		cout << endl;
	}
	void setEratos()
	{
		Eratos[0] = false;
		Eratos[1] = false;
		for (int i = 2; i <= sqrt(2000000); i++)
		{
			if (Eratos[i])
			{
				for (int j = i * 2; j <= 2000000; j += i)
					Eratos[j] = false;
			}
		}
	}
	bool isPelin(int num)
	{
		string s = to_string(num);
		if (s.size() == 1)
			return true;
		
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
				return false;
		}
		return true;
	}

	void getResult()
	{
		for (int i = N; ; i++)
		{
			if (Eratos[i] && isPelin(i))
			{
				cout << i;
				return;
			}
		}
	}
};




void solve()
{
	int N;
	cin >> N;
	auto S = Solver{N};
	S.setEratos();
	S.getResult();
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}