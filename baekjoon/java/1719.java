import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static final long INF = 987654321;
    static long[][] matrix;
    static int[][] result;    
    static int V, E;

    public static void main(String[] args) throws IOException {
        input();
        Floyd();
        showMatrix();
    }

    static void showMatrix() {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (i == j) System.out.print("- ");
                else System.out.printf("%d ", result[i][j]);
            }
            System.out.println();
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        matrix = new long[V + 1][V + 1];
        result = new int[V + 1][V + 1];

        for (int i = 1; i <= V; i++) {
            Arrays.fill(matrix[i], INF);
            matrix[i][i] = 0;
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());
            long w = Long.parseLong(st.nextToken());

            // 더 작은 가중치의 간선으로 업데이트
            if (matrix[n1][n2] > w) {
                matrix[n1][n2] = matrix[n2][n1] = w;
                result[n1][n2] = n2; // 초기에는 바로 가는 경로이므로 n2
                result[n2][n1] = n1; // 양방향 간선 처리
            }
        }
    }

    static void Floyd() {
        for (int k = 1; k <= V; k++) {
            for (int i = 1; i <= V; i++) {
                for (int j = 1; j <= V; j++) {
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                            matrix[i][j] = matrix[i][k] + matrix[k][j];

                            // 가장 먼저 가야 하는 집하장은 i에서 k로 가는 최단 경로의 첫 번째 노드
                            result[i][j] = result[i][k];
                        }
                    }
                }
            }
        }
    }
}
