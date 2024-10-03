#include <bits/stdc++.h>
#define MAX_VERT 200001
#define endl '\n'
using namespace std;
using ull = unsigned long long;

class Edge{
public:
    int from, to;
    ull weight;
    
    Edge(const int& f_input, const int& t_input, const ull& w_input):
        from(f_input), to(t_input), weight(w_input) {};
    bool operator < (const Edge& other)
    {
        return weight < other.weight;
    }
    friend ostream& operator << (ostream& out, const Edge& e)
    {
        out << e.from << " " << e.to << " " << e.weight;
        return out;
    }
};

int V, E;
ull originalSum = 0;
vector<int> parents(MAX_VERT), weight(MAX_VERT, 1);
vector<Edge> edges;

int Find(const int& a) noexcept
{
    if(parents[a] == a) return a;
    else
        return parents[a] = Find(parents[a]);
}

void Union(int a, int b) noexcept
{
    a = Find(a); b = Find(b);

    if(a == b) return;
    else if(weight[a] <= weight[b])
    {
        weight[b] += weight[a];
        parents[a] = b;
    }
    else
    {
        weight[a] += weight[b];
        parents[b] = a;
    }
}


template<typename T>
void showVec(T& t)
{
    for(auto& ele: t)
        cout << ele << endl;
}

void input() noexcept
{
    int from, to;
    ull w;
    for (size_t i = 0; i <= V; i++)
        parents[i] = i;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> w;
        originalSum += w;
        edges.emplace_back(Edge{++from, ++to, w});
    }
}

void mst() noexcept
{
    sort(edges.begin(),edges.end());
    
    int edgeNum = 0;
    ull mstWeight = 0;
    
    for(const auto& ele: edges)
    {
        int from = ele.from;
        int to = ele.to;
        ull w = ele.weight;

        if(Find(from) == Find(to)) continue;
        Union(from, to);
        ++edgeNum;
        mstWeight += w;
        if(edgeNum == V-1) break;
    }
    cout << originalSum - mstWeight << endl;
}

void reset() noexcept
{
    for (int i = 0; i <= V; i++)
    {
        parents[i] = i;
        weight[i] = 1;
    }
    edges.clear();
    originalSum = 0;
}


void solve() noexcept
{
    while(true)
    {
        cin >> V >> E;
        if(V==0 && E==0) return;
        input();
        mst();
        reset();

    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return (0);
}