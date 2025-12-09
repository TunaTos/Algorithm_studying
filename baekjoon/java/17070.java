
import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] house;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        house = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                house[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(1, 2, 0); // (1,1)-(1,2) 가로 방향으로 시작
        System.out.println(count);
    }

    // dir: 0=가로, 1=세로, 2=대각선
    static void dfs(int x, int y, int dir) {
        if (x == N && y == N) {
            count++;
            return;
        }

        // 가로
        if (dir == 0 || dir == 2) {
            if (y + 1 <= N && house[x][y + 1] == 0) {
                dfs(x, y + 1, 0);
            }
        }

        // 세로
        if (dir == 1 || dir == 2) {
            if (x + 1 <= N && house[x + 1][y] == 0) {
                dfs(x + 1, y, 1);
            }
        }

        // 대각선
        if (x + 1 <= N && y + 1 <= N &&
                house[x][y + 1] == 0 &&
                house[x + 1][y] == 0 &&
                house[x + 1][y + 1] == 0) {
            dfs(x + 1, y + 1, 2);
        }
    }
}
