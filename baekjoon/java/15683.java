/**
 * Memory : 28716
 * Time 316
 *
 *
 * 0은 빈칸
 * 6은 벽
 * 1 ~ 5는 CCYV
 *
 * CCTV의 최대 개수는 8개이다
 * matrix -> 8 * 8
 *
 */

package p_15683;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int Row, Col, res = Integer.MAX_VALUE;
    static int[][] matrix;
    static int x_move[] = {-1,1,0,0}, y_move[] = {0,0,-1,1};
    static ArrayList<int[]> cctv = new ArrayList<>(); // {xpos,ypos,type}
    static int[] selected;

    public static void main(String[] args) throws Exception{
        input();
        selected = new int[cctv.size()];
        permutation(0);
        System.out.println(res);
    }

    static void doCase (int xpos, int ypos, int type, int dir) {
        // dir -> 시계방향
        if (type == 1) {
            if (dir == 0)
                coloring(xpos,ypos,3);
            else if (dir == 1)
                coloring(xpos,ypos,1);
            else if (dir == 2)
                coloring(xpos,ypos,2);
            else if (dir == 3)
                coloring(xpos,ypos,0);
        }

        else if (type == 2) {
            if (dir == 0 || dir == 2) {
                coloring(xpos,ypos, 2);
                coloring(xpos,ypos, 3);
            }
            else if (dir == 1 || dir == 3) {
                coloring(xpos,ypos, 0);
                coloring(xpos,ypos, 1);
            }
        }

        else if (type == 3) {
            if (dir == 0) {
                coloring(xpos, ypos, 0);
                coloring(xpos, ypos, 3);
            }
            else if (dir == 1) {
                coloring(xpos, ypos, 1);
                coloring(xpos, ypos, 3);
            }
            else if (dir == 2) {
                coloring(xpos, ypos, 1);
                coloring(xpos, ypos, 2);

            }
            else if (dir == 3) {
                coloring(xpos, ypos, 0);
                coloring(xpos, ypos, 2);
            }
        }

        else if (type == 4) {
            if (dir == 0) {
                coloring(xpos, ypos, 0);
                coloring(xpos, ypos, 2);
                coloring(xpos, ypos, 3);
            }
            else if (dir == 1) {
                coloring(xpos, ypos, 0);
                coloring(xpos, ypos, 1);
                coloring(xpos, ypos, 3);
            }
            else if (dir == 2) {
                coloring(xpos, ypos, 1);
                coloring(xpos, ypos, 2);
                coloring(xpos, ypos, 3);
            }
            else if (dir == 3) {
                coloring(xpos, ypos, 0);
                coloring(xpos, ypos, 1);
                coloring(xpos, ypos, 2);
            }
        }

        else if (type == 5) {
            coloring(xpos,ypos,0);
            coloring(xpos,ypos,1);
            coloring(xpos,ypos,2);
            coloring(xpos,ypos,3);
        }
    }

    static void permutation(int idx) {
        if (idx == cctv.size()) {

            for (int i = 0; i < cctv.size(); ++i) {
                int dir = selected[i];
                int xpos = cctv.get(i)[0];
                int ypos = cctv.get(i)[1];
                int type = cctv.get(i)[2];

                // coloring
                doCase(xpos,ypos,type,dir);
            }

            res = Integer.min(res, countSpaceAndInitMatrix());
            return;
        }

        for (int i = 0; i < 4; ++i) {
            selected[idx] = i;
            permutation(idx+1);

        }
    }

    static void showMatrix() {
        for (int i =1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void coloring(int xpos, int ypos, int dir) {
        // dir -> 0,1,2,3 (상 하 좌 우)
        // 벽은 뚫고 갈 수 없음, 같은 cctv면 뚫고 갈 수 있음
        int cnt = 0;
        while (true) {
            xpos = xpos + x_move[dir];
            ypos = ypos + y_move[dir];

            if (!inTheMatrix(xpos,ypos)) break;
            if (matrix[xpos][ypos] == 6) break;
            if (matrix[xpos][ypos] >= 1 && matrix[xpos][ypos] <= 5) continue;

            matrix[xpos][ypos] = -1;
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }

    static int countSpaceAndInitMatrix() {
        // 사각 지대 개수와 matrix 초기화하는 함수
        int res = 0;

        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j)  {
                if (matrix[i][j] == 0)
                    ++res;
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }

        return res;
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        matrix = new int[Row+1][Col+1];

        for (int i = 1; i <= Row; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= Col; ++j) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                if (matrix[i][j] >= 1 && matrix[i][j] <= 5)
                    cctv.add(new int[] {i,j, matrix[i][j]});
            }
        }
    }
}
