/**
 * N개의 영어 단어를 사용해서 M인 새로운 단어를 만든다
 * N개의 단어를 순서대로 이어 붙인다
 * 단어 사이에 _를 넣어서 만든다
 * 새로운 단어의 길이가 M이 아닌 경우 _를 붙여서 M으로 만든다
 *
 * _는 단어와 단어 사이에 가능
 * 단어와 단어 사이에 있는 _의 개수는 같아야 한다.
 * 불가능한 경우 -> 단어 사이에 있는 _의 최댓값과 최솟값의 차이는 1
 *
 */
package p_1474;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        String[] w = new String[N];
        int len = 0;
        for (int i = 0; i < N; i++) {
            w[i] = br.readLine();
            len += w[i].length();
        }

        int slots = N - 1;
        int U = M - len;
        int base = U / slots;
        int rem = U % slots;

        int[] gap = new int[slots];
        Arrays.fill(gap, base);

        boolean[] extra = new boolean[slots];

        for (int i = 0; i < slots && rem > 0; i++) {
            char c = w[i + 1].charAt(0);
            if ('a' <= c && c <= 'z') {
                gap[i]++;
                extra[i] = true;
                rem--;
            }
        }

        for (int i = slots - 1; i >= 0 && rem > 0; i--) {
            if (extra[i]) continue;
            gap[i]++;
            rem--;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(w[0]);
        for (int i = 0; i < slots; i++) {
            for (int k = 0; k < gap[i]; k++) sb.append('_');
            sb.append(w[i + 1]);
        }

        System.out.println(sb);
    }
}