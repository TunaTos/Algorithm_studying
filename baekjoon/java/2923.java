package p_2923;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int[] aNums, bNums;

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }

    static void solve() {
        int[] aCount = new int[100];
        int[] bCount = new int[100];

        for (int round = 1; round <= N; ++round) {
            int a = aNums[round];
            int b = bNums[round];

            aCount[a]++;
            bCount[b]++;

            // greedy matching with counting arrays
            int aIdx = 0;
            int bIdx = 99;

            int[] aTmp = aCount.clone(); // 원본 유지
            int[] bTmp = bCount.clone();

            int maxSum = 0;

            while (aIdx < 100 && bIdx >= 0) {
                if (aTmp[aIdx] == 0) {
                    aIdx++;
                    continue;
                }
                if (bTmp[bIdx] == 0) {
                    bIdx--;
                    continue;
                }

                int pair = Math.min(aTmp[aIdx], bTmp[bIdx]);
                maxSum = Math.max(maxSum, aIdx + bIdx);

                aTmp[aIdx] -= pair;
                bTmp[bIdx] -= pair;
            }

            System.out.println(maxSum);
        }
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());

        aNums = new int[N + 1];
        bNums = new int[N + 1];

        for (int i = 1; i <= N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            aNums[i] = Integer.parseInt(st.nextToken());
            bNums[i] = Integer.parseInt(st.nextToken());
        }
    }
}
