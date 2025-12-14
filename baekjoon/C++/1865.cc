#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;
using ll = long long;
using pli = pair<ll,int>; // weght to


int Tcase, V, E, W;
vector<ll> dis;
vector<vector<pli>> adj;


void input() noexcept
{
    cin >> V >> E >> W;
    dis.resize(V+1, INF);
    adj.resize(V+1, vector<pli>());
    
    
    int from, to;
    ll w;
    for (int i = 0; i < E; ++i)
    {
        cin >> from >> to >> w;
        adj[from].push_back(make_pair(w,to));
        adj[to].push_back(make_pair(w,from));
    }
    
    for (int i = 0; i < W; ++i)
    {
        cin >> from >> to >> w;
        adj[from].push_back(make_pair(-w,to));
    }
}

void reset() noexcept
{
    for (int i = 1; i <= V; ++i)
    {
        dis[i] = INF;
        adj[i].clear();
    }
}

bool isCycle(int node) noexcept
{

    for (int i = 0; i < V-1; ++i)
    {
        for(int j = 1; j <= V; ++j)
        {
            for (const auto& ele: adj[j])
            {
                ll cost = ele.first;
                int nextNode = ele.second;
                

                if (dis[nextNode] > dis[j] + cost)
                {
                    dis[nextNode] = dis[j] + cost;
                }                
            }
        }
    }
    

    
    for(int j = 1; j <=V; ++j)
    {
        
        for (const auto& ele: adj[j])
        {
            //cout << ele.first << " ";
            ll cost = ele.first;
            int nextNode = ele.second;

            if (dis[nextNode] > dis[j] + cost)
                return true;
        }
    } 
        
    

    return false;
}


int main(void) noexcept
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> Tcase;
    
    for (int i = 0; i < Tcase; ++i)
    {
        input();
        bool cycle = false;
        
        for (int i = 1; i <= V; ++i)
        {
            if (isCycle(i))
            {
                cycle = true;
                cout << "YES" << endl;
                break;
            }
            for (int i = 1; i <= V; ++i)
                    dis[i] = INF;
        }
        if (cycle == false)
            cout << "NO" << endl;
        reset();
    }
    
    return (0);
}