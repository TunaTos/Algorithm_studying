#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int V, E, T, e_count;
long long res;

class union_find
{
private:
	vector<int> parents;
	vector<int> weight;

public:
	union_find(const int& n_input) {
			parents.resize(n_input+1, 0);
			weight.resize(n_input+1, 1);
			iota(parents.begin(), parents.end(), 0);
		}

	int Find(int a)
	{
		if (parents[a] == a)
			return a;
		else
			return parents[a] = Find(parents[a]);
	}

	void Union(int a, int b)
	{
		a = Find(a); b = Find(b);

		if (a == b)
			return;
		else if (weight[a] <= weight[b])
		{
			parents[a] = b;
			weight[b] += weight[a];
		}
		else if (weight[b] >= weight[a])
		{
			parents[b] = a;
			weight[a] += weight[b];
		}
	}
	
	bool is_cycle(int a, int b){ return Find(a) == Find(b); }
	auto get_parents() {return this->parents;}
	auto get_weights() { return this->weight;}	
};

class Edge
{
private:
	int from, to, weight;

public:
	Edge(istream& in) {
		in >> from >> to >> weight;
		if (from > to)
			swap(this->from, this->to);
	}
	int get_from() {return this->from;}
	int get_to() {return this->to;}
	int get_weight() {return this-> weight;}

	bool operator < (const Edge& other)
	{
		return this->weight < other.weight;
	}
	friend ostream& operator << (ostream& out, const Edge& e)
	{
		out << e.from << " " << e.to << " " << e.weight << endl;
		return out;
	}
};

vector<Edge> my_edge;

void show_vector(const auto& container) noexcept
{
	cout << "This is container" << endl;
	for(auto&ele: container)
		cout << ele << " ";
	cout << endl;
}

bool kruskal(union_find& uf) noexcept
{
	if (V==2 && e_count == 1)
		return true;
	for(auto&ele: my_edge)
	{
		auto [from, to, weight] = make_tuple(ele.get_from(), ele.get_to(), ele.get_weight());

		if (uf.is_cycle(from, to))
			continue;

		uf.Union(from, to);
		++e_count; res += weight;
		if (e_count == V -1)
			return true;
	}
	return false;
}

void solve() noexcept
{
	cin >> V >> E >> T;
	if (V==1)
	{
		cout << 0;
		return ;
	}
		
	union_find uf = union_find(V);
	// show_vector(uf.get_parents());
	// show_vector(uf.get_weights());
	for (int i = 0; i < E; i++)
	{
		Edge e(cin);
		my_edge.emplace_back(e);
	}
	sort(my_edge.begin(), my_edge.end());
	// show_vector(my_edge);
	for(auto&ele: my_edge)
	{
		if (ele.get_from() == 1)
		{
			++e_count; res += ele.get_weight();
			uf.Union(ele.get_from(), ele.get_to());
			break;
		}
	}
	
	// show_vector(uf.get_parents());
	if (kruskal(uf))
	{
		V = V -2;
		res += T * (V) * (V+1) / 2;
		cout << res;
	}
	else
		cout << 0;

}


int main(void) noexcept
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();

	return (0);
}