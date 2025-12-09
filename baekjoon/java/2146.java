import java.util.*;
import java.io.*;


/**
 * @author SJ
 * 
 * 1단계) dfs를 통한 Component를 구해준다. -> 하면서 겉에 있는 node도 더해줌
 * 
 *
 */
public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static String buffer;
	
	static int Len, comCount, res = 1;
	static int[][] matrix;
	static boolean[][] visited;
	static Queue<int[]> margin = new LinkedList<>(); // {xpos, ypos, com};
	static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
	
	
	
	
	public static void main(String[] args) throws IOException {
		input();
		setComponent();
		if (comCount == 1)
		{
			System.out.println(0);
			System.exit(0);
		}
		
		boolean flag = false;
		
		
		while (!flag)
		{
			setMargin();

			flag = spreading();
			//showMargin();
			//showMatrix();
			//System.out.println();
			
			if (flag == true) 
			{
				res = res * 2 - 1;	
				break;
			}
			flag = checking();
			if (flag == true)
			{
				res = res * 2;
				break;
			}
			++res;
		}
		
		System.out.println(res);
		

		
		
	}
	static boolean spreading() // margin에 있는 값들을 옮긴다
	{
		Queue<int[]> q = new LinkedList<>(margin);
		
		while (!q.isEmpty())
		{
			int[] tmp = q.poll();
			
			int x = tmp[0];
			int y = tmp[1];
			int v = tmp[2];
			
			
			if (matrix[x][y] != 0 && matrix[x][y] != v)
				return true;
			
			else if (matrix[x][y] == 0)
				matrix[x][y] = v;
			else if (matrix[x][y] == v)
				continue;
		}
		
		return false;
	}
	
	static boolean checking()
	{
		while (!margin.isEmpty())
		{
			int[] tmp = margin.poll();
			
			int xpos = tmp[0];
			int ypos = tmp[1];
			int v = tmp[2];
			
			for (int i = 0; i < 4; i++) {
				int x = xpos + x_move[i];
				int y = ypos + y_move[i];
				
				if (!inTheMatrix(x,y))
					continue;
				if (matrix[x][y] != v && matrix[x][y] != 0)
				{
					//System.out.println(x + " " + y  + " " + v);
					return true;
				}
			}
		}
		return false;
	}
	
	
	static void showMargin()
	{
		Queue<int[]> q = new LinkedList<>(margin);
		
		while (!q.isEmpty())
		{
			int[] tmp = q.poll();	
			//System.out.println(Arrays.toString(tmp));
		}
	}
	
	
	
	// Function for Debugging
	static void showMatrix()
	{
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j <= Len; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	static void input() throws IOException 
	{
		Len = Integer.parseInt(br.readLine());
		
		matrix = new int[Len+1][Len+1];
		visited = new boolean[Len+1][Len+1];
		
		
		for (int i = 1; i <= Len; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			for (int j = 1; j <= Len; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
		}	
	}
	
	static boolean inTheMatrix(int xpos, int ypos)
	{
		if (xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len)
			return true;
		else
			return false;
	}
	
	
	static void setMargin()
	{
		for (int i = 1; i <= Len; i++) 
		{
			for (int j = 1; j <= Len; j++) 
			{
				if (matrix[i][j] == 0)
					continue;
				for (int a = 0; a < 4; ++a)
				{
					int x = i + x_move[a];
					int y = j + y_move[a];
					
					if (!inTheMatrix(x,y))
						continue;
					if (matrix[x][y] == 0)
						margin.add(new int[] {x,y, matrix[i][j]});
					
				}
			}
		}
	}
	
	
	static void setComponent()
	{
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j <= Len; j++) {
				if (visited[i][j] || matrix[i][j] == 0)
					continue;
				else
				{
					++comCount;
					dfs(i,j);
				}			
			}
		}
	}
	
	static void dfs(int xpos, int ypos)
	{
		visited[xpos][ypos] = true;
		matrix[xpos][ypos] = comCount;
		
		for (int i = 0; i < 4; i++) {
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];
			
			if (!inTheMatrix(x,y)) continue;
			if (visited[x][y]) continue;
			if (matrix[x][y] == 0) continue;
			
			dfs(x,y);
		}
	}
}
