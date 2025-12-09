import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String buffer;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, K, res;
    static Set<Character>[] list;
    static boolean[] selected; // 선택된 알파벳을 저장할 배열
    static char[] alpha = "abcdefghijklmnopqrstuvwxyz".toCharArray(); // 모든 알파벳

    public static void main(String[] args) throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        if (K < 5) {
            System.out.println(0);
            System.exit(0);
        }

        list = new HashSet[N + 1];
        selected = new boolean[26]; // 알파벳 26개

        // a, c, n, t, i는 반드시 포함
        selected['a' - 'a'] = true;
        selected['c' - 'a'] = true;
        selected['n' - 'a'] = true;
        selected['t' - 'a'] = true;
        selected['i' - 'a'] = true;

        for (int i = 1; i <= N; i++) {
            list[i] = new HashSet<>();
            buffer = br.readLine();
            for (int j = 0; j < buffer.length(); j++) {
                list[i].add(buffer.charAt(j));
            }
        }

        dfs(0, 0);
        System.out.println(res);
    }

    static void dfs(int idx, int dpt) {
        if (dpt == K - 5) {
            int tmp = 0;

            for (int i = 1; i <= N; i++) {
                boolean canRead = true;
                for (char c : list[i]) {
                    if (!selected[c - 'a']) {
                        canRead = false;
                        break;
                    }
                }
                if (canRead) {
                    tmp++;
                }
            }

            res = Math.max(res, tmp);
            return;
        }

        for (int i = idx; i < 26; i++) {
            if (!selected[i]) {
                selected[i] = true;
                dfs(i + 1, dpt + 1);
                selected[i] = false;
            }
        }
    }
}