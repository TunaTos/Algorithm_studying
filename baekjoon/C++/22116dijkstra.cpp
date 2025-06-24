#include <bits/stdc++.h>
#define MAX_LEN 1001
#define endl '\n'
using namespace std;
using ull = long long;
using pii = pair<int,int>;

ull matrix[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];

int Len;
const int x_move[] = {-1,1,0,0};
const int y_move[] = {0,0,-1,1};

template<typename T>
void debug(const T& t)
{
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len; j++)
            cout <<  t[i][j] << " ";
        cout << endl;
    }
}

void reset()
{
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len; j++)
            visited[i][j] = false;
    }
}

void input()
{
    cin >> Len;

    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len; j++)
            cin >> matrix[i][j];
    }
}

bool inTheMatrix(const int& x, const int& y)
{
    if(x>=1 && x <= Len && y >= 1 && y <= Len)
        return true;
    else
        return false;
}


void dijkstra()
{
    priority_queue<pair<ull,pii>,vector<pair<ull,pii>>,greater<pair<ull,pii>>> pq;
    pq.push({0,{1,1}});
    
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        ull dis = node.first;
        int xpos = node.second.first;
        int ypos = node.second.second;
        if(xpos==Len && ypos ==Len) {
            cout << dis << endl;
            return;
        }
        if(visited[xpos][ypos]) continue;
        visited[xpos][ypos] = true;

        for (int i = 0; i < 4; i++)
        {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];

            if(!inTheMatrix(x,y)) continue;
            if(visited[x][y]) continue;
            ull w = abs(matrix[x][y] - matrix[xpos][ypos]);

            pq.push({max(w, dis),{x,y}});
        }
    }    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    dijkstra();
    
    return 0;
}