import java.io.*;
import java.util.*;


public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;

	static int Row, Col, unTomato, day; // 안 익은 토마토
	static int[][] matrix;
	static boolean[][] visited;
	static int x_move[] = {-1,1,0,0}, y_move[] = {0,0,-1,1};
	static boolean inTheMatrix(int xpos, int ypos)
	{
		return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}
	
	static void showMatrix()
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	static void showVisited()
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%b ", visited[i][j]);
			}System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException{
		input();
		
		Queue<int[]> q = new LinkedList<>(); // xpos ypos
		
		// 토마토 넣기
		for (int i = 1; i <= Row; i++) 
			for (int j = 1; j <= Col; j++) 
				if (matrix[i][j] == 1)
					q.add(new int[] {i,j});
		int res =0;
		while (unTomato != 0)
		{
			int qSize = q.size();
			if (qSize == 0)
			{
				System.out.println(-1);
				System.exit(0);
			}
			//showMatrix();
			//showVisited();
			//System.out.println(unTomato);
			for (int i = 0; i < qSize; i++) {
				int[] tmp = q.poll();
				int xpos = tmp[0];
				int ypos = tmp[1];
				
				for (int j = 0; j < 4; j++) 
				{
					int x = xpos + x_move[j];
					int y = ypos + y_move[j];
					
					
					if (!inTheMatrix(x,y)) // 배열 밖으로 넘어가면
						continue;
					if (matrix[x][y] == 1) // 익은 토마토라면
						continue;
					if (visited[x][y]) // 방문했다면
						continue;
					if (matrix[x][y] == -1) // 벽이라면
						continue;
					
					
					visited[x][y] = true;
					matrix[x][y] = 1;
					--unTomato;
					q.add(new int[] {x,y});

				}
				
				
				
				
				
				
			}
			++res;
		}
		System.out.println(res);
		

		
	}
	


	static void input() throws IOException {
	
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Col = Integer.parseInt(st.nextToken());
		Row = Integer.parseInt(st.nextToken());
		
		// init Container
		matrix = new int[Row+1][Col+1];
		visited = new boolean[Row+1][Col+1];
		
		unTomato = Row * Col;
		
		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			for (int j = 1; j <= Col; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
				
				if (matrix[i][j] == -1 || matrix[i][j] == 1)
					--unTomato;
			}
		}
	}
}
