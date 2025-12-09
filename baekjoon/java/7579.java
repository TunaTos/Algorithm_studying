
import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N, M;
    static int[] memory, cost;
    static int sumCost;

    public static void main(String[] args) throws IOException {
        // 입력
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());  
        M = Integer.parseInt(st.nextToken());  

        memory = new int[N];
        cost = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            memory[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
            sumCost += cost[i]; 
        }

        int[][] dp = new int[N + 1][sumCost + 1];

        for (int i = 1; i <= N; i++) {
            int mem = memory[i - 1];
            int cst = cost[i - 1];

            for (int j = 0; j <= sumCost; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= cst) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - cst] + mem);
                }
            }
        }

        for (int j = 0; j <= sumCost; j++) {
            if (dp[N][j] >= M) {
                System.out.println(j);
                return;
            }
        }
    }
}
