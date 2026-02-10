/**
 * 얼음까지 간다
 *  
 * 바위 -> 멈춘다
 * 구멍 -> ㅈ댐
 * 출구 -> 1개만 있음
 * 밖으로 나가면 -> ㅈ댐
 * 
 * 
 * 미끌 시간
 *       시작 빙판은 포함하지 않는다
 *       출구로 갈 때 출구의 미끌 시간은 포함하지 않음
 * 
 * 4방으로 탐색을 한다
 *       H나 밖으로 나가는 경우 -> ㅈ댐
 *    
 * 
 * bfs안됨 
 *       동일한 가중치가 아니기 때문 and 해당 좌표에 도달했을 때, 최단거리임을 보장하지 못함
 *       so 다익스트라를 사용해야함
 * 
 *  
 *       
 * 
 */
#include <bits/stdc++.h>
#define HUMAN -1
#define ROCK -2
#define HOLE -3
#define EXIT -4
#define OUT -5
using namespace std;
using pos = pair<int,int>;

int row, col, res = INT_MAX;
vector<vector<int>> matrix;
vector<vector<int>> visited;
const vector<int>  x_move{-1,1,0,0}, y_move{0,0,-1,1};
pos cur_pos, exit_pos;

struct node {
   int dis;
   int flag;
   pos p;
};


// function for debug()
template<typename M>
void show_matrix(const M& m) {
   for(int i = 1; i <= row; ++i) {
      for (int j = 1; j <= col; ++j) {
         cout <<m[i][j] << " ";
      }cout << endl;
   }
}


void input() noexcept {
   cin >> col >> row;

   // init container
   matrix.assign(row+1, vector<int>(col+1, 0));
   visited.assign(row+1, vector<int>(col+1, INT_MAX));

   string str;
   for (int i = 1; i <= row; ++i) {
      cin >> str;
      for (int j = 1; j <= col; ++j) {
         int num;

         if (str[j-1] == 'T') {
            num = HUMAN;
            cur_pos.first = i;
            cur_pos.second = j;
         } else if (str[j-1] == 'R') {
            num = ROCK;
         } else if (str[j-1] == 'H') {
            num = HOLE;
         } else if (str[j-1] == 'E') {
            exit_pos.first = i;
            exit_pos.second = j;

            num = EXIT;
         } else {
            num = str[j-1] - '0';
         }
         matrix[i][j] = num;
      }
   }

   visited[cur_pos.first][cur_pos.second] = 0;
}


bool inTheMatrix(int xpos, int ypos) {
   return xpos >= 1 && xpos <= row && ypos >= 1 && ypos <= col;
}



node traverse(pos p, int dir) {
   // {dis, flag, pos}
   node res;

   int xpos = p.first;
   int ypos = p.second;

   int dis = 0;
   
   while (true) {
      xpos += x_move[dir];
      ypos += y_move[dir];

      if (!inTheMatrix(xpos, ypos)) return node{dis, OUT, {xpos,ypos}};
      else if (matrix[xpos][ypos] == HOLE) return {dis, HOLE, {xpos,ypos}};
      else if (matrix[xpos][ypos] == EXIT) return {dis, EXIT, {xpos, ypos}};
      else if (matrix[xpos][ypos] == ROCK) return {dis, ROCK, {xpos - x_move[dir], ypos - y_move[dir]}};
      else {
         dis += matrix[xpos][ypos];
      }
   }
}


void bfs() {

   priority_queue<pair<int, pos>, vector<pair<int,pos>>, greater<pair<int,pos>>> q; // pos, dis
   q.push(make_pair(0, cur_pos));
   visited[cur_pos.first][cur_pos.second] = 0;


   while (!q.empty()) {
      auto z = q.top();
      pos p = z.second;
      int dis = z.first;
      q.pop();
      
      if (dis > visited[p.first][p.second]) continue;

      // cout << "Hello ";
      // cout << p.first << " " << p.second << " " <<dis << endl;
      for (int i = 0 ; i < 4; ++i) {
         node n = traverse(p, i);
         
         if (n.flag == OUT || n.flag == HOLE) continue;
         else if (n.flag == EXIT) {
            if (visited[n.p.first][n.p.second] > visited[p.first][p.second] + n.dis) {
               visited[n.p.first][n.p.second ] = visited[p.first][p.second] + n.dis;
            }
         }
         else if (n.flag == ROCK) {
            if (visited[n.p.first][n.p.second] > visited[p.first][p.second] + n.dis) {
               visited[n.p.first][n.p.second ] = visited[p.first][p.second] + n.dis;
               q.push(make_pair(visited[n.p.first][n.p.second], n.p));
            }
         
         }
      }
   }

   if (visited[exit_pos.first][exit_pos.second] == INT_MAX) 
      cout << -1;
   else
      cout << visited[exit_pos.first][exit_pos.second];
}


int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   input();
   // show_matrix(matrix);
   

   bfs();
   return (0);
}