import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static String buffer;
    static StringTokenizer st;
    
    
    static int Len, res1, res2; // 일반, 적록색약 -> 빨간색과 초록색이 같다고 친다.
    static char[][] matrix1, matrix2; // R B
    static boolean[][] visited;
    static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
    
    
    
	public static void main(String[] args) throws IOException {
		Len = Integer.parseInt(br.readLine());
		
		// init container
		matrix1 = new char[Len+1][Len+1];
		matrix2 = new char[Len+1][Len+1];
		visited = new boolean[Len+1][Len+1];
		
		for (int i = 1; i <= Len; i++) {
			buffer = br.readLine();
			for (int j = 1; j <= Len; j++) {
				matrix1[i][j] = buffer.charAt(j-1);
				if (matrix1[i][j] == 'G')
					matrix2[i][j] = 'R';
				else
					matrix2[i][j] = matrix1[i][j];
			}
		}
		
		// 일반
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j <= Len; j++) {
				if (!visited[i][j])
				{
					dfs(i,j, matrix1);
					++res1;
				}
			}
		}
		
		
		visited = new boolean[Len+1][Len+1];
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j <= Len; j++) {
				if (!visited[i][j])
				{
					dfs(i,j, matrix2);
					++res2;
				}
			}
		}
		
		System.out.println(res1 + " " + res2);
		
	}
	static boolean inTheMatrix(int xpos, int ypos)
	{
		return xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len;
	}
	
	static void showMatrix(char[][] matrix)
	{
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j <= Len; j++) {
				System.out.printf("%c ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	static void dfs(int xpos, int ypos, char[][] matrix)
	{
		visited[xpos][ypos] = true;
		
		for (int i = 0; i < 4; i++) {
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];
			
			
			if (!inTheMatrix(x,y))
				continue;
			if (visited[x][y])
				continue;
			if (matrix[x][y] != matrix[xpos][ypos])
				continue;
			
			dfs(x,y,matrix);
			
		}
	}
	


	
	
}
