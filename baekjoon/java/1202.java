/**
 * Memory : 152900
 * Time : 1752
 */
package p_1202;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, K;
    static long[][] gems; // 무게, 가치
    static long[] bags;
    static PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(b[1], a[1]));
    static long res;
    public static void main(String[] args) throws Exception{
        input();
        sortArrays();
        solve();
        System.out.println(res);
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // init datastructures
        gems = new long[N][2];
        bags = new long[K];

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            gems[i][0] = Long.parseLong(st.nextToken());
            gems[i][1] = Long.parseLong(st.nextToken());
        }

        for (int i = 0; i < K; ++i) {
            st = new StringTokenizer(br.readLine());
            bags[i] = Long.parseLong(st.nextToken());
        }
    }

    static void sortArrays() {
        Arrays.sort(gems, (a,b) -> Long.compare(a[0], b[0]));
        Arrays.sort(bags);
    }

    static void solve() {
        int bIdx = 0, gIdx = 0;

        for (bIdx = 0; bIdx < K; ++bIdx) {
            while (gIdx < N && gems[gIdx][0] <= bags[bIdx]) {
                pq.add(new long[] {gems[gIdx][0], gems[gIdx][1]});
                ++gIdx;
            }
            if (!pq.isEmpty())
                res += pq.poll()[1];

        }
    }

}
