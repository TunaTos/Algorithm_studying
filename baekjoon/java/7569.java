import java.io.*;
import java.util.*;


public class Main {
	
	static int Row, Col, Height; // Col먼저 
	static int[][][] matrix;
	static boolean[][][] visited;
	static int tomatoNum;
	
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;
	static Queue<int[]> q = new LinkedList<int[]>();
	static int[] x_move = {-1,1,0,0}; // 1차원 상 하 좌 우
	static int[] y_move = {0,0,-1,1};
	static int wallNum;
	public static void main(String[] args) throws IOException {
		input();
		
		// 예외처리 모두 익어있는 경우 or 아무것도 없는 경우
		if (tomatoNum == 0)
		{
			System.out.println(-1);
			System.exit(0);
		}
		else if (tomatoNum + wallNum == Row * Col * Height)
		{
			System.out.println(0);
			System.exit(0);
		}
		else
			getResult();
		
	}
	

	static void input() throws IOException{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Col = Integer.parseInt(st.nextToken());
		Row = Integer.parseInt(st.nextToken());
		Height = Integer.parseInt(st.nextToken());
		
		matrix = new int[Row+1][Col+1][Height+1];
		visited = new boolean[Row+1][Col+1][Height+1];

		
		for (int h = 1; h <= Height; h++) {
			for (int r = 1; r <= Row; r++) {
				buffer = br.readLine();
				st = new StringTokenizer(buffer);
				for (int c = 1; c <= Col; c++) {
					matrix[r][c][h] = Integer.parseInt(st.nextToken());
					if (matrix[r][c][h] == 1)
					{
						tomatoNum++;
						visited[r][c][h] = true;
						q.add(new int[] {r,c,h});
					}
					if (matrix[r][c][h] == -1)
						++wallNum;
				}
			}
		}
	}
	
	static boolean inTheMatrix(int row, int col, int height) {
		return row >= 1 && row <= Row && col >= 1 && col <= Col && height >= 1 && height <= Height;
	}
	
	
	static void getResult() throws IOException {
		int res = 0;
		
		while (!q.isEmpty())
		{
			int qSize = q.size();
			
			for (int i = 0; i < qSize; i++) 
			{
				int [] tmp = q.poll();
				
				int xpos = tmp[0];
				int ypos = tmp[1];
				int hpos = tmp[2];
				for (int j = 0; j < 4; j++) 
				{
					int x = xpos + x_move[j];
					int y= ypos + y_move[j];
					
					if (!inTheMatrix(x,y,hpos)) continue;
					if (visited[x][y][hpos] == true) continue;
					if (matrix[x][y][hpos] == -1) // 벽인경우
						continue;
					visited[x][y][hpos] = true; // 방문처리
					++tomatoNum;
					q.add(new int[] {x,y,hpos});
				}
				
				for (int j = 0; j < 2; j++) {
					int h = hpos + x_move[j]; // -1 1;
					
					if (!inTheMatrix(xpos,ypos,h)) continue;
					if (visited[xpos][ypos][h] == true) continue;
					if (matrix[xpos][ypos][h] == -1) continue;

					visited[xpos][ypos][h] = true;
					++tomatoNum;
					q.add(new int[] {xpos,ypos,h});
				}
			}
			++res;
		}
		
		
		for (int h = 1; h <= Height; h++) {
			for (int r = 1; r <= Row; r++) {
				for (int c = 1; c <= Col; c++) {
					if (matrix[r][c][h] != -1 && visited[r][c][h] == false)
					{
						System.out.println(-1);
						return;
					}
				}
			}
		}
		
		System.out.println(res - 1);
	}
	

	
	static void showMatrix(int height) {
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%b ", visited[i][j][height]);
			}System.out.println();
		}
	}
	
	
	
	
}
