/**
 * A마을까지 가는 경로
 * 소수인 Edge들만 포함한다
 * 마을의 개수 : 4000
 * 마을의 위치의 절댓값 : 3000 * 루트 2
 * 6000까지 eratos 하면 될 것 같음
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pii = pair<int,int>; 
typedef pii Edge;
Edge startPos, endPos;
vector<Edge> edges; // 중간 경류지
vector<bool> isPrime(6000 + 1, true);
vector<vector<pair<int,int>>> adj; // weight to

void input()
{
    cin >> startPos.first;
    cin >> startPos.second;
    cin >> endPos.first;
    cin >> endPos.second;

    int V;
    cin >> V;
    edges.push_back(startPos);
    edges.push_back(endPos);
    for (int i = 0; i < V; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        
        edges.push_back(make_pair(num1,num2));
    }
    adj.assign(edges.size() + 1, vector<pair<int,int>>());
}

void eratos()
{
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= sqrt(6001); i++)
    {
        if (isPrime[i]) {
            for (int j = i * 2; j <= 6000; j += i)
                isPrime[j] = false;
        }
    }
}
    
void setAdj()
{
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = i+1; j < edges.size(); j++)
        {
            auto e1 = edges[i];
            auto e2 = edges[j];

            int dis = sqrt(pow(e1.first - e2.first, 2) + pow(e1.second - e2.second, 2));
            
            if (isPrime[dis])
            {
                adj[i].push_back(make_pair(dis, j));
                adj[j].push_back(make_pair(dis, i));
            }
        }
    }
    


}



void Dijkstra()
{
    // 시작점은 0 도착점은 1

    vector<long long> d(adj.size()+1, 987654321);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // weight, node

    pq.push(make_pair(0, 0));
    d[0] = 0;

    while (!pq.empty())
    {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d[node] < w)
            continue;

        for (const auto next: adj[node])
        {
            int cost = next.first;
            int nextNode = next.second;

            if (d[nextNode] > d[node] + cost)
            {
                d[nextNode] = d[node] + cost;
                pq.push(make_pair(d[nextNode], nextNode));
            }
        }

    }
    if (d[1] == 987654321)
        cout << -1;
    else
        cout << d[1];
    

}

void solve()
{
    input();
    eratos();
    setAdj();

    
    Dijkstra();
    
}




int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     
    solve();

    return (0);
}