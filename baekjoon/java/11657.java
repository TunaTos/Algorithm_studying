import java.io.*;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int V, E;
    static String buffer;

    static class Edge {
        int node;
        long weight;

        Edge(int node, long weight) {
            this.node = node;
            this.weight = weight;
        }
    }

    static List<Edge>[] adj;

    public static void main(String[] args) throws IOException {
        input();
        bellmanFord();
    }

    static void input() throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        adj = new ArrayList[V + 1];
        for (int i = 0; i <= V; ++i)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < E; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            long weight = Long.parseLong(st.nextToken());

            adj[from].add(new Edge(to, weight));
        }
    }

    static void bellmanFord() {
        long[] dis = new long[V + 1];
        Arrays.fill(dis, Long.MAX_VALUE);
        dis[1] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int j = 1; j <= V; j++) {
                for (Edge nextEdge : adj[j]) {
                    int nextNode = nextEdge.node;
                    long weight = nextEdge.weight;

                    if (dis[j] != Long.MAX_VALUE && dis[nextNode] > dis[j] + weight)
                        dis[nextNode] = dis[j] + weight;
                }
            }
        }

        for (int i = 1; i <= V; ++i) {
            for (Edge nextEdge : adj[i]) {
                int nextNode = nextEdge.node;
                long weight = nextEdge.weight;
                if (dis[i] != Long.MAX_VALUE && dis[nextNode] > dis[i] + weight) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        for (int i = 2; i <= V; ++i) {
            if (dis[i] == Long.MAX_VALUE)
                System.out.println(-1);
            else
                System.out.println(dis[i]);
        }
    }
}
