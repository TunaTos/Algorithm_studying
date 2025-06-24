#include <bits/stdc++.h>
using namespace std;

template<typename container>
void showvector(const container& c)
{
	for(const auto& elem: c)
		cout << elem;
}

class Solver
{
private:
	int N, M;
	vector<int> visited;
	vector<char> chars;
	const set<char> vowels {'a','e','i','o','u'};
public:
	Solver(const int& n_input, const int& m_input) : 
		N(n_input), M(m_input), visited(M,false), chars(M) 
	{
		std::fill(visited.begin(), visited.begin() + N, 1);
		for (int i = 0; i < M; i++)
			cin >> chars[i];
		sort(chars.begin(), chars.end());
	}
	
	void combination()
	{
		do
		{
			int vowel_num{0}, consonent_num{0};
			vector<char> vec;
			for (int i = 0; i < M; i++)
			{
				if (visited[i] == 1)
				{
					vec.push_back(chars[i]);
					if (vowels.count(chars[i]))
						vowel_num++;
					else
						consonent_num++;
				}
			}
			if (vowel_num != 0 && consonent_num >= 2)
			{
				showvector(vec);
				std::cout << '\n';
			}
		} while (std::prev_permutation(visited.begin(), visited.end()));
	}

};

void solve()
{
	int N, M;
	cin >> N >> M;
	Solver S(N, M);
	S.combination();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}