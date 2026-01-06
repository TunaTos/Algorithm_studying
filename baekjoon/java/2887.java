package p_2887;
/**
 * MST
 *
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int n1;
        int n2;
        long dis;

        Edge(int n1, int n2, long dis) {
            this.n1 = n1;
            this.n2 = n2;
            this.dis = dis;
        }


        @Override
        public int compareTo(Edge o) {
            return Long.compare(this.dis, o.dis);
        }
    }

    static class Pos {
        int idx;
        int x;
        int y;
        int z;

        Pos (int idx, int x, int y, int z) {
            this.idx = idx;
            this.x = x;
            this.y = y;
            this.z = z;
        }

    }

    static int N;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int[] weights, parents;
    static Pos[] poses;
    static ArrayList<Edge> edges = new ArrayList<>();


    public static void main(String[] args) throws Exception{
        input();
        setEdge();
        mst();

    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());

        // init container
        weights = new int[N+1];
        parents = new int[N+1];
        poses = new Pos[N];

        for (int i = 1; i <= N; ++i) {
            parents[i] = i;
            weights[i] = 1;
        }

        for (int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            poses[i] = new Pos(i + 1, x, y, z);
        }
    }

    static long getDistance(Pos p1, Pos p2) {
        return Math.min(
                Math.abs(p1.x - p2.x),
                Math.min(
                        Math.abs(p1.y - p2.y),
                        Math.abs(p1.z - p2.z)
                )
        );
    }

    static void setEdge() {
        Arrays.sort(poses, Comparator.comparingInt(p -> p.x));
        for (int i = 0; i < N - 1; ++i) {
            Pos a = poses[i];
            Pos b = poses[i+1];
            edges.add(new Edge(a.idx, b.idx, getDistance(a,b)));
        }

        Arrays.sort(poses, Comparator.comparingInt(p -> p.y));
        for (int i = 0; i < N - 1; ++i) {
            Pos a = poses[i];
            Pos b = poses[i+1];
            edges.add(new Edge(a.idx, b.idx, getDistance(a,b)));
        }

        Arrays.sort(poses, Comparator.comparingInt(p -> p.z));
        for (int i = 0; i < N - 1; ++i) {
            Pos a = poses[i];
            Pos b = poses[i+1];
            edges.add(new Edge(a.idx, b.idx, getDistance(a,b)));
        }


    }

    static int Find(int pos) {
        if (parents[pos] == pos)
            return pos;
        else
            return parents[pos] = Find(parents[pos]);
    }

    static void Union(int p1, int p2) {
        p1 = Find(p1);
        p2 = Find(p2);

        if (p1 == p2) return;

        if (weights[p1] <= weights[p2])
        {
            parents[p1] = p2;
            weights[p2] += weights[p1];
        }
        else // weights[p1] > weights[p2]
        {
            parents[p2] = p1;
            weights[p1] += weights[p2];
        }
    }

    static void mst() {
        Collections.sort(edges);
        int edgeCnt = 0;
        long res = 0;

        for (Edge edge: edges) {
            int n1 = edge.n1;
            int n2 = edge.n2;

            if (Find(n1) == Find(n2))
                continue;

            Union(n1, n2);
            edgeCnt++;
            res += edge.dis;

            if (edgeCnt == N-1) {
                sb.append(res);
                System.out.println(sb.toString());
                break;
            }
        }
    }
}
