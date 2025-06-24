#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>  
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

int x_move[] = {-1, 1, 0, 0};
int y_move[] = {0, 0, -1, 1};
int Row, Col, T, D; 
vector<vector<int>> matrix;

void input()
{
    cin >> Row >> Col >> T >> D;
    string str;

    matrix.assign(Row + 1, vector<int>(Col + 1, 0));
    for (int i = 1; i <= Row; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] >= 'a' && str[j] <= 'z')
                matrix[i][j + 1] = str[j] - 'a' + 26;
            else
                matrix[i][j + 1] = str[j] - 'A';
        }
    }
}

bool inTheMatrix(int xpos, int ypos)
{
    return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
}

vector<vector<int>> Dijkstra(pair<int, int> start)
{
    vector<vector<int>> dis(Row + 1, vector<int>(Col + 1, 1e9));
    dis[start.first][start.second] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; // {cost, {x, y}}

    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int xpos = pq.top().second.first;
        int ypos = pq.top().second.second;
        pq.pop();

        if (dis[xpos][ypos] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];

            if (!inTheMatrix(x, y))
                continue;

            int height_diff = matrix[x][y] - matrix[xpos][ypos];

            if (abs(height_diff) > T)
                continue;

            int weight = (height_diff > 0) ? pow(height_diff, 2) : 1;
            int new_cost = dis[xpos][ypos] + weight;

            if (dis[x][y] > new_cost)
            {
                dis[x][y] = new_cost;
                pq.push({new_cost, {x, y}});
            }
        }
    }
    return dis;
}

void solve()
{
    input();

    vector<vector<int>> go_dis = Dijkstra({1, 1});

    int max_height = matrix[1][1]; 

    for (int i = 1; i <= Row; i++)
    {
        for (int j = 1; j <= Col; j++)
        {
            if (go_dis[i][j] == 1e9 || go_dis[i][j] > D)
                continue; 

            vector<vector<int>> return_dis = Dijkstra({i, j});
            if (return_dis[1][1] != 1e9 && go_dis[i][j] + return_dis[1][1] <= D)
            {
                max_height = max(max_height, matrix[i][j]);
            }
        }
    }

    cout << max_height << endl;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return (0);
}