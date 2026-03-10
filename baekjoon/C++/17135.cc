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
#include <unordered_set>
#define endl '\n'
using namespace std;

int row, col, r, res;
vector<vector<int>> matrix; 
vector<bool> arrows;


void show_matrix() {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cout << matrix[i][j] << " ";
        }cout << endl;
    }
}


void input() {
    cin >> row >> col >> r;

    matrix.assign(row+1, vector<int>(col+1, 0));
    arrows.assign(col+1, false);

    for (int i = 1; i <= row; ++i) 
        for (int j = 1; j <= col; ++j) 
            cin >> matrix[i][j];
}


void moving() {
    for (int i = row-1; i >= 1; --i) {
        for (int j = 1; j <= col; ++j) {
            matrix[i+1][j] = matrix[i][j];
        }
    }
    for (int j = 1; j <= col; ++j) 
        matrix[1][j] = 0;
}

void shooting_arrows() {
    
    vector<pair<int,int>> enemies;


    for (int a = 1; a <= col; ++a) {
        int dis = INT_MAX;
        pair<int,int> p = {-1,-1};


        if (arrows[a] == true) {
            cout << "I am a : " << a << " ";
            for (int i = row; i >= 1; --i) {
                for (int j = col; j >= 1; --j) {
                    if (matrix[i][j] == 1) {
                        int d = abs((row + 1 - i) + abs(a - j));
                        
                        if (dis > d) {
                            dis = d;
                            p.first = i; p.second = j;
                        } else if (dis == d && p.second < j) {
                            dis = d;
                            p.first = i; p.second = j;
                        }
                    }
                }
            }
            if (p.first != -1)
                enemies.push_back(p);
        }
    }
    
    for (pair<int,int> p: enemies) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    // 같은 것이 있을 수도 있음

    
    if (enemies.empty()) return ;
    else {
        res++;
        pair<int,int> p = enemies[0];

        for (int i = 1; i < enemies.size(); ++i) {
            pair<int,int> en = enemies[i];

            if (p.first != en.first || p.second != en.second) {
                p = en;
                ++res;
            }
        }
    }
}


void solve() {
    input();
    for (int z = 1; z <= row; ++z) {

        for (int i = 1; i <= col-2; ++i) {
            arrows[i] = true;
            for (int j = i + 1; j <= col-1; ++j) {
                arrows[j] = true;
                for (int k = j+1; k <= col; ++k) {
                    arrows[k] = true;
                    
                    // arrows selected
                    shooting_arrows();

                    arrows[k] = false;
                }
                arrows[j] = false;
            }
            arrows[i] = false;
        }
        moving();
    }   
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    
    solve();
    cout << res;
    return (0);
}