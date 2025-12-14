
import java.io.*;
import java.util.*;


/**
 * @author busalee
 * 
 * 
 */
public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static int[][][] matrix;
	static boolean[][][] visited;
	static int Row, Col, Height;
	static int[] x_move = {-1,1,0,0}, y_move= {0,0,-1,1}; // 일반 움직임
	static int[] x_hmove = {-2,-1,1,2,2,1,-1,-2};
	static int[] y_hmove = {1,2,2,1,-1,-2,-2,-1};
	
		
	public static void main(String[] args) throws IOException {
		input();



		System.out.println(bfs());
	}
	
	static void showMatrix(int[][] matrix)
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	static void showVisited(boolean[][] matrix)
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.print(matrix[i][j] + " ");
			}System.out.println();
		}
	}
	
	static boolean inTheMatrix(int height, int xpos, int ypos)
	{
		return 
				height >= 0 && height <= Height && 
				xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}
	
	
	static void input() throws IOException {
		Height = Integer.parseInt(br.readLine());
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Col = Integer.parseInt(st.nextToken());
		Row = Integer.parseInt(st.nextToken());
		
		matrix = new int[Height+1][Row+1][Col+1];
		visited = new boolean[Height+1][Row+1][Col+1];
		
		// input
		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			
			for (int j = 1; j <= Col; j++) {
				int num = Integer.parseInt(st.nextToken());
				
				for (int k = 0; k <= Height; k++) {
					matrix[k][i][j] = num;
				}
			}
		}
	}
	
	static int bfs()
	{
		Queue<int[]> q = new LinkedList<int[]>();// {height, xpos, ypos}
		q.offer(new int[] {0, 1, 1});
		
		int result = 0;
		visited[0][1][1] = true;
		if (Row == 1 && Col ==1)
			return 0;
		while (!q.isEmpty())
		{
			
			int qSize = q.size();
			
			for (int i = 0; i < qSize; i++) 
			{
				int[] tmp = q.poll();
				
				int hpos = tmp[0];
				int xpos = tmp[1];
				int ypos = tmp[2];
				
				if (xpos == Row && ypos == Col)
					return result;
				
				
				// 일반움직임
				for (int j = 0; j < 4; j++) 
				{
					int x = xpos + x_move[j];
					int y = ypos + y_move[j];
					
					if (!inTheMatrix(hpos, x,y)) continue;
					if (visited[hpos][x][y]) continue;
					if (matrix[hpos][x][y] == 1) continue; 
					
					visited[hpos][x][y] = true;
					q.offer(new int[] {hpos, x,y});
				}
				
				for (int j = 0; j < 8; j++) {
					int h = hpos + 1;
					int x = xpos + x_hmove[j];
					int y = ypos + y_hmove[j];
					
					if (!inTheMatrix(h,x,y)) continue;
					if (visited[h][x][y]) continue;
					if (matrix[h][x][y] == 1) continue; 

					
					visited[h][x][y] = true;
					q.offer(new int[] {h,x,y});
				}
				
				//showVisited(visited[0]);
				//System.out.println();
				//showVisited(visited[1]);
				//System.out.println();
				//System.out.println();
				//showVisited(visited[2]);
				//System.out.println();
				//System.out.println();
				
			}
			++result;
		}
		return -1;
	}
}
