import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String buffer;
    static StringTokenizer st;
    
    static int Row, Col, Q, comNumber;
    static int[] querys;
    static char[][] matrix;
    static int[] x_move = {-1, 1, 0, 0}, y_move = {0, 0, -1, 1};
    static ArrayList<int[]> fallingCom = new ArrayList<int[]>();
    
    public static void main(String[] args) throws IOException {
        input();
        comNumber = getComponentNumber();
        
        doQuery();
        showMatrix();
        
        bw.flush();
        bw.close();
    }
    
    static int getComponentNumber() {
        int res = 0;
        boolean[][] visited = new boolean[Row + 1][Col + 1];
        
        for (int i = 1; i <= Row; i++) {
            for (int j = 1; j <= Col; j++) {
                if (matrix[i][j] == 'x' && !visited[i][j]) {
                    dfs(i, j, visited, false);
                    ++res;
                }
            }
        }
        return res;
    }
    
    static boolean inTheMatrix(int xpos, int ypos) {
        return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
    }
    
    static void dfs(int xpos, int ypos, boolean[][] visited, boolean flag) {
        visited[xpos][ypos] = true;
        if (flag)
            fallingCom.add(new int[] {xpos, ypos});
        
        for (int i = 0; i < 4; i++) {
            int x = xpos + x_move[i];
            int y = ypos + y_move[i];
            
            if (!inTheMatrix(x, y))
                continue;
            if (visited[x][y])
                continue;
            if (matrix[x][y] == 'x')
                dfs(x, y, visited, flag);
        }
    }
    
    static void doQuery() throws IOException {
        for (int i = 1; i <= Q; ++i) {
            if (i % 2 == 1) { // left
                if (isCrash(1, querys[i - 1])) { // 왼쪽에서 부서지는 경우
                    findFloat();
                    if (!fallingCom.isEmpty()) {
                        while (canMove())
                            movedown();
                        fallingCom.clear();
                    }
                }
            } else {
                if (isCrash(2, querys[i - 1])) { // 오른쪽에서 부서지는 경우
                    findFloat();
                    if (!fallingCom.isEmpty()) {
                        while (canMove())
                            movedown();
                        fallingCom.clear();
                    }
                }
            }
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
    
    static void input() throws IOException {
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
        
        matrix = new char[Row + 1][Col + 1];
        
        for (int i = 1; i <= Row; i++) {
            buffer = br.readLine();
            for (int j = 1; j <= Col; j++) {
                matrix[i][j] = buffer.charAt(j - 1);
            }
        }
        
        Q = Integer.parseInt(br.readLine());
        querys = new int[Q];
        buffer = br.readLine();
        st = new StringTokenizer(buffer);
        for (int i = 0; i < Q; i++) 
            querys[i] = Integer.parseInt(st.nextToken());
    }
    
    static boolean isCrash(int dir, int val) {
        // dir == 1 : 왼쪽
        // dir == 2 : 오른쪽
        int r = Row - val + 1;
        
        if (dir == 1) { // 왼쪽에서 ㄱㄱ
            for (int i = 1; i <= Col; ++i) {
                if (matrix[r][i] == 'x') {
                    matrix[r][i] = '.';
                    return true;
                }
            }
        } else if (dir == 2) { // 오른쪽에서 ㄱㄱ
            for (int i = Col; i >= 1; --i) {
                if (matrix[r][i] == 'x') {
                    matrix[r][i] = '.';
                    return true;
                }
            }
        }
        return false;
    }
    
    static void findFloat() {
        boolean[][] visited = new boolean[Row + 1][Col + 1];
        
        for (int i = 1; i <= Col; ++i) {
            if (matrix[Row][i] == 'x')
                dfs(Row, i, visited, false);
        }
        
        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                if (matrix[i][j] == 'x' && !visited[i][j]) {
                    dfs(i, j, visited, true);
                }
            }
        }
    }
    
    static boolean canMove() {
        boolean[][] isPartOfCluster = new boolean[Row + 1][Col + 1];
        for (int[] cell : fallingCom) {
            isPartOfCluster[cell[0]][cell[1]] = true;
        }

        for (int[] cell : fallingCom) {
            int x = cell[0] + 1; 
            int y = cell[1];

            if (x > Row || (matrix[x][y] == 'x' && !isPartOfCluster[x][y])) {
                return false;
            }
        }
        return true;
    }
    
    static void movedown() {
        for (int i = 0; i < fallingCom.size(); ++i) {
            int xpos = fallingCom.get(i)[0];
            int ypos = fallingCom.get(i)[1];
            
            matrix[xpos][ypos] = '.';
            fallingCom.get(i)[0]++;
        }
        
        for (int i = 0; i < fallingCom.size(); ++i) {
            int xpos = fallingCom.get(i)[0];
            int ypos = fallingCom.get(i)[1];
            
            matrix[xpos][ypos] = 'x';
        }
    }
}
