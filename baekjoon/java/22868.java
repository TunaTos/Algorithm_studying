/**
 * S에서 출발해서 S와 다른 곳인 E를 찍고 다시 S로 돌아온다
 *
 * S -> E -> S
 * 조건
 *      갈때 사용했던 경로랑, 올때 사용했던 경로는 달라야한다.
 *      S -> E와 E -> S는 최단거리다
 *      S -> E로 갈 때, 경로나열할 때의 사전순으로 먼저 오는 거 선택한다.
 *
 *
 *
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.annotation.Target;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int V, E, S, T, res;
    static ArrayList<Integer>[] adj;
    static int[] from; // 특정 node가 어디서부터 왔는가?
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        input();
        startToTarget();
        //System.out.println(Arrays.toString(from));
        getPath();;
        //System.out.println(Arrays.toString(visited));
        visited[S] = false; visited[T] = false;
        TargetToStart();;
        System.out.println(res);
    }

    static void input() throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        // init container
        from = new int[V+1];
        visited = new boolean[V+1];
        adj = new ArrayList[V+1];
        for (int i = 0; i <= V; ++i)
            adj[i] = new ArrayList<>();

        int s, t;
        for (int i = 1; i <= E; ++ i) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            t = Integer.parseInt(st.nextToken());

            adj[s].add(t);
            adj[t].add(s);
        }

        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= V; ++i)
            if (!adj[i].isEmpty())
                Collections.sort(adj[i]);
    }

    static void startToTarget() {
        // 시작점에서 도착점까지
        Deque<Integer> dq = new ArrayDeque<>();
        int[] dis = new int[V+1];
        Arrays.fill(dis, -1);

        dq.addLast(S);
        dis[S] = 0;
        from[S] = S;

        while (!dq.isEmpty()) {
            int node = dq.pollFirst();

            for (int next: adj[node]) {
                if (dis[next] == -1) {
                    dis[next] = dis[node] + 1;
                    from[next] = node;
                    dq.addLast(next);
                }
            }
        }

        //System.out.println(Arrays.toString(dis));
        res += dis[T];
    }

    static void getPath() {
        int node = T;

        while (node != from[node]) {
            visited[node] = true;
            node = from[node];
        }
    }

    static void TargetToStart() {
        // 도착점에서 시작점까지
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(T);
        visited[T] = true;
        int tmp = 0;

        while (!dq.isEmpty()) {
            int qSize = dq.size();
            ++tmp;
            for (int i = 0; i < qSize; ++i) {
                int node = dq.pollFirst();
                if (node == S) {
                    res += (tmp-1);
                    return;
                }
                //System.out.println(node);

                for (int next: adj[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        dq.addLast(next);
                    }
                }
            }
        }
    }
}
