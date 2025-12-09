import java.util.*;

public class Main {
    static final int MAX_VERT = 10001;
    static int V, E, From, To;
    static List<Pair> adj[] = new ArrayList[MAX_VERT];
    static List<Pair> r_adj[] = new ArrayList[MAX_VERT];
    static int[] indegree, r_indegree;

    static class Pair {
        long weight;
        int to;

        Pair(long weight, int to) {
            this.weight = weight;
            this.to = to;
        }
    }

    // Function to show the vector (not used here but kept for debugging)
    static void showVec(int[] vec) {
        for (int i = 1; i <= V; i++) {
            System.out.print(vec[i] + " ");
        }
        System.out.println();
    }

    static void input() {
        Scanner sc = new Scanner(System.in);
        V = sc.nextInt();
        E = sc.nextInt();
        indegree = new int[V + 1];
        r_indegree = new int[V + 1];
        
        for (int i = 1; i <= V; i++) {
            adj[i] = new ArrayList<>();
            r_adj[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < E; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            long weight = sc.nextLong();
            indegree[to]++;
            r_indegree[from]++;
            adj[from].add(new Pair(weight, to));
            r_adj[to].add(new Pair(weight, from));
        }
        From = sc.nextInt();
        To = sc.nextInt();
    }

    static long[] getDistance(List<Pair>[] adj, int[] indegree, int start) {
        long[] res = new long[V + 1];
        Arrays.fill(res, 0);
        Queue<Integer> q = new LinkedList<>();
        q.add(start);

        while (!q.isEmpty()) {
            int node = q.poll();

            for (Pair ele : adj[node]) {
                long cost = ele.weight;
                int to = ele.to;

                res[to] = Math.max(res[to], res[node] + cost);
                indegree[to]--;
                if (indegree[to] == 0)
                    q.add(to);
            }
        }
        return res;
    }

    static int getResult(long[] distance, long[] r_distance) {
        int res = 0;
        for (int i = 1; i <= V; i++) {
            for (Pair ele : adj[i]) {
                int j = ele.to;
                long v = ele.weight;

                if (distance[i] + r_distance[j] + v == distance[To]) {
                    res++;
                }
            }
        }
        return res;
    }

    static void solve() {
        input();
        long[] Distance = getDistance(adj, indegree, From);
        long[] R_Distance = getDistance(r_adj, r_indegree, To);
        int edgeNum = getResult(Distance, R_Distance);

        System.out.println(Distance[To]);
        System.out.println(edgeNum);
    }

    public static void main(String[] args) {
        solve();
    }
}
