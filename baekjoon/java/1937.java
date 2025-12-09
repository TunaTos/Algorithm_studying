
import java.util.*;

public class Main {
    static int n;
    static int[][] forest, dp;
    static int[] dx = {-1, 1, 0, 0}; // 상, 하, 좌, 우
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        forest = new int[n][n];
        dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                forest[i][j] = sc.nextInt();
                dp[i][j] = -1; // 아직 방문하지 않음
            }
        }

        int maxMoves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxMoves = Math.max(maxMoves, dfs(i, j));
            }
        }

        System.out.println(maxMoves);
    }

    static int dfs(int x, int y) {
        if (dp[x][y] != -1) return dp[x][y]; // 이미 계산된 값이면 반환

        dp[x][y] = 1; // 최소한 자기 자신 포함 (이동 안 할 경우)

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && forest[nx][ny] > forest[x][y]) {
                dp[x][y] = Math.max(dp[x][y], dfs(nx, ny) + 1);
            }
        }

        return dp[x][y];
    }
}

