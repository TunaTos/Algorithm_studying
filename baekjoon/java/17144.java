import java.io.*;
import java.util.*;

public class Main {

    static final int MAX_LEN = 51;
    static final int MACHINE = -1;

    static int Row, Col, Tcase, cnt, dust1, dust2;
    static int[][] Matrix = new int[MAX_LEN][MAX_LEN];
    static int[] x_move = {-1, 1, 0, 0}, y_move = {0, 0, -1, 1};
    static Queue<int[]> pos = new LinkedList<>();
    static Queue<int[]> q = new LinkedList<>();
    static boolean[][] visited = new boolean[MAX_LEN][MAX_LEN];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
        Tcase = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= Row; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= Col; j++) {
                Matrix[i][j] = Integer.parseInt(st.nextToken());
                if (Matrix[i][j] == MACHINE) {
                    if (cnt == 0) {
                        dust1 = i; cnt++;
                    } else {
                        dust2 = i;
                    }
                }
                if (Matrix[i][j] >= 1) {
                    visited[i][j] = true;
                    pos.offer(new int[]{i, j});
                    if (Matrix[i][j] >= 5) q.offer(new int[]{Matrix[i][j], i, j});
                }
            }
        }

        for (int t = 0; t < Tcase; t++) {
            spread();
            sweepDust();
            for (int i = 1; i <= Row; i++) {
                for (int j = 1; j <= Col; j++) {
                    if (Matrix[i][j] >= 5) q.offer(new int[]{Matrix[i][j], i, j});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= Row; i++) {
            for (int j = 1; j <= Col; j++) {
                if (Matrix[i][j] != MACHINE)
                    result += Matrix[i][j];
            }
        }

        System.out.println(result);
    }

    static void spread() {
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int dust = curr[0];
            int xpos = curr[1];
            int ypos = curr[2];
            int val = dust / 5;

            int count = 0;
            for (int i = 0; i < 4; i++) {
                int x = xpos + x_move[i];
                int y = ypos + y_move[i];
                if (!inMatrix(x, y) || Matrix[x][y] == MACHINE) continue;
                Matrix[x][y] += val;
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    pos.offer(new int[]{x, y});
                }
                count++;
            }
            Matrix[xpos][ypos] -= val * count;
        }
    }

    static void sweepDust() {
        for (int i = dust1 - 1; i > 1; i--) Matrix[i][1] = Matrix[i - 1][1];
        Matrix[1][1] = 0;
        for (int i = 1; i < Col; i++) Matrix[1][i] = Matrix[1][i + 1];
        for (int i = 1; i < dust1; i++) Matrix[i][Col] = Matrix[i + 1][Col];
        for (int i = Col; i > 2; i--) Matrix[dust1][i] = Matrix[dust1][i - 1];
        Matrix[dust1][2] = 0;

        for (int i = dust2 + 1; i < Row; i++) Matrix[i][1] = Matrix[i + 1][1];
        Matrix[Row][1] = 0;
        for (int i = 1; i < Col; i++) Matrix[Row][i] = Matrix[Row][i + 1];
        for (int i = Row; i > dust2; i--) Matrix[i][Col] = Matrix[i - 1][Col];
        for (int i = Col; i > 2; i--) Matrix[dust2][i] = Matrix[dust2][i - 1];
        Matrix[dust2][2] = 0;
    }

    static boolean inMatrix(int x, int y) {
        return x >= 1 && x <= Row && y >= 1 && y <= Col;
    }
}
