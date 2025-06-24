#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// Using class
class Data
{
public:
    int N;
    Data(const int& n_input) : N(n_input) {}

    bool operator > (const Data& d) const  
    {
        if (abs(N) == abs(d.N))
            return N > d.N;  
        return abs(N) > abs(d.N);
    }

    friend ostream& operator <<(ostream& out, const Data& d)
    {
        out << d.N;
        return out;
    }
};

class AbsHeap
{
private:
    priority_queue<Data, vector<Data>, greater<Data>> pq;  
public:
    void put_node(const Data& d) noexcept { pq.push(d); } 
    Data pop_node() noexcept
	{
        auto node = pq.top();
        pq.pop();
        return node;
    }
	bool is_empty()  const {
		return pq.empty();
	}
};

int V;

void solve()
{
	AbsHeap aq;
	cin >> V;
	for (int i = 0; i < V; i++)
	{
		int N;
		cin >> N;
		if (N != 0)
			aq.put_node(Data{N});
		else
		{
			if (aq.is_empty() == true)
				cout << 0 << endl;
			else
				cout << aq.pop_node() << endl;
		}
	}
}


int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	solve();

    return 0;
}