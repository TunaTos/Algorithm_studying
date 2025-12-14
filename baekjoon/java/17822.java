import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static String buffer;
    static StringTokenizer st;

    static int N, M, T;
    static List<Integer>[] list;

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static class Node {
        int x, y, v;

        public Node(int x, int y, int v) {
            this.x = x;
            this.y = y;
            this.v = v;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 0; i < T; i++) {
            int onePan, dir, step;

            buffer = br.readLine();
            st = new StringTokenizer(buffer);

            onePan = Integer.parseInt(st.nextToken());
            dir = Integer.parseInt(st.nextToken());
            step = Integer.parseInt(st.nextToken());

            for (int j = onePan; j <= N; j = j + onePan) { // shuffling
                shuffle(j, dir, step);
            }

            boolean isAdj = false;
            for (int x = 1; x <= N; x++) {
                for (int y = 0; y < M; y++) {
                    if (list[x].get(y) != -200) {
                        if (BFS(x, y, list[x].get(y))) {
                            isAdj = true;
                        }
                    }
                }
            }

            if (!isAdj) {
                delete();
            }
        }
        System.out.printf("%d", getSum());
    }

    static void input() throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        list = new LinkedList[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new LinkedList<>();
        }

        for (int i = 1; i <= N; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);
            for (int j = 0; j < M; j++) {
                list[i].add(Integer.parseInt(st.nextToken()));
            }
        }
    }

    static void shuffle(int oneNum, int dir, int step) {
        step = step % M;
        if (dir == 0) {
            for (int i = 0; i < step; i++) {
                int num = list[oneNum].get(M - 1);
                list[oneNum].remove(M - 1);
                list[oneNum].add(0, num);
            }
        } else if (dir == 1) {
            for (int i = 0; i < step; i++) {
                int num = list[oneNum].get(0);
                list[oneNum].remove(0);
                list[oneNum].add(num);
            }
        }
    }

    static boolean BFS(int x, int y, int v) {
        Queue<Node> q = new LinkedList<>();
        boolean[][] check = new boolean[N + 1][M];
        boolean flag = false;
        check[x][y] = true;
        q.add(new Node(x, y, v));

        while (!q.isEmpty()) {
            Node cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = (cur.y + dy[i] + M) % M; // 원형 배열 처리

                if (nx < 1 || nx > N) continue;
                if (list[nx].get(ny) == cur.v && !check[nx][ny]) {
                    q.add(new Node(nx, ny, list[nx].get(ny)));
                    list[nx].set(ny, -200);
                    check[nx][ny] = true;
                    flag = true;
                }
            }
        }

        if (flag) {
            list[x].set(y, -200);
        }
        return flag;
    }

    static void delete() {
        double sum = 0, div = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                double num = list[i].get(j);
                if (num != -200) {
                    sum += num;
                    div++;
                }
            }
        }

        double avg = sum / div;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                int num = list[i].get(j);
                if (num == -200) continue;
                if (num > avg) list[i].set(j, num - 1);
                else if (num < avg) list[i].set(j, num + 1);
            }
        }
    }

    static int getSum() {
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                int num = list[i].get(j);
                if (num != -200)
                    sum += num;
            }
        }
        return sum;
    }

    // 디버깅용 함수들
    static void showAllPan() {
        for (int i = 1; i <= N; i++) {
            showOnePan(i);
        }
    }

    static void showOnePan(int oneNum) {
        for (int num : list[oneNum])
            System.out.printf("%d ", num);
        System.out.println();
    }
}
