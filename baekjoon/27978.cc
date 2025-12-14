/*
8칸 중에 한 곳으로 이동할 수 있다 (1칸)

시계방향에서 1,3,5방향은 연료가 소모되지 않는다
나머지는 1의 연료를 소모한다.

연료의 최소값은 어떻게 되는가?

//////
. -> 바다
# -> 암초
* -> 보물
K -> 배

<배와 보물은 지도에 1번만 나타난다>
*/


#include <iostream>
#include <vector>
#include <algorithm>   
#include <queue>
#include <string>
#define INF 987654321
#define endl '\n'
#define WATER '.'
#define WALL '#'
#define GOLD '*'
#define SHIP 'K'
using namespace std;
using pii = pair<int,int>;

const int x_move[] = {-1,0,1,1,1,0,-1,-1}; // 0~2 까지는 0이다
const int y_move[] = {1,1,1,0,-1,-1,-1,0};

int Row, Col, sXpos, sYpos;

vector<vector<char>> matrix;
vector<vector<int>> dis;

template<typename T>
void showContainer(const T& t)
{
    for (int i = 1; i <= Row; i++)
    {
        for (int j = 1; j <= Col; j++)
        {
            cout << t[i][j] << " ";
        }cout << endl;
    }
}

void input()
{
    cin >> Row >> Col;

    // init container
    matrix.assign(Row+1, vector<char>(Col+1));
    dis.assign(Row+1, vector<int>(Col+1, INF));

    for (int i = 1; i <= Row; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < Col; j++)
        {
            matrix[i][j+1] = str[j];
            
            if (str[j] == SHIP)
            {
                sXpos = i;
                sYpos = j+1;
            }
        }
    }
}

bool inTheMatrix(int xpos, int ypos)
{
    return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
}


void Dijkstra()
{
    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push(make_pair(0, make_pair(sXpos, sYpos))); // weight, xpos,ypos;
    dis[sXpos][sYpos] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cXpos = pq.top().second.first;
        int cYpos = pq.top().second.second;
        pq.pop();

        if (dis[cXpos][cYpos] < cost)
            continue;
        if (matrix[cXpos][cYpos] == GOLD)
        {
            cout << dis[cXpos][cYpos];
            return ;    
        }

        for (int i = 0; i < 8; i++)
        {
            int x = cXpos + x_move[i];
            int y = cYpos + y_move[i];

            if (!inTheMatrix(x,y))
                continue;
            if (matrix[x][y] == WALL)
                continue;


            int nextCost = cost;

            if (i <= 2 && dis[x][y] > dis[cXpos][cYpos])
            {
                dis[x][y] = dis[cXpos][cYpos];
                pq.push(make_pair(dis[x][y], 
                    make_pair(x,y)));
            }

            else if (i > 2 && dis[x][y] > dis[cXpos][cYpos] + 1)
            {
                dis[x][y] = dis[cXpos][cYpos] + 1;
                pq.push(make_pair(dis[x][y],
                    make_pair(x,y)));
            }
        }    
    }
    cout << -1;
}


void solve()
{
    input();

    Dijkstra();
    showContainer(dis);

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    solve();

    return (0);
}