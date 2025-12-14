
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static List<Integer>[] adj;
    static int[] points;
    static int N, M;
    
    public static void main(String[] args) throws IOException {
        input();

        // 칭찬 정보를 미리 저장 (DFS로 한 번만 전파)
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            points[v] += w;  // 칭찬을 해당 직원에게만 누적
        }

        // DFS를 통해 칭찬을 한 번만 전파
        dfs(1);

        // 결과 출력
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            sb.append(points[i]).append(" ");
        }
        bw.write(sb.toString());
        bw.flush();
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N + 1];
        points = new int[N + 1];

        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        // 상사 정보 입력받아 트리 구성
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int p = Integer.parseInt(st.nextToken());
            if (p != -1) adj[p].add(i);
        }
    }

    static void dfs(int node) {
        for (int next : adj[node]) {
            points[next] += points[node]; // 부모의 칭찬을 자식에게 전파
            dfs(next);
        }
    }
}
