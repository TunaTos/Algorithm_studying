/*
*  지헌이의 출발 위치와 성하의 출발 위치는 새로운 약속 장소 x
* 약속장소 -> 지헌이와, 성하의 최소
* 지헌이가 성하보다 더 빠르거나 같게 도착해야한다.
* 약속 장소가 여럿이라면
*   지헌이로부터 가장 가까운 곳
*   번호가 가장 작은 곳
*
* 풀이)
* 1. 지헌이에서 다익스트라
* 2. 성하에서 다익스트라
* 3. (지헌 -> n) + (성하 -> n)의 합이 최소인 노드 집합을 찾는다
* 4. n(x) 중에서 (지헌 -> n) <= (성하 -> n)
* 5. 그 중 같은 값이 있으면 n(x) 중에서 n의 값이 최소를 찾는다
*
* 시간복잡도 -> 다익스트라 2번
*
*
*
* */
package p_17270;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
    static class Node {
        int node;
        long dis;

        Node(int node, long dis) {
            this.node = node;
            this.dis = dis;
        }
    }

    static class Pair {
        long d;
        int node;

        Pair(long d, int node) {
            this.d = d;
            this.node = node;
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int V, E, jStart, sStart, res = Integer.MAX_VALUE;
    static ArrayList<Node>[] adj;
    static long[] jDis, sDis;
    static long disSum = Long.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        input();
        Dijkstra(jStart, jDis);
        Dijkstra(sStart, sDis);

        // System.out.println(Arrays.toString(jDis));
        // System.out.println(Arrays.toString(sDis));
        solve();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        // init container
        adj = new ArrayList[V+1];
        for (int i = 0; i <= V; ++i) adj[i] = new ArrayList<>();
        jDis = new long[V+1]; sDis = new long[V+1];
        Arrays.fill(jDis, Long.MAX_VALUE);
        Arrays.fill(sDis, Long.MAX_VALUE);

        int v1, v2;
        long d;
        for (int i = 1; i <= E; ++i) {
            st = new StringTokenizer(br.readLine());

            v1 = Integer.parseInt(st.nextToken());
            v2 = Integer.parseInt(st.nextToken());
            d = Long.parseLong(st.nextToken());

            adj[v1].add(new Node(v2, d));
            adj[v2].add(new Node(v1, d));
        }

        st = new StringTokenizer(br.readLine());
        jStart = Integer.parseInt(st.nextToken());
        sStart = Integer.parseInt(st.nextToken());
    }

    static void Dijkstra(int startNode, long[] dis) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> {
            return Long.compare(a.d, b.d);
        });
        dis[startNode] = 0;
        pq.add(new Pair(0, startNode));

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            long d = p.d;
            int n = p.node;

            if (d > dis[n]) continue;

            for (Node nextNode: adj[n]) {
                int nextN = nextNode.node;
                long nextDis = nextNode.dis;

                if (dis[nextN] >= dis[n] + nextDis) {
                    dis[nextN] = dis[n] + nextDis;
                    pq.add(new Pair(dis[nextN], nextN));
                }
            }
        }


    }

    static void solve() {

        // get disSum
        for (int i = 1; i <= V; ++i) {
            if (i == sStart || i == jStart) continue;

            disSum = Long.min(disSum, jDis[i] + sDis[i]);
        }
        ArrayList<Integer> tmp = new ArrayList<>();

        // get res
        for (int i = 1; i <= V; ++i) {
            if (i == sStart || i == jStart) continue;
            if (jDis[i] + sDis[i] == disSum) {
                if (sDis[i] < jDis[i]) continue;

                tmp.add(i);
            }
        }

        if (tmp.isEmpty()) {
            System.out.println(-1);
            return ;
        }

        tmp.sort((a, b) -> {
            if (jDis[a] != jDis[b]) {
                return Long.compare(jDis[a], jDis[b]);
            } else {
                return Integer.compare(a, b);
            }
        });

        System.out.println(tmp.get(0));
    }
}
