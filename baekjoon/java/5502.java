/*
* 최소 개수의 문자를 삽입해서 필린드롬이 되게 하는 것
*
* dp[a][b] -> a에서 b까지의 최장 팰린드롬
*
* dp[a][b]
*       만약 끝의 문자열이 같다면?
*           dp[a][b] = dp[a-1][b-1]
*       만약 끝이 다르다면?
*           dp[a][b] = max(dp[a-1][b], dp[a][b-1]) + 1 <움직이는거>

*
* */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long[][] dp;
    static String str;
    static int N;

    public static void main(String[] args) throws Exception {
        input();
        dfs(0, N-1);

        // showMatrix();;
        System.out.println(N - dp[0][N-1]);
    }

    static void showMatrix() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());
        dp = new long[N+1][N+1];
        str = br.readLine();
        for (int i = 0; i <= N; ++i)
            Arrays.fill(dp[i], -1);


    }

    static long dfs(int left, int right) {
        if (left > right) return 0;
        if (left == right) return 1;
        if (dp[left][right] != -1) return dp[left][right];

        if (str.charAt(left) == str.charAt(right)) {
            return dp[left][right] = 2 + dfs(left+1, right-1);
        }
        else {
            long a = dfs(left+1, right);
            long b = dfs(left, right-1);

            return dp[left][right] = Math.max(a,b);
        }
    }

}
