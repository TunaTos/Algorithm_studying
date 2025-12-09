import java.util.*;
import java.io.*;

public class Main {
    static int V, E;
    static long[][] matrix;
    static final long INF = 1000000000L;  // 적당히 큰 값 (최대 값이 Long.MAX_VALUE에 가까운 값으로 설정)

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String buffer;
    static long res = INF;  // 결과를 INF로 초기화

    public static void main(String[] args) throws IOException {
        input();
        Floyd();
        
        boolean isPossible = false;
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                long val1 = matrix[i][j];
                long val2 = matrix[j][i];
                
                if (i == j)
                    continue;
                if (val1 == INF || val2 == INF)
                    continue;
                
                res = Math.min(res, val1 + val2);
            }
        }

        if (res == INF)
            System.out.println(-1);
        else
            System.out.println(res);
    }

    static void showMatrix() {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void input() throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        matrix = new long[V + 1][V + 1];

        for (int i = 0; i <= V; i++) {
            Arrays.fill(matrix[i], INF);
            matrix[i][i] = 0;
        }

        int from, to;
        long cost;
        for (int i = 0; i < E; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);

            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            cost = Long.parseLong(st.nextToken());

            matrix[from][to] = Math.min(matrix[from][to], cost);  // 최소 비용으로 갱신
        }
    }

    static void Floyd() {
        for (int k = 1; k <= V; k++) {
            for (int s = 1; s <= V; s++) {
                for (int e = 1; e <= V; e++) {
                    if (matrix[s][e] > matrix[s][k] + matrix[k][e]) {
                            matrix[s][e] = matrix[s][k] + matrix[k][e];
                        }
                    }
                }
            }
        }
    }

