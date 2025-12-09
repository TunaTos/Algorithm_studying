import java.util.*;
import java.io.*;

public class Main {
    static int V, E, Start, End;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String buffer;

    static class Edge implements Comparable<Edge> {
        long weight;
        int node;

        public Edge(long weight, int node) {
            this.weight = weight;
            this.node = node;
        }

        @Override
        public int compareTo(Edge other) {
            return Long.compare(this.weight, other.weight);
        }
    }

    static List<Edge>[] adj;

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(Dijkstra());
    }

    static void input() throws IOException {
        V = Integer.parseInt(br.readLine());
        E = Integer.parseInt(br.readLine());

        adj = new ArrayList[V + 1];
        for (int i = 0; i <= V; ++i)
            adj[i] = new ArrayList<>(); // ArrayList 초기화

        for (int i = 0; i < E; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);

            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            long weight = Long.parseLong(st.nextToken());

            adj[from].add(new Edge(weight, to));
        }

        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        Start = Integer.parseInt(st.nextToken());
        End = Integer.parseInt(st.nextToken());
    }

    static long Dijkstra() {
        long[] distance = new long[V + 1];
        Arrays.fill(distance, Long.MAX_VALUE);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0, Start));
        distance[Start] = 0; // 시작점 거리 0으로 설정

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();

            int node = edge.node;
            long weight = edge.weight;

            if (distance[node] < weight) // 현재 노드의 최단 거리가 현재까지 알려진 최단 거리보다 크면 무시
                continue;

            for (Edge nextEdge : adj[node]) {
                int next = nextEdge.node;
                long cost = nextEdge.weight;

                if (distance[next] > distance[node] + cost) {
                    distance[next] = distance[node] + cost;
                    pq.add(new Edge(distance[next], next));
                }
            }
        }

        return distance[End];
    }
}