/*
 * 하루 이용권은 만원
 * 3일 연속 할인권을 25,000 (쿠폰 1)
 * 5일 이용권 37,000 (쿠폰 2)
 * 쿠폰3장 -> 하루 이용권
 *
 * 기간권 -> 모두 이용할 필요는 없음
 *
 * 연속이라면
 *   -> 연속권이 무조건 더 좋음
 * 연속이 아니라면?
 *   -> 잘 모르겠음
 * 연속을 먼저 솎아내는 방법? -> greedy? -> no -> testcase
 *
 * 그러면 DP
 * 티켓의 개수를 어떻게 처리할 것인가?
 * 3개면 하루 이용권
 * 마지막 티켓이 0개라면?
 * 마지막 티켓이 1개라면?
 * 마지막 티켓이 2개라면?
 * 마지막 티켓이 3개라면?
 * 마지막 티켓이 4개라면?
 * .
 * .
 * .
 * 마지막 티켓이 40개라면?
 *
 *
 * 쿠폰을 언제 써야하는가??
 *   빨리 쓰는게 더 이득일까? (No)
 *   case 5)
 *   11111 -> 37000
 *   c1111 -> 40000
 *   case 3)
 *   111 -> 25000
 *   c11 -> 20000
 *
 * bool flag -> canVisit
 *
 *
 *
 *
 * */


package p_13302;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M;
    static boolean[] notVisit;
    static long[][] dp; // dp[day][coupon]
    static final long INF = Long.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        notVisit = new boolean[N + 6];
        dp = new long[N + 6][41];

        for (long[] row : dp) Arrays.fill(row, INF);
        dp[0][0] = 0;



        if (M > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < M; ++i) {
                notVisit[Integer.parseInt(st.nextToken())] = true;
            }
        }
    }

    static void solve() {
        for (int i = 1; i <= N; i++) {
            for (int c = 0; c <= 40; c++) {
                if (dp[i-1][c] == INF) continue;
                long prev = dp[i-1][c];

                if (notVisit[i]) {
                    dp[i][c] = Math.min(dp[i][c], prev);
                } else {
                    dp[i][c] = Math.min(dp[i][c], prev + 10_000);



                    if (c + 3 <= 40 && dp[i-1][c+3] != INF)
                        dp[i][c] = Math.min(dp[i][c], dp[i-1][c+3]);



                    int next3 = Math.min(i + 2, N);
                    if (c + 1 <= 40)
                        dp[next3][c+1] = Math.min(dp[next3][c+1], prev + 25_000);



                    int next5 = Math.min(i + 4, N);
                    if (c + 2 <= 40)
                        dp[next5][c+2] = Math.min(dp[next5][c+2], prev + 37_000);
                }
            }
        }

        long res = INF;


        for (int c = 0; c <= 40; c++) {
            res = Math.min(res, dp[N][c]);
        }
        System.out.println(res);
    }
}