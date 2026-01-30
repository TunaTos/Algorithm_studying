package p_2283;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static long K;

    static final int MAX = 1_000_000;

    static int[] diff;
    static int[] cover;

    public static void main(String[] args) throws Exception {
        input();



        solve();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Long.parseLong(st.nextToken());

        diff = new int[MAX + 2];

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());

            diff[l] += 1;
            diff[r] -= 1;
        }

        cover = new int[MAX];
        int cur = 0;


        for (int x = 0; x < MAX; ++x) {
            cur += diff[x];
            cover[x] = cur;
        }
    }

    static void solve() {
        int l = 0, r = 0;
        long sum = 0;

        while (true) {

            if (sum < K) {
                if (r == MAX) break;
                sum += cover[r];
                r++;
            }


            else if (sum > K) {
                sum -= cover[l];
                l++;
            }



            else {
                System.out.println(l + " " + r);
                return;
            }
        }

        System.out.println("0 0");
    }
}
