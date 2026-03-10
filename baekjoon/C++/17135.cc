/**
 * 궁수 3명을 배치하려고 한다.
 * 
 * 궁수는 하나의 적을 공격 && 궁수는 동시에 공격
 * 
 * 공격 대상)
 * D이하인 적 중에서 가장 가까운 적
 * 여럿이라면 가장 왼쪽의 적
 * 같은 적이 여러 궁수에게 공격당할 수 있음
 * 
 * 공격 받은 적은 게임에서 제외
 * 
 * 이동)
 * 궁수의 공격이 끝나면 이동
 * 적은 아래로 한 칸 이동함
 * 성이 있는 칸으로 이동하면 게임에서 제외
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define endl '\n'
using namespace std;

int row, col, r, res;
vector<vector<int>> matrix; 
vector<bool> arrows;

void input() {
    cin >> row >> col >> r;

    matrix.assign(row+1, vector<int>(col+1, 0));
    arrows.assign(col+1, false);

    for (int i = 1; i <= row; ++i) 
        for (int j = 1; j <= col; ++j) 
            cin >> matrix[i][j];
}

void moving(vector<vector<int>>& mat) {
    for (int i = row-1; i >= 1; --i) {
        for (int j = 1; j <= col; ++j) {
            mat[i+1][j] = mat[i][j];
        }
    }
    for (int j = 1; j <= col; ++j) 
        mat[1][j] = 0;
}
int shooting_arrows(vector<vector<int>>& mat) {
    
    vector<pair<int,int>> enemies;

    for (int a = 1; a <= col; ++a) {
        int dis = INT_MAX;
        pair<int,int> p = {-1, -1};

        if (arrows[a] == true) {



            for (int i = 1; i <= row; ++i) {
                for (int j = 1; j <= col; ++j) {
                    if (mat[i][j] == 1) {
                        int d = abs(row + 1 - i) + abs(a - j);
                        


                        if (d <= r) {
                            if (d < dis) 
                            {
                                dis = d;
                                p.first = i; p.second = j;
                            } 
                            
                            else if (d == dis && j < p.second) {
                                p.first = i; p.second = j;
                            }
                        }
                    }
                }
            }
            if (p.first != -1)
                enemies.push_back(p);
        }
    }
    
    vector<pair<int,int>> unique_enemies;
    for (pair<int,int> p : enemies) {
        if (find(unique_enemies.begin(), unique_enemies.end(), p) == unique_enemies.end()) {
            unique_enemies.push_back(p);
        }
    }

    for (pair<int,int> p : unique_enemies) {
        mat[p.first][p.second] = 0;
    }

    return unique_enemies.size();
}



void solve() {
    input();

    for (int i = 1; i <= col-2; ++i) {
        arrows[i] = true;
        for (int j = i + 1; j <= col-1; ++j) {
            arrows[j] = true;
            for (int k = j+1; k <= col; ++k) {
                arrows[k] = true;
                


                vector<vector<int>> tmp = matrix;
                int cnt = 0;

                for (int turn = 0; turn < row; ++turn) {
                    cnt += shooting_arrows(tmp);
                    moving(tmp);
                }

                res = max(res, cnt);

                arrows[k] = false;
            }
            arrows[j] = false;
        }
        arrows[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    
    solve();
    cout << res;
    return (0);
}