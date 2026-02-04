package p_18809;

import java.io.*;
import java.util.*;

public class Main {
    static class Pos {
        int x, y;
        Pos(int x, int y) { this.x = x; this.y = y; }
    }


    static final int WATER = 0;
    static final int LAND = 1;
    static final int FERTILE = 2;
    static final int GREEN = 3;
    static final int RED = 4;
    static final int FLOWER = 5;

    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int Row, Col, G, R, result;
    static int[][] base;
    static ArrayList<Pos> fertilePos = new ArrayList<>();

    static boolean[] pick;
    static Pos[] selected;
    static boolean[] isGreen;

    static boolean inRange(int x, int y) {
        return x >= 1 && x <= Row && y >= 1 && y <= Col;
    }

    public static void main(String[] args) throws Exception {
        input();
        dfsPick(0, 0);
        System.out.println(result);
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
        G = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        base = new int[Row + 1][Col + 1];

        for (int i = 1; i <= Row; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= Col; ++j) {
                base[i][j] = Integer.parseInt(st.nextToken());
                if (base[i][j] == FERTILE) {
                    fertilePos.add(new Pos(i, j));
                }
            }
        }

        pick = new boolean[fertilePos.size()];
        selected = new Pos[G + R];
        isGreen = new boolean[G + R];
        result = 0;
    }

    static void dfsPick(int idx, int depth) {
        if (depth == G + R) {
            dfsAssignGreen(0, 0);
            return;
        }
        for (int i = idx; i < fertilePos.size(); ++i) {
            if (!pick[i]) {
                pick[i] = true;
                selected[depth] = fertilePos.get(i);
                dfsPick(i + 1, depth + 1);
                pick[i] = false;
            }
        }
    }

    static void dfsAssignGreen(int idx, int gCount) {
        if (gCount == G) {
            bfs();
            return;
        }
        for (int i = idx; i < selected.length; ++i) {
            if (!isGreen[i]) {
                isGreen[i] = true;
                dfsAssignGreen(i + 1, gCount + 1);
                isGreen[i] = false;
            }
        }
    }

    static void bfs() {
        int[][] time = new int[Row + 1][Col + 1];
        int[][] color = new int[Row + 1][Col + 1];
        for (int i = 1; i <= Row; ++i) Arrays.fill(time[i], -1);

        ArrayDeque<Pos> q = new ArrayDeque<>();

        for (int i = 0; i < selected.length; ++i) {
            Pos p = selected[i];
            time[p.x][p.y] = 0;
            color[p.x][p.y] = (isGreen[i] ? GREEN : RED);
            q.addLast(p);
        }

        while (!q.isEmpty()) {
            Pos cur = q.pollFirst();
            int x0 = cur.x, y0 = cur.y;

            if (color[x0][y0] == FLOWER) continue;

            for (int d = 0; d < 4; ++d) {
                int x = x0 + dx[d];
                int y = y0 + dy[d];

                if (!inRange(x, y)) continue;
                if (base[x][y] == WATER) continue;

                int nt = time[x0][y0] + 1;
                int nc = color[x0][y0];

                if (time[x][y] == -1) {
                    time[x][y] = nt;
                    color[x][y] = nc;
                    q.addLast(new Pos(x, y));
                }


                else if (time[x][y] == nt && color[x][y] != nc && color[x][y] != FLOWER) {
                    color[x][y] = FLOWER;
                }
            }
        }

        int flowers = 0;
        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                if (color[i][j] == FLOWER) flowers++;
            }
        }
        result = Math.max(result, flowers);
    }
}
