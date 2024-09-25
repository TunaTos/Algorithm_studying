#include <bits/stdc++.h>
#define MAX_N 200001
#define endl '\n'
using namespace std;
using ull = long long;

int N, res;
ull boundary, angry;
vector<ull> cost(MAX_N,0);
priority_queue<ull> pq;

void solve() 
{
    ull input;
    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        angry += input;
        pq.push(input);
        while(angry >= boundary)
        {
            ++res;
            angry -= (2 * pq.top());
            pq.pop();
        }
    }
}


int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> boundary;
    solve();
    cout << res;

    return (0);
}