#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
class Party
{
public:
	vector<int> member;
	bool flag = true;

	Party() = default; 
	bool operator < (const Party& other) const {return this->member.size() < other.member.size();}
	bool operator > (const Party& other) const {return this->member.size() > other.member.size();}
};

int N, M, T, TRoot; 
vector<int> parents;
vector<int> weights;
vector<Party> party;

template<typename T>
void showVec(const T& container)
{
	for (const auto& ele: container)
		cout << ele << ' ';
	cout << endl;
}


int Find(const int& a) noexcept
{
	if (parents[a] == a) return a;
	else
		return parents[a] = Find(parents[a]);
}

void Union(int a, int b) noexcept
{
	a = Find(a), b = Find(b);

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

void handleTruth() noexcept
{
	cin >> T;
	int tmp;
	for (int i = 1; i <= T; i++)
	{
		if (i == 1)
			cin >> TRoot;
		else
		{
			cin >> tmp;
			Union(TRoot, tmp);
		}
	}
}

bool findTruthPeople(vector<int>& vec) noexcept
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (Find(vec[i]) == Find(TRoot))
			return true;
	}
	return false;
}

void unionAll(Party& p) noexcept
{
	p.flag = false;

	for (auto ele: p.member)
		Union(TRoot, ele);
}

void initParty() noexcept
{
	int size;
	for (int i = 0; i < M; i++)
	{
		cin >> size;
		Party p{};
		
		for (int j = 0; j < size; j++)
		{
			int tmp;
			cin >> tmp;
			p.member.push_back(tmp);
		}
		if (findTruthPeople(p.member) == true)
			unionAll(p);
		party.emplace_back(p);
	}
}



void solve() noexcept
{
	cin >> N >> M;

	// init container
	parents.resize(N+1, 0);
	weights.resize(N+1, 1);
	std::iota(parents.begin(), parents.end(), 0);

	handleTruth();
	initParty();

	for (int i = 0; i < M; i++)
	{
		for (auto& ele: party)
		{
			if (findTruthPeople(ele.member) == true) // 진실인 사람이 있는 경우	
				unionAll(ele);
		}
	}


	int res{0};
	for (auto& ele: party)
	{
		if (ele.flag == true)
			++res;
	}
	cout << res;
}

int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	solve();

	return 0;
}