/**
 * 백양로 브레이크 (BOJ 11562)
 * 
 * 입력)
 * n, m: 건물 수(≤250), 길의 수
 * u, v, b: 길 정보 (b=0: 일방통행, b=1: 양방향)
 * k: 질문 개수(≤30,000)
 * s, e: 출발지, 도착지 (같을 수도 있음)
 * 
 * 출력)
 * s→e로 가기 위해 양방향으로 바꿔야 하는 최소 일방통행 개수
 * 
 * FAIL
 * 
 * 분석한 것)
 * - V의 개수가 250으로 적은 것을 보고 O(V³) 플로이드-워셜 알고리즘 파악
 * - 질문이 30,000개로 많아서 전처리 필요성 인지
 * 
 * 틀린 점)
 * - 가중치를 어떻게 설정해야 하는지 몰랐음
 * - 일방통행과 양방향 길을 그래프 가중치로 어떻게 변환하는지 이해 못함
 * 
 * 정답 아이디어)
 * - 양방향(b=1): 양쪽 모두 가중치 0 (이미 양방향이라 바꿀 필요 없음)
 * - 일방통행(b=0): 
 *   · 정방향(u→v): 가중치 0 (그냥 갈 수 있음)
 *   · 역방향(v→u): 가중치 1 (일방통행을 양방향으로 바꿔야 함)
 * - 최단거리 = 바꿔야 하는 최소 일방통행 개수
 * 
 * 배운점)
 *      플로이드는 어떤 것을 거리?로 잡아야하는지를 묻는 것 같음.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;

int V,E, K;
vector<vector<int>> dis;

// Function for debug
template<typename matrix>
void show_matrix(const matrix& mat) {
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << mat[i][j] << " ";
        }cout << endl;
    }
}

void input() noexcept {
    cin >> V >> E;

    dis.assign(V+1, vector<int>(V+1, INF));
    
    for (int i = 0; i < E; i++)
    {
        int from, to, dir;
        cin >> from >> to >> dir;
    
        if (dir == 0) {
            dis[from][to] = 0;
            dis[to][from] = 1;
        } else if (dir == 1) {
            dis[from][to] = dis[to][from] = 0;
        }
    }
    for (int i = 1; i <= V; i++)
        dis[i][i] = 0;
    
    
}

void floyd() {
    for (int k = 1; k <= V; k++)
    {
        for (int s = 1; s <= V; s++)
        {
            for (int e = 1; e <= V; e++)
            {
                if (dis[s][k] != INF && dis[k][e] != INF && dis[s][e] >= dis[s][k] + dis[k][e]) {
                    dis[s][e] = dis[s][k] + dis[k][e];
                }
            }
        }
    }
}

void solve() {
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int from, to;
        cin >> from >> to;
        
        cout << dis[from][to] << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    input();
    floyd();
    solve();
    return (0);
}