/*
* N, M (V, E)
* A, B -> 시작에서 끝점
* K , G -> 고돌라가 방문하는 교차로
*
* 양방향
*
*
* */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int V, E, A, B, K, G;
    static int[] tours;
    static ArrayList<int[]>[] adj;
    static PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> {
        return Long.compare(a[1], b[1]);
    });
    static long[][] blocked, blockedStart;


    public static void main(String[] args) throws Exception {
        input();
        simulateKing();
        Dijkstra();
    }

    static void Dijkstra() {
        long[] dis = new long[V+1];
        Arrays.fill(dis, Long.MAX_VALUE);

        pq.add(new long[] {A, K});
        dis[A] = K;

        while (!pq.isEmpty())
        {
            long[] node = pq.poll();
            int n = (int) node[0];
            long w = node[1];

            if (w > dis[n]) continue;

            for (int[] nextNode : adj[n]) {
                int nextN = nextNode[0];
                long cost = nextNode[1];

                long enterTime = w;
                if (blockedStart[n][nextN] != -1 && enterTime <= blocked[n][nextN] && enterTime >= blockedStart[n][nextN]) {
                    enterTime = blocked[n][nextN] + 1;
                }

                long v = enterTime + cost;

                if (dis[nextN] > v) {
                    dis[nextN] = v;
                    pq.add(new long[] {nextN, v});
                }
            }
        }

        System.out.println(dis[B] - K);
    }

    static void showMatrix(long[][] matrix) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void simulateKing() {
        long time = 0;
        for (int i = 0; i < G - 1; ++i) {
            int node = tours[i];
            int nextNode = tours[i+1];
            long w = 0;
            blockedStart[node][nextNode] = time;
            blockedStart[nextNode][node] = time;

            for (int[] n : adj[node]) {
                if (n[0] == nextNode) {
                    w = n[1];
                    break;
                }
            }

            blocked[node][nextNode] = time + w - 1;
            blocked[nextNode][node] = time + w - 1;
            time += w;
        }
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());

        tours = new int[G];
        adj = new ArrayList[V+1];
        for (int i = 0; i <= V; ++i)
            adj[i] = new ArrayList<>();
        blocked = new long[V+1][V+1];
        blockedStart = new long[V+1][V+1];

        for (int i = 0; i <= V; ++i) {
            Arrays.fill(blocked[i], -1);
            Arrays.fill(blockedStart[i], -1);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < G; ++i) {
            tours[i] = Integer.parseInt(st.nextToken());
        }

        int from, to, w;
        for (int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            adj[from].add(new int[] {to, w});
            adj[to].add(new int[] {from, w});
        }
    }
}