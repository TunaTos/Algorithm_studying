/**
 * 주어진 구슬의 무게를 확인할 수 있는가?
 *
 * 주어진 추만을 사용해서 구슬의 무게를 확인할 수 있는가?
 *
 * 추의 개수는 30 이하이다
 * 가벼운 것부터 입력이 된다
 * 같은 무게의 추는 여러 개 있을 수 있다
 * 추의 무게는 500 이하이다.
 *
 * 확인할 구슬의 개수는 7개 이하이다.
 * 구슬의 무게는 40,000이하다.
 *
 * 각각의 구슬을 쓰냐? 안쓰냐
 *
 *    0 1 2 3 4 5
 * 0  0 0 0 0 0 0
 * 1  0 1 1 1 1 1
 * 4  0 1 1 1 4 5
 *
 *    0(아무것도 안사용한거), 1(1만 사용한거), 4(4만 사용한거), 5 (1,4 사용한거)
 *
 */


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int bellNum, beedNum, bellSum;
    static long[][] dp;
    static int[] beeds, bells;
    static HashSet<Integer> hs = new HashSet<>(), bs = new HashSet<>();

    public static void main(String[] args) throws Exception {
        input();
        knapsack();
        getComb();
        long[] combs = new long[hs.size()];
        int tmp = 0;
        for (long num: hs) {
            combs[tmp++] = num;
        }

        for (int i = 0; i < combs.length; ++i) {
            for (int j = i+1; j < combs.length; ++j) {
                bs.add((int) Math.abs(combs[i] - combs[j]));
            }
        }



        for (int i  =1 ; i <= beedNum; ++i) {
            //System.out.println("I am beed " +  beeds[i]);
            if (bs.contains(beeds[i])) {
                System.out.print("Y");
            } else {
                System.out.print("N");
            }

            if (i != beedNum)
                System.out.print(" ");
        }

    }

    static void getComb() {
        for (int i = 1; i <= bellNum; ++i) {
            for (int j = 0; j <= bellSum; ++j) {
                hs.add((int) dp[i][j]);
            }
        }

    }
    static void knapsack() {

        for (int i = 1; i <= bellNum; ++i) {
            int bell = bells[i];

            for (int j = 1; j < bell; ++j) {
                dp[i][j] = dp[i-1][j];
            }
            for (int j = bell; j <= bellSum; ++j) {
                dp[i][j] = Long.max(dp[i-1][j], dp[i-1][j-bell] + bell);
            }
        }
    }

    static void input() throws Exception {
        bellNum = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        bells = new int[bellNum+1];

        for (int i = 1; i <= bellNum; ++i)
        {
            bells[i] = Integer.parseInt(st.nextToken());
            bellSum += bells[i];
        }

        beedNum = Integer.parseInt(br.readLine());
        beeds = new int[beedNum+1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= beedNum; ++i) {
            beeds[i] = Integer.parseInt(st.nextToken());
        }

        dp = new long[bellNum+1][bellSum+1];

    }


}
