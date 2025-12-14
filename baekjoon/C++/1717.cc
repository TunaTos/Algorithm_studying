#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<typename T>
void showVector(const T& container)
{
	for(const auto& ele: container)
		cout << ele << " ";
	cout << endl;
}

class Solver
{
private:
	int N, M;
	vector<int> parents;
	vector<int> weights;
public:
	Solver(const int& n_input, const int& m_input):
		N(n_input), M(m_input), parents(N+1), weights(N+1, 1) {
			std::iota(parents.begin(), parents.end(), 0);
		}
	vector<int> getParents() { return this->parents; }
	vector<int> getWeights() { return this->weights; }
	int Find(const int& a)
	{
		if (parents[a] == a)
			return a;
		else
			return (parents[a] = Find(parents[a]));
	}
	void Union(int a, int b)
	{
		a = Find(a); b = Find(b);
		if (a == b)
			return;
		
		else if (weights[a] <= weights[b])
		{
			parents[a] = b;
			weights[b] += weights[a];
		}
		else
		{
			parents[b] = a;
			weights[a] += weights[b];
		}
	}
	void isSameGroup(int a, int b)
	{
		if (Find(a) == Find(b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
};

void runTestCase(Solver& S)
{
	int flag, a, b;
	cin >> flag >> a >> b;

	if (flag == 0)
		S.Union(a,b);
	else
		S.isSameGroup(a,b);
}

void Solve()
{
	int n, m;
	cin >> n >> m;
	
	auto S = Solver{n,m};
	for (int i = 0; i < m; i++)
		runTestCase(S);

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solve();

	return 0;
}