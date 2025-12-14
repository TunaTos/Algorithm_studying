import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int Row, Col, sXpos, sYpos;
    static boolean[][][] visited;
    static char[][] matrix;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(bfs());
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        matrix = new char[Row + 1][Col + 1];
        visited = new boolean[64][Row + 1][Col + 1];

        for (int i = 1; i <= Row; i++) {
            String line = br.readLine();
            for (int j = 1; j <= Col; j++) {
                char c = line.charAt(j - 1);
                matrix[i][j] = c;

                if (c == '0') {
                    sXpos = i;
                    sYpos = j;
                }
            }
        }
    }

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        // [0]: keyState, [1]: x, [2]: y, [3]: distance

        visited[0][sXpos][sYpos] = true;
        q.add(new int[]{0, sXpos, sYpos, 0});

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int keyState = cur[0], x = cur[1], y = cur[2], dist = cur[3];

            if (matrix[x][y] == '1') return dist;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 1 || ny < 1 || nx > Row || ny > Col) continue;
                char next = matrix[nx][ny];

                if (next == '#') continue;

                int newKeyState = keyState;

                if ('a' <= next && next <= 'f') {
                    newKeyState |= (1 << (next - 'a'));
                }

                if ('A' <= next && next <= 'F') {
                    if ((keyState & (1 << (next - 'A'))) == 0) continue;
                }

                if (!visited[newKeyState][nx][ny]) {
                    visited[newKeyState][nx][ny] = true;
                    q.add(new int[]{newKeyState, nx, ny, dist + 1});
                }
            }
        }

        return -1;
    }
}
