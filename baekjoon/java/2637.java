
import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static List<int[]>[] adj; // adj[from] = {to, count}
    static int[] indegree;
    static boolean[] isBase; 
    static int[][] dp; 
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine()); 
        M = Integer.parseInt(br.readLine()); 

        adj = new ArrayList[N + 1];
        indegree = new int[N + 1];
        isBase = new boolean[N + 1];
        dp = new int[N + 1][N + 1];

        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()); 
            int y = Integer.parseInt(st.nextToken()); 
            int k = Integer.parseInt(st.nextToken()); 

            adj[y].add(new int[]{x, k}); // y → x
            indegree[x]++;
        }

        for (int i = 1; i < N; i++) {
            if (indegree[i] == 0) isBase[i] = true;
        }
    }

    static void solve() {
        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            if (isBase[i]) {
                q.add(i);
                dp[i][i] = 1;
            }
        }

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int[] edge : adj[cur]) {
                int next = edge[0];
                int count = edge[1];

                for (int i = 1; i <= N; i++) {
                    dp[next][i] += dp[cur][i] * count;
                }

                if (--indegree[next] == 0) {
                    q.add(next);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (isBase[i] && dp[N][i] > 0) {
                System.out.println(i + " " + dp[N][i]);
            }
        }
    }
}
