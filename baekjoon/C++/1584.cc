/**
 * 죽음의 구역 -> 들어갈 수 없음
 * 위험한 구역한 번 움직이면 생명 1
 * 안전한 구역 -> 생명의 위협이 없음
 *      죽음의 구역과 위험한 구역 말고 나머지
 * 
 * (0,0) -> (500,500)
 * 
 * N -> 위험한 구의 구역
 * (x1, y1) -> 모서리
 * 
 * 죽음의 구역 -> 구역에 들어갈 때만 1씩 깎인다?
 * 
 * 가중치가 다른 bfs? -> 다익스트라? 
 * 
 * 출력 -> 잃는 생명의 최솟값
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define SAFE 0
#define DANGER 1
#define DEAD 2
#define INF 7777777
using namespace std;
using pos = pair<int,int>;
using pip = pair<int, pos>;


vector<vector<int>> matrix;
vector<vector<bool>> visited;
int x_move[] = {-1,1,0,0};
int y_move[] = {0,0,-1,1};
int N,M;
pos sPos, ePos;


template<typename c>
void showMatrix(const c& m) {
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            cout << m[i][j] << " ";
        }cout << endl;
    }
}


bool inTheMatrix(int xpos, int ypos) {
    return xpos >= 0 && xpos <= 500 && ypos >= 0 && ypos <= 500;
}


void input() {
    matrix.assign(500+1, vector<int>(500+1,0));
    visited.assign(500+1, vector<bool>(500+1,false));
    
    cin >> N;
    for (int k = 1; k <= N; ++k) {
        cin >> sPos.first >> sPos.second;
        cin >> ePos.first >> ePos.second;

        for (int i = min(sPos.first, ePos.first); i <= max(sPos.first,ePos.first); ++i) {
            for (int j = min(sPos.second, ePos.second); j <= max(sPos.second,ePos.second); ++j) {
                matrix[i][j] = DANGER;
            }
        }
    }

    cin >> M;
    for (int k = 1; k <= M; ++k) {
        cin >> sPos.first >> sPos.second;
        cin >> ePos.first >> ePos.second;

        for (int i = min(sPos.first, ePos.first); i <= max(sPos.first,ePos.first); ++i) {
            for (int j = min(sPos.second, ePos.second); j <= max(sPos.second,ePos.second); ++j) {
                matrix[i][j] = DEAD;
            }
        }
    }
}

void dijkstra() {
    // 들어갈 때 피가 깎인다.
    priority_queue<pip> pq; // {-dmg, xpos, ypos}
    vector<vector<int>> dp;
    dp.assign(500+1, vector<int>(500+1, INF));
    
    dp[0][0] = 0;
    pq.push({0,{0,0}});

    
    while (!pq.empty()) {
        int dmg = pq.top().first * -1;
        int xpos = pq.top().second.first;
        int ypos = pq.top().second.second;
        pq.pop();

        if (dmg > dp[xpos][ypos]) continue;
        

        for (int i = 0; i < 4; ++i) {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];
            
            if (!inTheMatrix(x,y)) continue;
            if (matrix[x][y] == DEAD) continue; // 죽음인 경우
            int addDmg;
            if (matrix[x][y] == DANGER) 
                addDmg = 1;
            else if (matrix[x][y] == SAFE)
                addDmg = 0;            
            if (dp[x][y] > dp[xpos][ypos] + addDmg) {
                dp[x][y] = dp[xpos][ypos] + addDmg;
                pq.push({-(dp[x][y]), {x,y}});
            }
        }
    }

    dp[500][500] == INF ? cout << -1 << endl: cout << dp[500][500] << endl;
    

        //cout << endl;
        //showMatrix(matrix);
        //cout << endl;
        //showMatrix(dp);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    dijkstra();
    return (0);
}