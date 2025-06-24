#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define MAX_N 100001
using namespace std;

int N, M, cNum, hNum, K;
vector<int> parents(MAX_N, 0);
vector<int> weights(MAX_N, 1);

template<typename Container>
void debug(const Container& c)
{
    for (int i = 1; i <= N; i++)
    {
        cout << c[i] << " ";
    }cout << endl;
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
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        parents[i] = i;
}

void setUnion()
{
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        Union(a,b);
    }
}

void solve()
{
    input();
    setUnion();
    cin >> cNum >> hNum >> K;
    cNum = Find(cNum); hNum = Find(hNum);

    priority_queue<pair<int,int>> pq; // weight, num
    vector<bool> visited(N+1, false);

    for (int i = 1; i <= N; i++)
    {
        int p = Find(parents[i]);
        if (p == cNum || p == hNum || visited[p]) continue;
        pq.push(make_pair(weights[p], p));
        visited[p] = true;
    }
    
    for (int i = 0; i < K; i++)
    {
        if (pq.empty())
            break;
        Union(cNum, pq.top().second);
        pq.pop();
    }
    cout << weights[Find(cNum)];
    // debug(parents);
    // debug(weights);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();


    return (0);
}