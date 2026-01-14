/**
 *
 */
package p_27945;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge>{
        int p1;
        int p2;
        long w;

        Edge(int p1, int p2, long w) {
            this.p1 = p1;
            this.p2 = p2;
            this.w = w;
        }


        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.w, o.w);
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M;
    static Edge[] edges;
    static int[] parents, weights;
    static ArrayList<Long> arrays = new ArrayList<>();

    public static void main(String[] args) throws Exception{
        input();
        mst();
        getResult();
    }

    static void getResult() {
        long res = 1;

        for (Long day: arrays)
        {
            if (res != day)
                break;
            ++res;
        }
        System.out.println(res);
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        edges = new Edge[M];
        parents = new int[N+1];
        weights = new int[N+1];

        Arrays.fill(weights, 1);
        for (int i = 1; i <= N; ++i)
            parents[i] = i;

        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int p1, p2; long w;
            p1 = Integer.parseInt(st.nextToken());
            p2 = Integer.parseInt(st.nextToken());
            w = Long.parseLong(st.nextToken());
            edges[i] = new Edge(p1,p2,w);
        }
    }

    static int Find(int node) {
        if (parents[node] == node)
            return node;
        else
            return parents[node] = Find(parents[node]);
    }

    static void Union(int n1, int n2)
    {
        n1 = Find(n1);
        n2 = Find(n2);

        if (n1 == n2)
            return ;

        if (weights[n1] >= weights[n2])
        {
            parents[n2] = n1;
            weights[n1] += weights[n2];
        }
        else {
            parents[n1] = n2;
            weights[n2] += weights[n1];
        }
    }

    static void mst() {
        int edgeCount = 0;
        Arrays.sort(edges);

        for (Edge e: edges) {
            int p1 = Find(e.p1);
            int p2 = Find(e.p2);

            if (p1 == p2) continue;

            Union(p1,p2);
            arrays.add(e.w);
            ++edgeCount;

            if (edgeCount == N-1)
                break;
        }
    }

}
