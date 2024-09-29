#include <bits/stdc++.h>
#define MAX_VERT 1001
#define INF 9999999999
#define endl '\n'
using namespace std;
using ull = unsigned long long;
using pui = pair<ull,int>;
int V, E, S = 1, T = 2;
vector<pui> adj[MAX_VERT]; // weight, to
vector<ull> disStart(MAX_VERT,INF), disTo(MAX_VERT,INF); // 시작점에서, 도착점에서
vector<bool> isValid(MAX_VERT,false), visited(MAX_VERT,false); // S에서 T방향으로 가는 V인가?
vector<int> path(MAX_VERT,0);

ostream& operator << (ostream& out, const pui& p)
{
    out << p.first << " " << p.second;
    return out;
}
template<typename T>
void showDistance(T& v)
{
    for (int i = 1; i <= V; i++)
    {
        cout << v[i] << " ";
    }cout << endl;
}


void showAdj()
{
    for (int i = 1; i <= V; i++)
    {
        cout << "i is : " << i << " ";
        for(auto& ele: adj[i])
            cout << ele << " ";
        cout << endl;
    }
}

void input()
{
    int from, to;
    ull w;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> w;
        adj[from].push_back(make_pair(w,to));
        adj[to].push_back(make_pair(w,from));
    }
}

void Dijkstra(const int& start, vector<ull>& v)
{
    priority_queue<pui,vector<pui>,greater<pui>> pq;
    pq.push(make_pair(0,start));
    v[start] = 0;

    while(!pq.empty())
    {
        ull dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(v[node] < dis) continue;

        for(const auto& next: adj[node])
        {
            ull cost = next.first;
            int to = next.second;

            if(v[to] >= v[node] + cost)
            {
                v[to] = v[node] + cost;
                pq.push(make_pair(v[to],to));
            }
        }
    }   
}

void setValid() 
{
    /*
    adj를 순회하면서, S에서 T로 향하는 것인지 알아본다
    */
    const ull standard = disStart[2];
    for (int i = 1; i <= V; i++)
    {
        if(disStart[i] + disTo[i] == standard)
            isValid[i] = true;
    }
}

int dfs(int node)
{
    if(node == T) return 1;
    if(visited[node]) return path[node];

    visited[node] =true;
    int totalPaths = 0;

    for(const auto& ele: adj[node])
    {
        int next = ele.second;
        if(isValid[next] && disTo[next] < disTo[node])
            totalPaths += dfs(next);
    }
    path[node] = totalPaths;
    return path[node];
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    Dijkstra(S, disStart);
    Dijkstra(T, disTo);
    setValid();
    dfs(S);
    int res = dfs(1);
    //showDistance(path);
    cout << res;
    return (0);
}