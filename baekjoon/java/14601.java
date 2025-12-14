import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	
	static StringTokenizer st;
	static int Len, num, xpos, ypos, tmp = 1;
	static int[][] matrix; // 출력을 반대로 출력한다!
	
	
	
	public static void main(String[] args) throws IOException{
		input();
		//showMatrix();
		devide(1, 1, Len);
		showMatrix();
	}
	
	static int findPos(int row, int col, int len)
	{
		int half = len / 2;
		// 1사분면
		for (int i = row; i < row + half; i++) {
			for (int j = col; j < col + half; j++) {
				if (matrix[i][j] != 0)
					return 1;
			}
		}
		
		// 2사분면
		for (int i = row; i < row + half; i++) {
			for (int j = col + half; j < col + len; j++) {
				if (matrix[i][j] != 0)
					return 2;
			}
		}
		// 3사분면
		for (int i = row + half; i < row + len; i++) {
			for (int j = col; j < col + half; j++) {
				if (matrix[i][j] != 0)
					return 3;
			}
		}
		
		// 4사분면
		for (int i = row + half; i < row + len; i++) {
			for (int j = col + half; j < col + len; j++) {
				if (matrix[i][j] != 0)
					return 4;
			}
		}
		return -1;
	
	}
	
	static void coloring(int row, int col, int half, int pos)
	{

		var num1 = matrix[row + half - 1][col + half - 1];
		var num2 = matrix[row + half - 1][col + half];
		var num3 = matrix[row + half][col + half - 1];
		var num4 = matrix[row + half][col + half];
		
		if (pos == 1)
		{
			matrix[row + half - 1][col + half] = tmp;
			matrix[row + half][col + half - 1] = tmp;
			matrix[row + half][col + half] = tmp;
		}
		else if (pos == 2)
		{
			matrix[row + half - 1][col + half - 1] = tmp;
			matrix[row + half][col + half - 1] = tmp;
			matrix[row + half][col + half] = tmp;
		}
		else if (pos == 3)
		{
			matrix[row + half - 1][col + half - 1] = tmp;
			matrix[row + half - 1][col + half] = tmp;
			matrix[row + half][col + half] = tmp;
		}
		else
		{
			matrix[row + half - 1][col + half - 1] = tmp;
			matrix[row + half - 1][col + half] = tmp;
			matrix[row + half][col + half - 1] = tmp;
		}
		++tmp;
	}
	
	
	static void devide(int row, int col, int len)
	{
		if (len == 1)
			return ;
		
		int half = len / 2;
		// 4분면에서 -1이 어디에 있는지 찾는다!
		int p = findPos(row, col, len); // 점이 어디에 있는지 알려준다.
		coloring(row, col, half, p);
		//showMatrix();
		//System.out.println();
		devide(row, col, half);
		devide(row, col + half, half);
		devide(row+half, col, half);
		devide(row + half, col+half, half);
	}
	
	static void showMatrix()
	{
		for (int i = Len; i >= 1; --i) {
			for (int j = 1; j <= Len; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	static void input() throws IOException {
		num = Integer.parseInt(br.readLine());
		Len = 1 << num;
		
		matrix = new int[Len+1][Len+1];
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		ypos = Integer.parseInt(st.nextToken());
		xpos = Integer.parseInt(st.nextToken());
		
		matrix[xpos][ypos] = -1;
	}
}
