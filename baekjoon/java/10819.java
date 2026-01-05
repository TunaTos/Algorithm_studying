/**
 * permutation
 *
 */
package p_10819;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, res = -1;
    static int[] numbers, selected;
    static boolean[] visited;

    public static void main(String[] args) throws Exception{
        input();
        dfs(0);
        System.out.println(res);
    }

    static void input() throws Exception{
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        // init container
        numbers = new int[N];
        selected = new int[N];
        visited = new boolean[N];

        for (int i = 0; i < N; ++i)
            numbers[i] = Integer.parseInt(st.nextToken());
    }

    static int getResult(int[] arr) {
        int res = 0;

        for (int i = 0; i < N - 1; ++i)
            res += Math.abs(arr[i] - arr[i+1]);

        return res;
    }

    static void dfs(int idx) {
        if (idx == N) {
            res = Math.max(res, getResult(selected));
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                selected[idx] = numbers[i];
                dfs(idx+1);

                visited[i] = false;
            }
        }
    }
}
