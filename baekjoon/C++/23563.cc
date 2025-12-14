#include <bits/stdc++.h>
#define WALL -1
#define START -2
#define END -3
#define endl '\n'
using namespace std;
using pos = pair<int,int>;
using pip = pair<int,pos>;


int Row, Col, sXpos, sYpos, eXpos, eYpos;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

static int x_move[] = {-1,1,0,0}; // 상 하 좌 우
static int y_move[] = {0,0,-1,1}; 


template<typename T>
void showMatrix(const T& t)
{
    for (int i = 1; i <= Row; ++i)
    {
        for (int  j = 1; j <= Col; ++j)
            cout << t[i][j] << " ";
        cout << endl;
    }
}
void input()
{
    cin >> Row >> Col;
    matrix.assign(Row+1, vector<int>(Col+1,0));
    visited.assign(Row+1, vector<bool>(Col+1, 0));
    string str;
    
    for (int i = 1; i <= Row ; ++i)
    {
        cin >> str;
        for (int j = 0; j < Col; ++j)
        {
            if (str[j] == '#')
                matrix[i][j+1] = WALL;
            if (str[j] == '.')
                matrix[i][j+1] = 0;
            if (str[j] == 'E')
            {
                matrix[i][j+1] = END;
                eXpos = i;
                eYpos = j+1;
            }
            if (str[j] == 'S')
            {
                matrix[i][j+1] = START;
                sXpos = i;
                sYpos = j+1;
            }
        }
    }
}

bool isSide(int xpos, int ypos)
{
    for (int i = 0; i <4; ++i)
    {
        int x = xpos + x_move[i];
        int y = ypos + y_move[i];
        
        if (matrix[x][y] == WALL)
            return true;
    }
    return false;
}

void kruskal()
{
    
    vector<vector<int>> dis(Row+1 ,vector<int>(Col+1, 987654321));
    
    //showMatrix(copyMatrix);   
    priority_queue<pip, vector<pip>, greater<pip>> pq; // distance, xpos, ypos
    pq.push(make_pair(0,make_pair(sXpos, sYpos)));
    dis[sXpos][sYpos] = 0;
    
    while (!pq.empty())
    {
        int d = pq.top().first;
        int xpos = pq.top().second.first;
        int ypos = pq.top().second.second;
        pq.pop();
        
        if (dis[xpos][ypos] < d)
            continue;
            
        if (xpos == eXpos && ypos == eYpos)
        {
            cout << dis[xpos][ypos];
            return ;
        }
        //showMatrix(dis);
        //cout << endl;
        
        for (int i = 0; i < 4; ++i)
        {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];
            
            if (matrix[x][y] == WALL) // 다음 경로가 벽이라면벽이라면
                continue;
            
            if (isSide(xpos,ypos) && isSide(x,y)) // 벽에서 벽
            {
                if (dis[x][y] > d)
                {
                    dis[x][y] = d;
                    pq.push(make_pair(d, make_pair(x,y)));
                }
            }
                
            else
            {
                if (dis[x][y] > d+1)
                {
                    dis[x][y] = d+1;
                    pq.push(make_pair(d+1, make_pair(x,y)));
                }
            }
        }
    }

    
    
    
}


void solve()
{
    input();
    //showMatrix();
    kruskal();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    solve();
    
    return (0);
}