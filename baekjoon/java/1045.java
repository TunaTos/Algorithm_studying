import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static char[][] adjMatrix;
    static int[] roots;
    static Queue<int[]> roads = new LinkedList<>();
    static StringBuilder result = new StringBuilder();

    public static void main(String[] args) throws IOException {
        readInput();
        processRoads();
        outputResult();
    }

    private static void readInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adjMatrix = new char[N][N];
        roots = new int[N];

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            roots[i] = i; // 초기화
            for (int j = i + 1; j < N; j++) {
                adjMatrix[i][j] = line.charAt(j);
                if (adjMatrix[i][j] == 'Y') {
                    roads.add(new int[]{i, j});
                }
            }
        }
    }

    private static void processRoads() {
        int[] roadCount = new int[N];
        int linkedRoads = 0;
        Queue<int[]> pendingRoads = new LinkedList<>();

        if (roads.size() < M) {
            result.append(-1);
            return;
        }

        while (!roads.isEmpty()) {
            int[] road = roads.poll();
            if (connect(road[0], road[1])) {
                roadCount[road[0]]++;
                roadCount[road[1]]++;
                linkedRoads++;
            } else {
                pendingRoads.add(road);
            }
        }

        if (linkedRoads != N - 1) {
            result.append(-1);
            return;
        }

        for (int i = linkedRoads; i < M; i++) {
            if (pendingRoads.isEmpty()) {
                result.append(-1);
                return;
            }
            int[] road = pendingRoads.poll();
            roadCount[road[0]]++;
            roadCount[road[1]]++;
        }

        for (int count : roadCount) {
            result.append(count).append(" ");
        }
    }

    private static boolean connect(int a, int b) {
        a = findRoot(a);
        b = findRoot(b);

        if (a == b) return false;

        if (a < b) roots[b] = a;
        else roots[a] = b;
        return true;
    }

    private static int findRoot(int node) {
        if (roots[node] == node) return node;
        return roots[node] = findRoot(roots[node]);
    }

    private static void outputResult() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(result.toString().trim());
        bw.flush();
    }
}
