import java.io.*;
import java.util.StringTokenizer;
 
class Solution {
    static int[] x_move = {-1, 1, 0, 0}; // 상 하 좌 우
    static int[] y_move = {0, 0, -1, 1};
    static char[][] matrix;
 
    static int Tcase, xpos, ypos, dir, Row, Col;
 
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
 
    public static void main(String[] args) throws IOException {
        Tcase = Integer.parseInt(br.readLine());
        String order;
        int len;
        for (int i = 0; i < Tcase; i++) {
            input();
 
            len = Integer.parseInt(br.readLine());
            order = br.readLine();
 
            for (int j = 0; j < len; ++j) {
                char c = order.charAt(j);
                if (c == 'U')
                    move('^');
                else if (c == 'D')
                    move('v');
                else if (c == 'L')
                    move('<');
                else if (c == 'R')
                    move('>');
                else // shooting
                    shooting();
            }
            bw.write("#" + (i + 1) + " ");
            showMatrix();
        }
        bw.flush();
    }
 
    static void shooting() {
        int pXpos = xpos + x_move[dir];
        int pYpos = ypos + y_move[dir];
 
        while (inTheMatrix(pXpos, pYpos)) {
            char c = matrix[pXpos][pYpos];
 
            if (c == '*') { // 일반 벽인 경우
                matrix[pXpos][pYpos] = '.';
                break;
            }
            if (c == '#') // 강철 벽인 경우
                break;
            pXpos += x_move[dir];
            pYpos += y_move[dir];
        }
    }
 
    static int charToDir(char dir) {
        if (dir == '^')
            return 0;
        else if (dir == 'v')
            return 1;
        else if (dir == '<')
            return 2;
        else if (dir == '>')
            return 3;
        return -1;
    }
 
    static void move(char dirInput) {
        dir = charToDir(dirInput); // 방향 변경
        matrix[xpos][ypos] = dirInput; // matrix update
 
        int x = xpos + x_move[dir];
        int y = ypos + y_move[dir];
 
        if (!inTheMatrix(x, y))
            return;
 
        if (matrix[x][y] == '.') { // 평지라면
            matrix[x][y] = dirInput; // 다음으로 움직인다
            matrix[xpos][ypos] = '.'; // 이전거는 평지처리
            xpos = x;
            ypos = y;
        }
    }
 
    static void showMatrix() throws IOException {
        for (int i = 1; i <= Row; i++) {
            for (int j = 1; j <= Col; j++) {
                bw.write(matrix[i][j]);
            }
            bw.newLine();
        }
    }
 
    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }
 
    static void input() throws IOException {
        String buffer = br.readLine();
        StringTokenizer st = new StringTokenizer(buffer);
 
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
 
        matrix = new char[Row + 1][Col + 1];
 
        for (int i = 1; i <= Row; i++) {
            buffer = br.readLine();
            for (int j = 0; j < buffer.length(); j++) {
                matrix[i][j + 1] = buffer.charAt(j);
 
                if (matrix[i][j + 1] == '^') {
                    xpos = i;
                    ypos = j + 1;
                    dir = 0;
                }
                if (matrix[i][j + 1] == 'v') {
                    xpos = i;
                    ypos = j + 1;
                    dir = 1;
                }
                if (matrix[i][j + 1] == '<') {
                    xpos = i;
                    ypos = j + 1;
                    dir = 2;
                }
                if (matrix[i][j + 1] == '>') {
                    xpos = i;
                    ypos = j + 1;
                    dir = 3;
                }
            }
        }
    }
}