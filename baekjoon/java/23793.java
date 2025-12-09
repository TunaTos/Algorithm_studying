
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static String buffer;
    static final long INF = Long.MAX_VALUE;

    static class Edge implements Comparable<Edge> {
        int node;
        long weight;

        Edge(int node, long weight) {
            this.node = node;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.weight, o.weight);
        }

        @Override
        public String toString() {
            return "Edge [node=" + node + ", weight=" + weight + "]";
        }
    }

    static int V, E, S, M, T;
    static List<Edge>[] adj;

    public static void main(String[] args) throws IOException {
        input();
        long[] startDistance = Dijkstra(S, true);
        long[] startDistanceWithoutMid = Dijkstra(S, false);
        long[] midDistance = Dijkstra(M, true);

        if (startDistance[M] != INF && midDistance[T] != INF)
            sb.append(startDistance[M] + midDistance[T]).append(" ");
        else
            sb.append("-1 ");

        if (startDistanceWithoutMid[T] == INF)
            sb.append("-1\n");
        else
            sb.append(startDistanceWithoutMid[T]).append("\n");

        bw.write(sb.toString());
        bw.flush();
    }

    static void input() throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        adj = new ArrayList[V + 1];
        for (int i = 0; i <= V; i++)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < E; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            long w = Long.parseLong(st.nextToken());
            adj[from].add(new Edge(to, w));
        }
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        S = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
    }

    static long[] Dijkstra(int start, boolean midContain) {
        long[] dis = new long[V + 1];
        Arrays.fill(dis, INF);
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        dis[start] = 0;
        pq.add(new Edge(start, 0));

        while (!pq.isEmpty()) {
            int node = pq.peek().node;
            long weight = pq.peek().weight;
            pq.poll();

            if (dis[node] < weight)
                continue;

            for (Edge next : adj[node]) {
                int nextNode = next.node;
                long cost = next.weight;

                if (!midContain && nextNode == M)
                    continue;

                if (dis[nextNode] > dis[node] + cost) {
                    dis[nextNode] = dis[node] + cost;
                    pq.add(new Edge(nextNode, dis[nextNode]));
                }
            }
        }
        return dis;
    }
}
