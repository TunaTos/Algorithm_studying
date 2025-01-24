#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ull = unsigned long long;

class Edge {
public:
    int from, to;
    ull weight;
    Edge(const int& f_input, const int& t_input, const ull& w_input):
        from(f_input), to(t_input), weight(w_input) {}
    
    bool operator < (const Edge& other) const
    {
        return this->weight < other.weight;
    }
    friend ostream& operator << (ostream& out, const Edge& e)
    {
        out << e.from << " " << e.to << " " << e.weight;
        return out;
    }
};

template<typename C>
void showContainer(const C& c)
{
    for (const auto& ele: c)
        cout << ele << endl;
    cout << endl;
}
int Tcase, Row, Col, V, E;
vector<int> parents;
vector<int> weights;
vector<Edge> edges; 

int Find(int a)
{
    if (parents[a] == a)
        return a;
    else
        return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
{
    a = Find(a), b = Find(b);

    if (a ==b)
        return ;
    
    else if (weights[a] <= weights[b])
    {
        parents[a] = b;
        weights[b] += weights[a];
    }
    else {
        parents[b] = a;
        weights[a] += weights[b];
    }
}

void Kruskal() 
{
    sort(edges.begin(), edges.end());

    int edgeCount{0};
    ull totalWeight{0};

    for (const auto& edge: edges)
    {
        int from = edge.from;
        int to = edge.to;
        ull weight = edge.weight;

        if (Find(from) == Find(to)) // cycle
            continue;
        
        Union(from, to);
        edgeCount++;
        totalWeight += weight;

        if (edgeCount == V - 1)
        {
            cout << totalWeight << endl;
            return;
        }
    }
}


void input()
{
    cin >> Row >> Col;
    V = Row * Col; // 2 3
    E = (Row - 1) * Col + (Col-1) * Row;
    
    parents.resize(V+1, 0);
    weights.resize(V+1, 1);
    edges.clear();

    for (int i = 1; i <=V; ++i)
        parents[i] = i;
    
    
    int tmp = 1;
    ull w{};
    for (size_t i = 1; i <= Row; i++)
    {
        for (size_t j = 1; j <= Col - 1; j++)
        {
            cin >> w;
            edges.push_back(Edge(Col * (i - 1) + j, Col * (i - 1) + j + 1,w));
        }
    }

    for (int i = 1; i <= Row - 1; i++)
    {
        for (int j = 1; j <= Col; j++)
        {
            cin >> w;
            edges.push_back(Edge(Col * (i - 1) + j ,Col * (i - 1) + j + Col,w));
        }
    }    
}



void solve()
{
    cin >> Tcase;

    for (int i = 0; i < Tcase; i++)
    {
        input();
        Kruskal();
    }
    
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}