import java.io.*;
import java.util.*;

public class Main {

    static int V, E;
    static boolean flag = false;
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        solve();
    }

    static void solve() throws IOException {
        input();
        visited = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!flag) {
                dfs(i, 1);
            }
            Arrays.fill(visited, false);  // 방문 배열 초기화
        }

        System.out.println(flag ? 1 : 0);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());

            adj.get(node1).add(node2);
            adj.get(node2).add(node1);
        }
    }

    static void dfs(int node, int depth) {
        if (depth == 5) {
            flag = true;
            return;
        }

        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1);
            }
        }
        visited[node] = false;
    }
}
