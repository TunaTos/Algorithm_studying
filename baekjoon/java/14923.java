import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int Row, Col, sXpos, sYpos, eXpos, eYpos;
    static int[][] matrix;

    static boolean[][][] visited;
    static int[][][] dist;

    static int[] xMove = {-1, 1, 0, 0};
    static int[] yMove = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        input();
        int ans = bfs();
        System.out.println(ans);
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }

    static int bfs() {
        ArrayDeque<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0, sXpos, sYpos});
        visited[0][sXpos][sYpos] = true;
        dist[0][sXpos][sYpos] = 0;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int b = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == eXpos && c == eYpos) {
                return dist[b][r][c];
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + xMove[i];
                int nc = c + yMove[i];
                if (!inTheMatrix(nr, nc)) continue;

                if (matrix[nr][nc] == 0)
                {
                    if (!visited[b][nr][nc]) {
                        visited[b][nr][nc] = true;
                        dist[b][nr][nc] = dist[b][r][c] + 1;
                        q.offer(new int[]{b, nr, nc});
                    }
                }
                else
                {
                    if (b == 0 && !visited[1][nr][nc]) {
                        visited[1][nr][nc] = true;
                        dist[1][nr][nc] = dist[0][r][c] + 1;
                        q.offer(new int[]{1, nr, nc});
                    }
                }
            }
        }

        return -1;
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        sXpos = Integer.parseInt(st.nextToken());
        sYpos = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        eXpos = Integer.parseInt(st.nextToken());
        eYpos = Integer.parseInt(st.nextToken());

        matrix = new int[Row + 1][Col + 1];

        visited = new boolean[2][Row + 1][Col + 1];
        dist = new int[2][Row + 1][Col + 1];

        for (int i = 1; i <= Row; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= Col; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
}
