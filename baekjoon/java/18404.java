package p_18404;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class  Edge {
        int xpos;
        int ypos;

        Edge(int xpos, int ypos) {
            this.xpos = xpos;
            this.ypos = ypos;
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] x_move = {-2,-1,1,2,2,1,-1,-2};
    static int[] y_move = {1,2,2,1,-1,-2,-2,-1};
    static int[][] matrix;
    static boolean[][] visited;
    static int N, M;
    static Edge sPos;
    static Edge[] targets;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws  Exception{
        input();
        bfs();
        for (int i = 1; i <= M; ++i) {
            sb.append(matrix[targets[i].xpos][targets[i].ypos]).append(" ");
        }
        System.out.println(sb.toString());
    }

    static void bfs() {
        ArrayDeque<int[]> q = new ArrayDeque<>(); // {x,y,d}
        q.addLast(new int[] {sPos.xpos, sPos.ypos, 0});
        visited[sPos.xpos][sPos.ypos] = true;

        while (!q.isEmpty()) {
            int[] node = q.pollFirst();
            int x = node[0];
            int y = node[1];
            int d = node[2];

            for (int i = 0; i < 8; ++i) {
                int nextX = x + x_move[i];
                int nextY = y + y_move[i];

                if (!inTheMatrix(nextX, nextY)) continue;
                if (visited[nextX][nextY]) continue;

                matrix[nextX][nextY] = d + 1;
                visited[nextX][nextY] = true;
                q.addLast(new int[] {nextX, nextY, matrix[nextX][nextY]});
            }
        }
    }



    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
    }

    static void input() throws  Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());


        // init container
        matrix = new int[N+1][N+1];
        visited = new boolean[N+1][N+1];
        targets = new Edge[M+1];

        int x, y;

        st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        sPos = new Edge(x,y);

        for (int i = 1; i <= M; ++i) {
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());

            targets[i] = new Edge(x,y);
        }
    }
}
