package p_18500;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static class Edge {
        int xpos, ypos;
        Edge(int xpos, int ypos) {
            this.xpos = xpos;
            this.ypos = ypos;
        }
    }

    static final int LEFT = 1, RIGHT = 2;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int Row, Col, tCount, Turn = LEFT, comCount;
    static int[] throwRows;
    static char[][] matrix;
    static int[][] visited;
    static int[] x_move = {-1, 1, 0, 0}, y_move = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {
        input();
        solve();
        printMatrix();


    }

    static void solve() {
        for (int i = 0; i < tCount; ++i) {
            int tRow = throwRows[i];

            throwPoll(tRow);
            Turn = (Turn == LEFT) ? RIGHT : LEFT;

            visited = new int[Row + 1][Col + 1];
            comCount = 0;

            for (int j = 1; j <= Row; ++j) {
                for (int z = 1; z <= Col; ++z) {
                    if (visited[j][z] == 0 && matrix[j][z] == 'x') {
                        dfs(j, z, ++comCount);
                    }
                }
            }


            Set<Integer> grounded = new HashSet<>();
            for (int j = 1; j <= Col; ++j) {
                if (matrix[Row][j] == 'x') {
                    grounded.add(visited[Row][j]);
                }
            }

            ArrayList<Edge> floating = new ArrayList<>();
            for (int a = 1; a <= Row; ++a) {
                for (int b = 1; b <= Col; ++b) {
                    if (matrix[a][b] == 'x' && !grounded.contains(visited[a][b])) {
                        floating.add(new Edge(a, b));
                    }
                }
            }

            if (floating.isEmpty()) continue;



            for (Edge e : floating) {
                matrix[e.xpos][e.ypos] = '.';
            }




            int drop = Row;
            for (Edge e : floating) {
                int d = 0;
                int nx = e.xpos + 1;
                while (nx <= Row && matrix[nx][e.ypos] == '.') {
                    d++;
                    nx++;
                }
                drop = Math.min(drop, d);
            }




            for (Edge e : floating) {
                matrix[e.xpos + drop][e.ypos] = 'x';
            }
        }
    }

    static void dfs(int xpos, int ypos, int id) {
        visited[xpos][ypos] = id;

        for (int i = 0; i < 4; ++i) {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];

            if (!inTheMatrix(x, y)) continue;
            if (visited[x][y] != 0) continue;
            if (matrix[x][y] == '.') continue;

            dfs(x, y, id);
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }

    static void throwPoll(int count) {
        // count는 높이(1=바닥, R=천장) → 행 인덱스로 변환
        int r = Row - count + 1;

        if (Turn == LEFT) {
            for (int c = 1; c <= Col; ++c) {
                if (matrix[r][c] == 'x') {
                    matrix[r][c] = '.';
                    break;
                }
            }
        } else {
            for (int c = Col; c >= 1; --c) {
                if (matrix[r][c] == 'x') {
                    matrix[r][c] = '.';
                    break;
                }
            }
        }
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        matrix = new char[Row + 1][Col + 1];

        for (int i = 1; i <= Row; ++i) {
            String tmp = br.readLine();
            for (int j = 0; j < Col; ++j) {
                matrix[i][j + 1] = tmp.charAt(j);
            }
        }

        tCount = Integer.parseInt(br.readLine());
        throwRows = new int[tCount];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < tCount; ++i) {
            throwRows[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void printMatrix() {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                sb.append(matrix[i][j]);
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}