#include <iostream>
#include <vector>
#include <algorithm>
#define CLEAN 1
#define DIRTY 0
#define endl '\n'
using namespace std;
using pii = pair<int,int>;

/**
 * union-find를 해서 청정수가 더 많은 경우 return true
 */


int V, E, T;
vector<int> parents;
vector<pii> weights; // clean dirty

ostream& operator << (ostream& out, pair<int,int> p)
{
    out << p.first << " " << p.second;
    return out;
}

template<typename T>
void showContainer(const T& t)
{
    for (int i = 1; i <= V; ++i)
        cout << t[i] << " ";
    cout << endl;
}


void input()
{
    cin >> V >> E >> T;

    parents.resize(V+1, 0);
    weights.resize(V+1, pair<int,int>());
    for (int i = 1; i<= V; ++i)
        parents[i] = i;
    
    for (size_t i = 1; i <= V; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == CLEAN)
            weights[i].first++;
        else if (tmp == DIRTY)
            weights[i].second++;
    }
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

    if (a == b) return;

    int weight1 = weights[a].first + weights[a].second;  
    int weight2 = weights[b].first + weights[b].second;
    
    if (weight2 > weight1)
    {
        parents[a] = parents[b];
        weights[b].first += weights[a].first;
        weights[b].second += weights[a].second;
    }
    
    else 
    {
        parents[b] = parents[a];
        weights[a].first += weights[b].first;
        weights[a].second += weights[b].second;
    }
}

bool isPossible(int node)
{
    node = Find(node);
    
    if (weights[node].first > weights[node].second)
        return true;
    return false;
}

void solve()
{
    input();

    int a, b;
    for (int i = 1; i <= E; ++i)
    {
        int a, b;
        cin >> a >> b;
        Union(a,b);
    }
    int node;
    for (int i = 1; i <= T; ++i)
    {
        cin >> node;
        if (isPossible(node))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    

}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}