/**
 * multisource bfs
 * Memory: 12168 kb
 * Time : 88ms
 *
 *
 */
package p_1430;

import java.io.*;
import java.util.*;

public class Main {
    static class Point {
        int x, y;
        Point(int x, int y) { this.x = x; this.y = y; }
    }

    static int N, R, D, ex, ey;
    static Point[] towers;

    static boolean withinR(Point a, Point b, int R) {
        long dx = a.x - b.x;
        long dy = a.y - b.y;
        long rr = 1L * R * R;
        return dx * dx + dy * dy <= rr;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        ex = Integer.parseInt(st.nextToken());
        ey = Integer.parseInt(st.nextToken());

        towers = new Point[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            towers[i] = new Point(x, y);
        }



        List<Integer>[] g = new ArrayList[N];
        for (int i = 0; i < N; i++) g[i] = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (withinR(towers[i], towers[j], R)) {
                    g[i].add(j);
                    g[j].add(i);
                }
            }
        }



        int INF = 1_000_000;
        int[] dist = new int[N];
        Arrays.fill(dist, INF);

        ArrayDeque<Integer> q = new ArrayDeque<>();
        Point enemy = new Point(ex, ey);

        for (int i = 0; i < N; i++) {
            if (withinR(towers[i], enemy, R)) {
                dist[i] = 0;
                q.add(i);
            }
        }

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : g[cur]) {
                if (dist[nxt] > dist[cur] + 1) {
                    dist[nxt] = dist[cur] + 1;
                    q.add(nxt);
                }
            }
        }

        double res = 0.0;
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) continue;
            res += D / Math.pow(2.0, dist[i]);
        }


        System.out.printf("%.2f", res);
    }
}
