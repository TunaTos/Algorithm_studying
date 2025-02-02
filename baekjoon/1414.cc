#include <bits/stdc++.h>
using namespace std;


class Edge
{
public:
    int node1, node2, w;
    
    Edge(int node1, int node2, int w):
        node1(node1), node2(node2), w(w) {}
    
    
    friend ostream& operator << (ostream& out, const Edge& e)
    {
        out << e.node1 << " " << e.node2 << " " << e.w;
        return out;
    }
};

vector<int> parents;
vector<int> weights;
vector<Edge> edges;
int V;
long long totalWeight;
// Function For Union-Find
int Find(const int& a)
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
        return ;
    else if (weights[a] <= weights[b])
    {
        parents[a] = b;
        weights[b] += weights[a];
    }
    else
    {
        parents[b]= a;
        weights[a] += weights[b];
    }
}


template<typename T>
void showContainer(const T& t)
{
    for (const auto& ele: t)
        cout << ele << endl;
    cout << endl;
}

void input()
{
    cin >> V;
    parents.resize(V+1, 0);
    weights.resize(V+1, 1);
    iota(parents.begin(), parents.end(), 0);
}

int charToInt(char c)
{
    if (islower(c))
        return c - 'a' + 1;
    else
        return 26 + charToInt(c - 'A' + 'a');
}

void setEdges()
{
    string str;
    
    for (int i = 1; i <= V; ++i)
    {
        cin >> str;
        for(int j = 0; j <V; ++j)
        {
            if (str[j] == '0')
                continue;
            if (i != j + 1)
                edges.push_back(Edge{i, j+1, charToInt(str[j])});
                
            totalWeight += charToInt(str[j]);
            
        }
    }
}

long long mst() 
{
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    });
    
    int edgeNum{0};
    int mstWeight{0};
    //showContainer(edges);
    
    for (const auto& edge: edges)
    {
        int node1 = edge.node1;
        int node2 = edge.node2;
        int w = edge.w;
        
        if (Find(node1) == Find(node2))
            continue;
        
        Union(node1, node2);
        ++edgeNum;
        mstWeight+= w;
        
        if (edgeNum == V-1)
            return totalWeight - mstWeight;
    }
    return -1;
}


void solve()
{
    input();
    if (V == 1)
    {
        string str;
        cin >> str;
        if (str == "0")
            cout << 0;
        else
            cout << charToInt(str[0]);
        return;
    }
    setEdges();
    cout << mst();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
    
    return (0);
}