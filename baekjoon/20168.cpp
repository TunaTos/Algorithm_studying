#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_VERT 11
#define INF 987654321
using namespace std;
using ull = unsigned long long;
using pui = pair<unsigned long long, int>; // weight, to

int V, E, Start, End, M;
ull minResult = INF, maxResult = 0;
priority_queue<pui,vector<pui>,greater<pui>> pq;
vector<pui> adj[MAX_VERT];
vector<ull> dis(MAX_VERT,INF);

void input() noexcept
{
    cin >> V >> E >> Start >> End >> M;
    int from, to, weight;

    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
        adj[to].push_back({weight, from});
    }
}

bool dijkstra(const int& bottleNeck) noexcept
{
    pq.emplace(make_pair(0,Start));
    dis[Start] = 0;

    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        ull distance = p.first;
        int s = p.second;


        if(dis[s] < distance) 
            continue;
        
        for(auto& next: adj[s])
        {
            ull cost = next.first;
            int to = next.second;

            if(cost > bottleNeck) continue;
            if(dis[to] > dis[s] + cost && M >= dis[s] + cost)
            {
                dis[to] = dis[s] + cost;
                pq.emplace(make_pair(dis[to], to));
            }
        }
    }
    return dis[End] <= M;
}

void solve() noexcept
{
    int res = -1;
    for (int i = 1; i <= 1000; i++)
    {
        if(dijkstra(i))
        {
            cout << i;
            return;
        }
        for (int i = 0; i < 11; i++)
            dis[i] = INF;
        while(!pq.empty())
            pq.pop();
        
    }
    cout << res;

}


int main(void)
{
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

    input();
    solve();


   return 0;
}