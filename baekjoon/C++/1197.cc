#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Edge
{
public:
    int start, end, weight;
    
    Edge() = default;
    Edge(const int& s_input, const int& e_input, const int& w_input ) : 
    start(s_input), end(e_input), weight(w_input) {}
    
    bool operator <(const Edge other) const
    {
        return this-> weight < other.weight;
    }
    friend ostream& operator << (ostream& out, const Edge e)
    {
        out << e.start <<  " " << e.end << " " << e.weight;
        return out;
    }
    
};

int V, E;
vector<int> parents;
vector<int> weights;
vector<Edge> edges;

template<typename T>
void showContainer(const T& constainer)
{
    for (auto&ele: constainer)
        cout << ele << " ";
    cout << endl;
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

void input()
{
    cin >> V >> E;
    parents.resize(V+1, 0);
    weights.resize(V+1, 1);
    
    for (int i = 1; i <= V; ++i)
        parents[i] = i;
    
    int from, to, weight;
    for (int i = 0; i < E; ++i)
    {
        cin >> from >> to >> weight;
        edges.push_back(Edge{from, to, weight});
    }
    sort(edges.begin(), edges.end());
    
}

void kruskal()
{
    int resultWeight{0};
    int edgeCount{0};
    
    for (const auto& edge: edges)
    {
        int from = edge.start;
        int to = edge.end;
        int weight = edge.weight;
        
        if (Find(from) == Find(to))
            continue;
        
        Union(from,to);
        
        edgeCount++;
        resultWeight += weight;
        
        if (edgeCount == V - 1)
            break;
        
    }
    cout << resultWeight;
    
}



void solve()
{
    input();
    //showContainer(parents);
    //showContainer(weights);
    //showContainer(edges);
    kruskal();
    
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
    
    return 0;
}
