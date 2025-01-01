#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Data
{
private:
	int N;
	vector<int> number;
public:
	Data(istream& cin) 
	{
		int input;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> input;
			number.emplace_back(input);
		}
		std::sort(number.begin(), number.end());
	}
	vector<int>& getVector() 
	{
		return this->number;
	}
};

class Solver 
{
private:
	int N;

public:
	void Solve(Data& D) 
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int input;
			cin >> input;
			cout << std::binary_search(D.getVector().begin(), D.getVector().end(), input);
			cout << endl;
		}
		
	}
};


int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Data D(cin);
	Solver S{};
	S.Solve(D);
	
	return 0;
}