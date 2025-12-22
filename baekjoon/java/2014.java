/**
 * fail : 지피티 참고했음
 *
 * good
 *      입력 데이터를 어떻게 필터링 해야하는가?라는 문제로 치환까지는 됨
 * bad
 *      어떤 조건으로 필터링 조건을 찾지 못함
 *      문제가 왜 "소수"인지, "오름차순"으로 되어 있는지를 조금 더 분석했으면 좋았을 것 같음
 */
package p_2014;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    static int K, N;
    static ArrayList<Long> nums = new ArrayList<>();
    static TreeMap<Long, Boolean> tm = new TreeMap<>();

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; ++i) {
            long p = Long.parseLong(st.nextToken());
            nums.add(p);
            tm.put(p, true);
        }

        final long LIMIT = 1L << 31;

        long res = 0L;

        for (int i = 1; i <= N; ++i) {
            Map.Entry<Long, Boolean> firstEntry = tm.pollFirstEntry();
            long k = firstEntry.getKey();
            res = k;

            for (long p : nums) {

                if (k > LIMIT / p) break;
                long nextKey = k * p;
                if (nextKey >= LIMIT) break;

                if (!tm.containsKey(nextKey)) {
                    tm.put(nextKey, true);
                }
                if (k % p == 0) break;
            }
        }

        System.out.println(res);
    }
}
