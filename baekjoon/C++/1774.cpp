#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Edge
{
public:
    int x, y;
    double weight;

    Edge(const int& x_input, const int& y_input, const double w_input):
        x(x_input), y(y_input), weight(w_input) {};

    bool operator <(const Edge& other)
    {
        return weight < other.weight;
    }
    friend ostream& operator << (ostream& out, const Edge& e)
    {
        out << e.x << " " << e.y << " " << e.weight << endl;
        return out;
    }

};

int V, connectedEdges;
vector<pair<int,int>> pos;
vector<int> parents, weight;
vector<Edge> edges;
void showPos()
{
    for(auto& ele: pos)
        cout << ele.first << " " << ele.second << endl;
    
}
int Find(const int& a)
{
    if(parents[a] == a) return a;
    else
        return parents[a] = Find(parents[a]);
}

void Union(int a, int b)
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
        parents[b] =a;
    }
}

void init()
{
    for (int i = 1; i <= V; i++)
        parents[i] = i;
}

void setEdges()
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = i; j <= V; j++)
        {
            if(i == j) continue;
            auto pos1 = pos[i];
            auto pos2 = pos[j];

            double distance = sqrt(pow((pos1.first - pos2.first),2) + pow((pos1.second - pos2.second),2));
            edges.push_back(Edge(i,j,distance));
        }
    }
}


void input()
{
    pos.push_back({0,0});
    int x, y;
    for (int i = 0; i < V; i++)
    {
        std::cin >> x >> y;
        pos.push_back({x,y});
    }
    //showPos();
    setEdges();
    
    for (int i = 0; i < connectedEdges; i++)
    {
        std::cin >> x >> y;
        Union(x,y);    
    }
}

void mst()
{
    double res = 0;
    int count = connectedEdges;
    sort(edges.begin(),edges.end());

    for(const auto& ele: edges)
    {
        int x = ele.x;
        int y = ele.y;
        double w = ele.weight;

        if(Find(x)==Find(y)) continue;
        Union(x,y);
        res += w;
        ++count;

        // if(count == V -1)
        //     break;
    }
    cout << std::fixed << std::setprecision(2);
    cout << res;
}

int main(void)
{
    ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> V >> connectedEdges;
    parents.resize(V+1); weight.resize(V+1);
    init();
    input();
    mst();
    
    // for(const auto& ele: edges)
    //     std::cout << ele << endl;

    return (0);
}