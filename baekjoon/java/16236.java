/**
 * N N
 *
 * 한 칸에 물고기가 최대 1마리 존재한다.
 *
 * 처음에 아기 상어의 크기는 2이다
 *
 * 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없음
 * 작은 칸의 물고기는 먹을 수 있음
 * 물고기 먹으면 크기가 커짐
 *
 * 이동 규칙)
 *      먹을 물고기가 없다면 -> 도움을 청한다
 *      먹을 수 있는 물고기가 1마리라면 -> 그 물고기 먹음
 *      1마리보다 더 많다면
 *             거리가 가장 가까운 물고기 먹는다.
 *             거리가 가까운 물고기가 많다면 ->
 *                  가장 위에 있는 물고기, 가장 왼쪽에 있는 물고기
 */
package p_16236;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Shark {
        int xpos;
        int ypos;
        int size;
        int eat;
        Shark(int xpos, int ypos) {
            this.xpos = xpos;
            this.ypos = ypos;
            this.size = 2;
            this.eat = 0;
        }
    }

    static class Fish {
        int x, y, dist;
        Fish(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
    static final int[] x_move= {-1,1,0,0}, y_move = {0,0,-1,1};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] matrix;
    static boolean[][] visited;
    static int N, res;
    static Shark shark;

    public static void main(String[] args) throws Exception {
        input();
        while (checkingFishes()) {
        }
        System.out.println(res);
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());

        // init
        matrix = new int[N+1][N+1];

        for (int i = 1; i <= N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; ++j) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                if (matrix[i][j] == 9)
                {
                    shark = new Shark(i,j);
                    matrix[i][j] = 0;
                }
            }
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= N && ypos >= 1 && ypos <= N;
    }

    static boolean checkingFishes() {
        visited = new boolean[N+1][N+1];
        Queue<int[]> q = new ArrayDeque<>();
        List<Fish> candidates = new ArrayList<>();

        q.add(new int[]{shark.xpos, shark.ypos, 0});
        visited[shark.xpos][shark.ypos] = true;

        int minDist = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int dist = cur[2];

            if (dist > minDist) break;

            if (matrix[x][y] > 0 && matrix[x][y] < shark.size) {
                minDist = dist;
                candidates.add(new Fish(x, y, dist));
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + x_move[i];
                int ny = y + y_move[i];

                if (!inTheMatrix(nx, ny)) continue;
                if (visited[nx][ny]) continue;
                if (matrix[nx][ny] > shark.size) continue;

                visited[nx][ny] = true;
                q.add(new int[]{nx, ny, dist + 1});
            }
        }

        if (candidates.isEmpty()) return false;

        candidates.sort((a, b) -> {
            if (a.x != b.x) return a.x - b.x;
            return a.y - b.y;
        });

        Fish target = candidates.get(0);

        shark.xpos = target.x;
        shark.ypos = target.y;
        shark.eat++;
        res += target.dist;
        matrix[target.x][target.y] = 0;

        if (shark.eat == shark.size) {
            shark.size++;
            shark.eat = 0;
        }

        return true;
    }
}
