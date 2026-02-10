/**
 * N이닝동안 진행
 * 3아웃 발생하면 종료
 * 
 * 1번부터 9번은 매겨져 있음
 * 
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, res;
vector<vector<int>> matrix;
vector<int> visited(9+1, false);
vector<int> selected(9+1, 0);

void input() {
   cin >> N;

   matrix.assign(N+1, vector<int>(9+1));


   for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= 9; ++j) {
         cin >> matrix[i][j];
      }
   }

   selected[4] = 1;
   visited[1] = true;
}

void permutation(int dpt) {

   if (dpt == 10) {
      
      
      // solve 
      int idx = 1; // 순번
      int score = 0;

      for (int iCount = 1; iCount <= N; ++iCount) 
      {
         int outCnt = 0;
         deque<int> base;


         while (outCnt <= 2) 
         {   
            int action = matrix[iCount][selected[idx]];

            // 아웃
            if (action == 0) {
               ++outCnt;
            }

            else if (action == 1) {
               base.push_back(0);
               int cnt = 0;
               for (int i = 0; i < base.size(); ++i) {
                  base[i]++;
                  if (base[i] >= 4) {
                     ++cnt;
                  }
               }
               for (int i = 0; i < cnt; ++i) {
                  base.pop_front();
                  ++score;
               }
            }

            else if (action == 2) {
               base.push_back(0);
               int cnt = 0;
               for (int i = 0; i < base.size(); ++i) {
                  base[i] += 2;
                  if (base[i] >= 4) {
                     ++cnt;
                  }
               }
               for (int i = 0; i < cnt; ++i) {
                  base.pop_front();
                  ++score;
               }
            }
            
            else if (action == 3) {
               base.push_back(0);
               int cnt = 0;
               for (int i = 0; i < base.size(); ++i) {
                  base[i] += 3;
                  if (base[i] >= 4) {
                     ++cnt;
                  }
               }
               for (int i = 0; i < cnt; ++i) {
                  base.pop_front();
                  ++score;
               }
            }

            else if (action == 4) {
               base.push_back(0);
               score += base.size();
               base.clear();
            }

            idx == 9 ? idx = 1 : ++idx;
         }
      }
      res = max(res, score);

      return ;
   }

   if (dpt == 4) {
      permutation(dpt+1);
      return ;
   }


   for (int i = 2; i <= 9; ++i) {
      if (!visited[i]) {
         visited[i] = true;
         selected[dpt] = i;


         permutation(dpt+1);

         // 원상복구
         visited[i] = false;
      }

   }
}





int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   input();
   permutation(1);
   cout << res << endl;
   return (0);
}