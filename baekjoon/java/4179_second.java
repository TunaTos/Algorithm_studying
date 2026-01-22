
package p_4179;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    static final char WALL = '#';
    static final char HUMAN = 'J';
    static final char FIRE = 'F';


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static char[][] matrix;
    static boolean[][] visited;
    static int Row, Col;
    static int[] human; // {xpos, ypos}
    static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
    static Deque<int[]> humanDeque = new ArrayDeque<>(); // {xpos, ypos, dis}
    static Deque<int[]> fireDeque = new ArrayDeque<>(); // {xpos, ypos}

    public static void main(String[] args) throws Exception{
        input();
        humanDeque.addLast(new int[] {human[0], human[1], 1});
        visited[human[0]][human[1]] = true;

        solve();
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >=1 && ypos <= Col;
    }

    static boolean isPossibleToEvict(int xpos, int ypos) {
        return xpos == 1 || xpos == Row || ypos == 1 || ypos == Col;
    }

    static void solve()
    {
        while (!humanDeque.isEmpty())
        {

            int flag = humanMoving();
            if (flag != -1)
            {
                System.out.println(flag);
                return ;
            }
            if (!fireDeque.isEmpty())
                fireMove();
        }

        System.out.println("IMPOSSIBLE");

    }
    static int humanMoving() {
        // 인간이 움직임


        int qSize = humanDeque.size();

        for (int i = 0; i < qSize; ++i) {
            int[] node = humanDeque.pollFirst();
            int xpos = node[0];
            int ypos = node[1];
            int dis = node[2];

            if (matrix[xpos][ypos] == FIRE)
                continue;
            if (isPossibleToEvict(xpos, ypos))
            {
                return dis;
            }

            for (int j = 0; j < 4; ++j) {
                int x = xpos + x_move[j];
                int y = ypos + y_move[j];

                if (!inTheMatrix(x,y)) continue;
                if (visited[x][y]) continue;
                if (matrix[x][y] == WALL || matrix[x][y] == FIRE) continue;

                visited[x][y] = true;
                humanDeque.addLast(new int[] {x,y,dis+1});
            }
        }


        return -1;
    }

    static void fireMove() {



        int qSize = fireDeque.size();

        for (int i = 1; i <= qSize; ++i) {
            int[] node = fireDeque.pollFirst();
            int xpos = node[0];
            int ypos = node[1];

            for (int j = 0; j < 4; ++j) {
                int x = xpos + x_move[j];
                int y = ypos + y_move[j];


                if (!inTheMatrix(x,y)) continue;
                if (matrix[x][y] == WALL) continue;
                if (matrix[x][y] == FIRE) continue;

                fireDeque.addLast(new int[] {x,y});
                matrix[x][y] = FIRE;
            }
        }

    }
    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        matrix = new char[Row+1][Col+1];
        visited = new boolean[Row+1][Col+1];

        for (int i = 1; i <= Row; ++i) {
            String str = br.readLine();

            for (int j = 1; j <= Col; ++j) {
                char c = str.charAt(j-1);

                if (c == FIRE) {
                    fireDeque.addLast(new int[] {i,j});
                }

                if (c == HUMAN)
                {
                    human = new int[] {i,j};
                    c = '.';
                }
                matrix[i][j] = c;
            }
        }
    }
}
