#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_VERT = 301;

class Edge
{
public:
    int from, to, w;
    Edge(const int& f_input, const int& t_input, const int& w_input):
        from(f_input), to(t_input), w(w_input) {}
    constexpr bool operator > (const Edge& other) 
    {
        return this-> w > other.w;
    }
    constexpr bool operator < (const Edge& other)
    {
        return this->w < other.w;
    }
    friend ostream& operator << (ostream& out, const Edge& E)
    {
        out << E.from << " " << E.to << " " << E.w;
        return out;
    }
};

int V, cnt, res;
int matrix[MAX_VERT][MAX_VERT];
vector<int> parents(MAX_VERT), weight(MAX_VERT,1), cost(MAX_VERT);
vector<Edge> edges;

template<typename T>
void showVector(const T& t)
{
    for(auto& ele: t)
        cout << ele << endl;
}

int Find(const int& a) noexcept
{
    if(parents[a] == a) return a;
    else
        return parents[a] = Find(parents[a]);
}

void Union(int a, int b) noexcept
{
    a = Find(a); b = Find(b);
    
    if(a==b) return;
    
    else if(weight[a] >= weight[b])
    {
        parents[b] = a;
        weight[a] += weight[b];
    }
    else
    {
        parents[a] = b;
        weight[b] += weight[a];
    }
}

void input() noexcept
{
    cin >> V;
    int input;
    for (int i = 0; i <= V; i++) parents[i] = i;
    
    for (int i = 1; i <= V; i++)
    {
        cin >> cost[i];
        edges.push_back(Edge{0,i,cost[i]});
    }
    sort(edges.begin(), edges.end());
    Union(edges[0].from, edges[0].to);
    res+= edges[0].w;
    ++cnt;
        
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cin >> matrix[i][j];
            if(i < j)
                edges.push_back(Edge{i,j,matrix[i][j]});
        }
    }
}

void kruskal() noexcept
{
    
    for(const auto& edge: edges)
    {
        auto [from, to, weight] = edge;
        
        if(Find(from)==Find(to)) continue; // 이미 포함된 경우
        // cout << "I am edge : " << edge << endl; 
        Union(from, to);
        res += weight;
        ++cnt;
        if(cnt==V)
            break;
    }
    cout << res;
}


int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    sort(edges.begin(),edges.end());
    //showVector(edges);
    kruskal();
    return (0);
}