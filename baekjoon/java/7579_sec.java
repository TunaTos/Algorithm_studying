/**
 * m만큼의 메모리를 사용하고 있음
 * 다시 실행하는 비용은 c이다.
 *
 * 몇개를 비활성화해서 M 바이트 이상의 가질 수 있는가?
 * M바이트를 확보하는데 다시 실행하는 비용 c를 최소화해라
 *
 *
 *
 * 일반 냅색을 쓰면 M을 넘어갈 수도 있기 때문에
 * dp[프로세스 수][M]은 안됨
 *
 * dp[프로세스 수][코스트의 수] -> 메모리의 최대값?
 *
 * dp[N(100)][sum(c)(10000)]
 *      프로세스 n개를 사용해서 특정 cost c를 만들어 낼 때의 process의 최대값
 *
 *
 */

package p_7579;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, costSum, res =Integer.MAX_VALUE;
    static long M;
    static int[] memory, cost;
    static long[][] dp;

    public static void main(String[] args) throws Exception {
        input();
        //System.out.println(Arrays.toString(memory));
        //System.out.println(Arrays.toString(cost));
        solve();
        //System.out.println();
        //showDp();
        System.out.println(res);
    }

    static void showDp() {
        for (int i = 1;i <= N; ++i)
            System.out.println(Arrays.toString(dp[i]));
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Long.parseLong(st.nextToken());

        // init container
        memory = new int[N+1];
        cost = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; ++i)
            memory[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; ++i) {
            cost[i] = Integer.parseInt(st.nextToken());
            costSum += cost[i];
        }

        dp = new long[N+1][costSum+1];
    }

    static void solve() {
        for (int i = 1; i <= N; ++i) {
            int m = memory[i];
            int c = cost[i];

            for (int j = 0; j <= costSum; ++j) {
                if (j < c) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = Long.max(dp[i-1][j], dp[i-1][j-c] + m);
                }
            }
        }


        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= costSum; ++j) {
                if (dp[i][j] >= M)
                    res = Integer.min(res,j);
            }
        }
    }
}
