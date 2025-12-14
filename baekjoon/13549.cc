#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define MAX 100000
using namespace std;
using pii = pair<int,int>;
int start, target, res;
vector<bool> visited;

priority_queue<pii, vector<pii>, greater<pii>> pq;

bool inTheArray(int node) 
{
    if (node >= 0 && node <= 100000)
        return true;
    else
        return false;
}

void dfs(int node) 
{

    visited.resize(MAX + 1 , false);
    visited[start] = true;
    pq.push(make_pair(0, start));
    if (inTheArray(start * 2))
    {
        pq.push(make_pair(0, 2*start));
        visited[start * 2] = true;
    }
    

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        
        if (pos == target)
        {
            res = dis;
            break;
        }

        int doublePos = pos * 2;
        if (inTheArray(doublePos) && !visited[doublePos])
        {
            pq.push(make_pair(dis, doublePos));
            visited[doublePos] = true;
        }
        
        if (inTheArray(pos - 1) && !visited[pos - 1])
        {
            pq.push(make_pair(dis + 1, pos -1));
            visited[pos-1] = true;
        }
        
        if (inTheArray(pos+1) && !visited[pos+1])
        {
            pq.push(make_pair(dis+1, pos+1));
            visited[pos+1] = true;
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> start >> target;
    dfs(start);
    cout << res;



    return (0);
}
