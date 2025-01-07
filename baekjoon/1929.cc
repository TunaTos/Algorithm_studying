#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Eratos
{
private:
	int M, N;
	vector<bool> eratos;
	
public:
	Eratos() = default;
	Eratos(const int& m_input, const int& n_input):
		M(m_input), N(n_input), eratos(N+1, true) {}
	
	void setEratos()
	{
		eratos[1] = false;
		for (int i = 2; i <= sqrt(N); i++)
		{
			for (int j = i*2; j <= N; j += i)
			{
				eratos[j] = false;
			}
		}
	}
	void getResult()
	{
		for (int i = M; i <= N; i++)
		{
			if (eratos[i])
				cout << i << endl;
		}
	}
};

void solve()
{
	int M, N;
	cin >> M >> N;
	Eratos E(M,N);
	E.setEratos();
	E.getResult();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}