#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solver
{
private:
	unique_ptr<int>	N;
	vector<int> my_vec;
public:
	Solver(const int& n_input): N(make_unique<int>(n_input))
	{
		my_vec.resize(*N);
	}
	void inputAndSort() noexcept
	{
		for (int i = 0; i < *N; i++)
			cin >> my_vec[i];
		
		sort(my_vec.begin(), my_vec.end());
	}
	void show_vec() noexcept
 	{
		for (int i = 0; i < my_vec.size(); i++)
		{
			cout << my_vec[i] << endl;
		}
	}
};

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	Solver solver(N);
	solver.inputAndSort();
	solver.show_vec();	
	return (0);
}