package p_2110;
/**
 * 도현의 집 N개가 수직선 위에 있다.
 *
 * 집 여러개가 같은 좌표는 없다
 *
 * 공유기 C개를 설치하려고 한다. 많은 곳에서 와이파이 사용
 * 집에는 공유기 한 개
 *
 * "가장 인접한 두 공유기 사이의 거리를 최대로 한다"
 *
 * 집의 개수, 공유기의 개수
 *
 * 1 2 4 8 9
 *
 * distance의 가장 최소 값이 -> 3이다?
 *
 * N보다 같거나 큰 거리로 선택을 할 수 있는가?
 * yes no
 *
 *
 *
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, C;
    static long[] poses;
    static int INF = 1_000_000_000;

    public static void main(String[] args) throws Exception{
        input();
        //System.out.println(isPossible(4));
        solve();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        // init array
        poses = new long[N];

        for (int i = 0; i < N; ++i)
            poses[i] = Integer.parseInt(br.readLine());

        Arrays.sort(poses);
    }

    static boolean isPossible(int n) {
        // 가장 인접한 선택지가 N이면서 C개를 선택할 수 있는가?

        long stand = poses[0];
        int cnt = 1;

        for (int i = 1; i < N; ++i) {
            if (poses[i] - stand >= n) {
                ++cnt;
                stand = poses[i];
                if (cnt >= C) return true;
            }
        }

        return false;
    }

    static void solve() {
        int left = 1; int right = INF;
        int mid = 0;
        while (left <= right)
        {

            mid = (left + right) / 2;

            //System.out.println(left + " " + right + " " + mid);

            if (isPossible(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        System.out.println(right);
    }
}
