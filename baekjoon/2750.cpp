#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solver
{
private:
	int N;
	vector<int> my_vec;

public:
	Solver(istream& in) 
	{
		in >> N;
		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			my_vec.emplace_back(tmp);
		}
	}

	void get_result()
	{
		sort(my_vec.begin(), my_vec.end());
		for(const auto&ele: my_vec)
			cout << ele << endl;
	}
	
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto sol = Solver(cin);
	sol.get_result();
	return (0);

}