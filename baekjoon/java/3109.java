import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int Row, Col, res;
    static char[][] matrix;
    static boolean[][] visited;
    static int[] x_move = {-1, 0, 1}; // 왼쪽, 직진, 오른쪽
    static int[] y_move = {1, 1, 1}; // 모든 이동은 오른쪽으로

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 1; i <= Row; i++) {
            if (dfs(i, 1)) { // 목적지에 도달하면 true 반환
                res++; // 경로가 성공적으로 도착했을 때만 카운트
            }

            //showMatrix();
        }
        sb.append(res);
        bw.write(sb.toString());
        bw.flush();
        //showMatrix();
    }

    static void showMatrix() {
        for (int i = 1; i <= Row; i++) {
            for (int j = 1; j <= Col; j++) {
                System.out.printf("%c ", matrix[i][j]);
            }
            System.out.println();
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());

        matrix = new char[Row + 1][Col + 1];
        visited = new boolean[Row+1][Col+1];
        for (int i = 1; i <= Row; i++) {
            String buffer = br.readLine();
            for (int j = 0; j < Col; j++) {
                matrix[i][j + 1] = buffer.charAt(j);
            }
        }
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }

    static boolean dfs(int xpos, int ypos) {
        visited[xpos][ypos] = true; // 방문 처리

        if (ypos == Col) { // 목적지에 도착했음
            matrix[xpos][ypos] = 'x'; // 경로 표시
            return true; // 성공적으로 도착했음을 반환
        }

        for (int i = 0; i < 3; i++) { // 좌, 직진, 우
            int nextX = xpos + x_move[i];
            int nextY = ypos + y_move[i];

            if (inTheMatrix(nextX, nextY) && matrix[nextX][nextY] != 'x' && !visited[nextX][nextY]) {
                if (dfs(nextX, nextY)) {
                    matrix[xpos][ypos] = 'x'; // 경로가 성공적으로 도착했을 때만 경로 표시
                    return true; // 성공적으로 도착했음을 반환
                }
            }
        }
        return false; // 목적지에 도달하지 못했음을 반환
    }
}
