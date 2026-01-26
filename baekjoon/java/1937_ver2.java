/**
 * n * n의 대나무 숲
 *
 * 상, 하, 좌, 우 움직인다
 * 대나무가 더 많은 곳으로 가야한다.
 *
 * 어디에 처음 놓아야 하나? and 어디로 움직여야하나?
 *
 * dp[x][y] -> {x,y}에서 시작해서 움직일 수 있는 최대값.
 *
 *
 */
package p_1937;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] matrix;
    static long[][] dp;
    static final int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
    static int N;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        //showDp();
    }

    static void showDp() {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void input() throws Exception{
        N = Integer.parseInt(br.readLine());

        // init
        matrix = new int [N+1][N+1];
        dp = new long [N+1][N+1];

        for (int i = 1; i <= N; ++i)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; ++j)
            {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
    }

    static long dfs(int xpos, int ypos) {
        long val = 0;
        if (dp[xpos][ypos] != -1)
            return dp[xpos][ypos];


        for (int i = 0; i < 4; ++i) {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];

            if (!inTheMatrix(x,y)) continue;
            if (matrix[x][y] <= matrix[xpos][ypos]) continue;

            val = Long.max(val, dfs(x,y));
        }

        dp[xpos][ypos] = 1 + val;
        return dp[xpos][ypos];
    }

    static void solve() {
        long res = -1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                res = Long.max(res,dfs(i,j));
            }
        }

        System.out.println(res);
    }
}
