/**
 * Memory : 15240
 * Time : 116
 *
 *
 * 모든 건물은 일렬로 나열되어 있다.
 * K개의 경찰서가 있다
 *
 * 금은방 S에 있음 (시작점)
 * D에 비밀 통로를 있음
 *
 * a + F -> 전방
 * a - B -> 후방
 * 한 번 달리면 10초동안 휴식 -> 경찰서 안에 휴식하면 체포된다
 *
 * 못 갈 수도 있음!
 *
 * 얼마나 최소
 *
 * N : 건물의 개수
 * S : 털린 금은방
 * D : X의 집
 * F : 앞으로
 * B : 뒤로
 * K 경찰서 개수
 * l(k) : 경찰서의 건물 번호
 *
 * bfs처럼 먼저 가는 것이 best case인가?
 *
 */
package p_13700;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, S, D, F, B, K;
    static boolean[] visited;
    public static void main(String[] args) throws Exception{
        input();
        bfs();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        F = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        visited = new boolean[N+1];

        if (K != 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= K; ++i) {
                int num = Integer.parseInt(st.nextToken());
                visited[num] = true;
            }
        }
    }

    static void bfs() {
        Deque<int[]> q = new ArrayDeque<>(); // {pos, dis}
        q.addLast(new  int[] {S, 0});
        visited[S] = true;

        while (!q.isEmpty()) {
            int[] tmp = q.pollFirst();

            int pos = tmp[0];
            int dis = tmp[1];
            if (pos == D) {
                System.out.println(dis);
                return;
            }

            int fPos = pos + F;
            int bPos = pos - B;

            if (inTheRange(fPos) && !visited[fPos]) {
                visited[fPos] = true;
                q.addLast(new int[] {fPos, dis + 1});
            }

            if (inTheRange(bPos) && !visited[bPos]) {
                visited[bPos] = true;
                q.addLast(new int[] {bPos, dis + 1});
            }
        }

        System.out.println("BUG FOUND");
    }

    static boolean inTheRange(int pos) {
        return pos >= 1 && pos <= N;
    }
}
