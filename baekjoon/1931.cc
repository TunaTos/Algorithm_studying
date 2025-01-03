#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class TimeLine
{
private:
	int start, end;
public:
	TimeLine(const int& s_input, const int& e_input):
		start(s_input), end(e_input) {};
	int getStart()  const {return this->start;} 
	int getEnd() const {return this->end;}
	bool operator < (const TimeLine& other) const
	{
		if (this->end == other.end)
			return this->start < other.start;
		else
			return this->end < other.end;
	}
	friend ostream& operator<<(ostream& out, const TimeLine& t)
	{
		out << t.start << ' ' << t.end;
		return out;
	}
};


std::vector<TimeLine> vec;
int N;


template<typename T>
void show_vec(const T& t)
{
	for(const auto&ele: t)
		cout << ele << endl;
}

void inputAndSort()
{
	int s_input, e_input;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> s_input >> e_input;
		vec.emplace_back(TimeLine{s_input, e_input});
	}
	sort(vec.begin(), vec.end());
}

void getResult()
{
	int res{0};
	int stand{0};
	for(const auto& time: vec)
	{
		int start = time.getStart();
		int end = time.getEnd();
		
		if (stand <= start)
		{
			++res;
			stand = end;
		}
	}
	cout << res;
}

void solve()
{
	inputAndSort();
	// show_vec(vec);
	getResult();
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return (0);
}