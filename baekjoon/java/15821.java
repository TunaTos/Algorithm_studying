package ㅔ_15821;

import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int x;
        int y;

        public Edge(int x, int y) {
            this.x = x;
            this.y = y;
        }

        double getDistance() {
            return (double) x * x + (double) y * y;
        }
    }

    static int N, K, P;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static List<Double> dis = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            P = Integer.parseInt(br.readLine().trim());
            st = new StringTokenizer(br.readLine());

            double res = 0.0;

            for (int z = 0; z < P; z++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                Edge e = new Edge(x, y);
                res = Math.max(res, e.getDistance());
            }

            dis.add(res);
        }

        Collections.sort(dis);
        System.out.printf("%.2f%n", dis.get(K - 1));
    }
}