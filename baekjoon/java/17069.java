
import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] map;
    static long[][][] dp; 

    static final int HORIZONTAL = 0;
    static final int DIAGONAL = 1;
    static final int VERTICAL = 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        map = new int[N + 1][N + 1];
        dp = new long[3][N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[HORIZONTAL][i][j] = -1;
                dp[DIAGONAL][i][j] = -1;
                dp[VERTICAL][i][j] = -1;
            }
        }


        System.out.println(dfs(HORIZONTAL, 1, 2));
    }

    static long dfs(int dir, int x, int y) {
        if (x > N || y > N || map[x][y] == 1)
            return 0;

        if (x == N && y == N)
            return 1;

        if (dp[dir][x][y] != -1)
            return dp[dir][x][y];

        long res = 0;

        if (dir == HORIZONTAL) {
            if (y + 1 <= N && map[x][y + 1] == 0)
                res += dfs(HORIZONTAL, x, y + 1);

            if (x + 1 <= N && y + 1 <= N &&
                map[x][y + 1] == 0 &&
                map[x + 1][y] == 0 &&
                map[x + 1][y + 1] == 0)
                res += dfs(DIAGONAL, x + 1, y + 1);
        }

        else if (dir == VERTICAL) {
            if (x + 1 <= N && map[x + 1][y] == 0)
                res += dfs(VERTICAL, x + 1, y);

            if (x + 1 <= N && y + 1 <= N &&
                map[x][y + 1] == 0 &&
                map[x + 1][y] == 0 &&
                map[x + 1][y + 1] == 0)
                res += dfs(DIAGONAL, x + 1, y + 1);
        }

        else {
            if (y + 1 <= N && map[x][y + 1] == 0)
                res += dfs(HORIZONTAL, x, y + 1);

            if (x + 1 <= N && map[x + 1][y] == 0)
                res += dfs(VERTICAL, x + 1, y);

            if (x + 1 <= N && y + 1 <= N &&
                map[x][y + 1] == 0 &&
                map[x + 1][y] == 0 &&
                map[x + 1][y + 1] == 0)
                res += dfs(DIAGONAL, x + 1, y + 1);
        }

        dp[dir][x][y] = res;
        return res;
    }
}
