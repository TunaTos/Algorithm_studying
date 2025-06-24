#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define endl '\n'
using namespace std;
using ull = unsigned long long;

int N; 
const int x_move[] = {-1,1,0,0}; // 상 하 좌 우
const int y_move[] = {0,0,-1,1};

vector<vector<ull>> matrix;
vector<vector<ull>> dis;

class Edge
{
public:
    int xpos;
    int ypos;
    ull cost;

    Edge(int xpos, int ypos, ull cost):
        xpos(xpos), ypos(ypos), cost(cost) {}
    
    bool operator > (const Edge& other) const
    {
        return this->cost > other.cost;
    }
};

template<typename T>
void showContainer(const T& t)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << t[i][j] << " ";
        }cout << endl;
    }
}

void init()
{
    matrix.assign(N+1, vector<ull>(N+1,0));
    dis.assign(N+1, vector<ull>(N+1, INF));
}

void input()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> matrix[i][j];   
}

bool inTheMatrix(int xpos, int ypos)
{
    return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
}

void dijkstra()
{
    priority_queue<Edge,vector<Edge>, greater<Edge>> pq;
    dis[1][1] = matrix[1][1];

    pq.push(Edge(1,1,dis[1][1]));

    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();

        int xpos = edge.xpos;
        int ypos = edge.ypos;
        ull cost = edge.cost;

        if (dis[xpos][ypos] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];

            if (!inTheMatrix(x,y))
                continue;
            

            ull tmp = dis[xpos][ypos] + matrix[x][y];

            if (dis[x][y] > tmp)
            {
                dis[x][y] = tmp;
                pq.push(Edge(x,y,dis[x][y]));
            }
        }
    }

}

void solve()
{
    int cnt = 1;
    while (true)
    {
        cin >> N;
        if(N==0)
            return ;
        
        init();
        input();
        dijkstra();
        cout << "Problem " << cnt << ": " << dis[N][N] << endl;
        ++cnt;
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    solve();

    return (0);
}