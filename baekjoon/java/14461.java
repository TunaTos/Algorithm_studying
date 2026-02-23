/*
* 길을 건너는데 T초가 걸린다
* dp[3][N][N] -> step % 3
*
* step 3번째 갈 때는 해당 목초지를 다 먹어야한다 (시작점 제외, 도착점 ok)
* 나머지는 그냥 T초만 더하면 된다
*
* DP가 안되는 이유(dp의 조건)
*   1. 최적 부분 구조 : 특정 해의 최적값을 구하기 위해 이전의 최적값을 사용한다
*   2. 중복 부분 문제 : 같은 문제가 반복적으로 발생한다
*   3. DAG : 상태공간tree가 DAG가 되어야한다 (이 문제가 DP가 안되는 이유)
*
* 시간 복잡도 : 다익스트라 -> O(ElogV)
* E : 12N²
* V : N * N * 3 -> N²
* O(N² log N)
*
*
* */
package p_14461;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int xpos;
        int ypos;
        int step;
        long dis;

        Node(int xpos, int ypos, int step,  long dis) {
            this.xpos = xpos;
            this.ypos = ypos;
            this.step = step;
            this.dis = dis;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long[][][] dp;
    static long[][] matrix;
    static int N;
    static long T;
    static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};


    public static void main(String[] args) throws Exception {
        input();
        Dijkstra();

        // showMatrix(dp[0]);
        // showMatrix(dp[1]);
        // showMatrix(dp[2]);

    }


    // function for debug
    static void showMatrix(long[][] matrix) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Long.parseLong(st.nextToken());

        // init container
        dp = new long[3][N+1][N+1];
        matrix = new long[N+1][N+1];
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j <= N; ++j) {
                Arrays.fill(dp[i][j], Long.MAX_VALUE);
            }
        }

        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; ++j) {
                matrix[i][j] = Long.parseLong(st.nextToken());
            }
        }
    }

    static void Dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>((a,b) -> {
            return Long.compare(a.dis, b.dis);
        });


        dp[0][1][1] = 0;

        pq.add(new Node(1,1,0,0));

        while (!pq.isEmpty()) {
            Node n = pq.poll();

            int xpos = n.xpos;
            int ypos = n.ypos;
            int step = n.step;
            long dis = n.dis;

            if (dp[step][xpos][ypos] < dis) continue;

            for (int i = 0; i < 4; ++i) {
                int x = xpos + x_move[i];
                int y = ypos + y_move[i];

                if (!inTheMatrix(x,y)) continue;
                int s = (step + 1) % 3;
                long d = 0;
                if (s == 0) {
                    d = T + matrix[x][y];
                } else {
                    d = T;
                }

                if (dp[s][x][y] > dp[step][xpos][ypos] + d) {
                    dp[s][x][y] = dp[step][xpos][ypos] + d;
                    pq.add(new Node(x,y,s,dp[s][x][y]));
                }
            }
        }
        System.out.println(Long.min(Long.min(dp[0][N][N], dp[1][N][N]), dp[2][N][N]));

    }

}
