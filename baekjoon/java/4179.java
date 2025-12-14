import java.io.*;
import java.util.*;

public class Main {
	
	static StringTokenizer st;
	static String buffer;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
	static int Row, Col, Result;
	static char[][] matrix;
	static boolean[][] humanVisited, fireVisited;
	
	static Queue<int[]> homanPos = new LinkedList<int[]>();
	static Queue<int[]> firePos = new LinkedList<int[]> ();
	

	public static void main(String[] args) throws IOException {
		input();
		
		while (true)
		{
			
			if (homanPos.isEmpty())
			{
				System.out.println("IMPOSSIBLE");
				break;
			}
			
			boolean flag = humanMoving();
			
			if (flag)
			{
				System.out.println(Result);
				break;		
			}
			
			fireMoving();
			
			//showVisited(humanVisited);
			//System.out.println();
			//showVisited(fireVisited);
			//System.out.println(Result);
			//System.out.println("======================");
		}
	}
	
	static void input() throws IOException 
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Row = Integer.parseInt(st.nextToken());
		Col = Integer.parseInt(st.nextToken());
		
		matrix = new char[Row+1][Col+1];
		humanVisited = new boolean[Row+1][Col+1];
		fireVisited  = new boolean[Row+1][Col+1];
		
		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			
			for (int j = 0; j < buffer.length(); j++) {
				matrix[i][j+1] = buffer.charAt(j);
				if (matrix[i][j+1] == 'J')
				{
					homanPos.add(new int[] {i,j+1});
					humanVisited[i][j+1] = true;		
				}
				if (matrix[i][j+1] == 'F')
				{
					firePos.add(new int[] {i, j+1});
					fireVisited[i][j+1] = true;
				}
			}
		}
	}
	
	static void showVisited(boolean[][] visited)
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.print(visited[i][j] + " ");
			}System.out.println();
		}
	}
	
	
	static boolean inTheMatrix(int xpos, int ypos)
	{
		return xpos >= 1 && xpos <= Row && ypos>= 1 && ypos <= Col;
	}
	
	
	static boolean humanMoving()
	{
		++Result;
		int qSize = homanPos.size();
		
		
		for (int i = 0; i < qSize; i++) 
		{
			int xpos = homanPos.peek()[0];
			int ypos = homanPos.peek()[1];
			homanPos.poll();
			
			if (fireVisited[xpos][ypos])
				continue;
			if (xpos == 1 || xpos == Row || ypos == 1 || ypos == Col)
				return true;
			
			for (int j = 0; j < 4; j++) {
				
				int x = xpos + x_move[j];
				int y = ypos + y_move[j];
				
				if (!inTheMatrix(x,y)) continue;
				if (humanVisited[x][y]) continue;
				if (matrix[x][y] == '#') continue;
				if (fireVisited[x][y]) continue;
				
				humanVisited[x][y] = true;
				homanPos.add(new int[] {x,y});
			}
		}
		return false;
		

	}
	
	static void fireMoving()
	{
		int qSize = firePos.size();
		
		for (int i = 0; i < qSize; i++) {
			int xpos = firePos.peek()[0];
			int ypos = firePos.peek()[1];
			firePos.poll();
			
			for (int j = 0; j < 4; j++) 
			{
				
				int x = xpos + x_move[j];
				int y = ypos + y_move[j];
				
				if (!inTheMatrix(x,y)) continue;
				if (fireVisited[x][y]) continue;
				if (matrix[x][y] == '#') continue;
				
				fireVisited[x][y] =  true;
				firePos.add(new int[] {x,y});
			}
		}
	}


}
