/**
 * A ~ Z (0,25), a ~ z (26,51)
 * 차이 x <= T
 *
 * 낮은 곳이나 같은 곳 -> 시간은 1초
 * 높은 곳으로 가면 차이의 제곱
 *
 * 어두워지는 시간 D
 * 올라갈 수 있는 최대의 높이
 *
 * 갔다가 돌아오는 것은 시간이 다르다
 *
 * 1 2 3
 * 3 4 5
 *
 * 0 1 2
 * 4 5 6
 *
 *
 *
 *
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Edge implements Comparable<Edge>{
        int xpos;
        int ypos;
        long dis;


        Edge (int xpos, int ypos, long dis) {
            this.xpos = xpos;
            this.ypos = ypos;
            this.dis = dis;
        }

        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.dis, o.dis);
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int Row, Col, T, D;
    static int[][] matrix;
    static final int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
    static long[][] dis1, dis2;
    static int res;

    public static void main(String[] args) throws Exception{
        input();
        Dijkstra(1,1, dis1, false);
        Dijkstra(1, 1, dis2, true);


        //showMatrix(dis1);
        //System.out.println();
        //showMatrix(dis2);

        solve();

        System.out.println(res);
    }
    static void solve() {
        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                if (dis1[i][j] == Long.MAX_VALUE) continue;
                if (dis2[i][j] == Long.MAX_VALUE) continue;

                if (dis1[i][j] + dis2[i][j] <= D) {
                    res = Math.max(res, matrix[i][j]);
                }
            }
        }
    }
    static void showMatrix() {
        for (int i = 1; i <= Row; ++i) {
            System.out.println(Arrays.toString(matrix[i]));
        }
    }
    static void showMatrix(long[][] matrix) {
        for (int i = 1; i <= Row; ++i) {
            System.out.println(Arrays.toString(matrix[i]));
        }
    }



    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        matrix = new int[Row+1][Col+1];
        dis1 = new long[Row+1][Col+1];
        dis2 = new long[Row+1][Col+1];

        for (int i = 1; i <= Row; ++i) {
            String str = br.readLine();
            for (int j = 1; j <= Col; ++j) {
                char c = str.charAt(j-1);

                if (Character.isUpperCase(c)) {
                    matrix[i][j] = (int) c - 'A';
                } else {
                    matrix[i][j] = (int) c - 'a' + 26;
                }

            }
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }


    static void Dijkstra(int sx, int sy, long[][] dis, boolean reverse) {
        for (int i = 1; i <= Row; ++i) Arrays.fill(dis[i], Long.MAX_VALUE);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(sx, sy, 0));
        dis[sx][sy] = 0;

        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int x = e.xpos, y = e.ypos;
            long d = e.dis;

            if (d != dis[x][y]) continue;

            for (int k = 0; k < 4; ++k) {
                int nx = x + x_move[k];
                int ny = y + y_move[k];

                if (!inTheMatrix(nx, ny)) continue;
                if (Math.abs(matrix[nx][ny] - matrix[x][y]) > T) continue;

                long w;
                if (!reverse) {
                    if (matrix[nx][ny] <= matrix[x][y]) w = 1;
                    else {
                        long diff = matrix[nx][ny] - matrix[x][y];
                        w = diff * diff;
                    }
                } else {
                    if (matrix[x][y] <= matrix[nx][ny]) w = 1;
                    else {
                        long diff = matrix[x][y] - matrix[nx][ny];
                        w = diff * diff;
                    }
                }

                long nd = dis[x][y] + w;
                if (nd < dis[nx][ny]) {
                    dis[nx][ny] = nd;
                    pq.add(new Edge(nx, ny, nd));
                }
            }
        }
    }


}
