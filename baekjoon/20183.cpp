#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_VERT 100001
#define INF 9999999999999999
using ull = unsigned long long;
using pui = std::pair<ull, int>;
using namespace std;

vector<ull> dis(MAX_VERT,INF);
vector<pui> adj[MAX_VERT];
int V, E, Start, End;
ull M;

template<typename T>
void showDistance(const T& d)
{
    for (int i = 1; i <= V; i++)
        cout << d[i] << " ";
    cout << endl;
}

void input() noexcept
{
    int from, to;
    ull w;
    std::cin >> V >> E >> Start >> End >> M;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> w;
        adj[from].push_back({w,to});
        adj[to].push_back({w, from});
    }
}

void resetDistance()
{
    for (int i = 1; i <= V; i++)
        dis[i] = INF;
}

bool dijkstra(const int& bottleneck)
{
    priority_queue<pui,vector<pui>,greater<pui>> pq;
    
    pq.emplace(make_pair(0,Start));
    dis[Start] = 0;

    while(!pq.empty())
    {
        auto [cost, from] = pq.top();
        pq.pop();

        if(dis[from] < cost) continue;

        for(auto [distance, to]: adj[from])
        {
            if(distance > bottleneck) continue;
            
            if(dis[to] > dis[from] + distance && M >= dis[from] + distance)
            {
                dis[to] = dis[from] + distance;
                pq.emplace(make_pair(dis[to],to));
            }
        }
    }
    //cout << "I am bottleneck : " << bottleneck<< endl;
    //showDistance(dis);
    return dis[End] != INF;
}

void solve()
{
    ull left = 1, right = 1000000000;
    int res = -1;

    while(left <= right)
    {    
        resetDistance();
        ull mid = (left + right) / 2;

        if(dijkstra(mid))
        {
            res = mid;
            right = mid - 1;
        }   
        else
            left = mid + 1;
    }
    cout << res;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    //showDistance(dis);
    
    return (0);
}