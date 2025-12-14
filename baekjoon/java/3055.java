
import java.io.*;
import java.util.*;


public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;
	
	static int Row, Col, sXpos, sYpos, tXpos, tYpos, res;
	static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
	static char[][] matrix;
	static boolean[][] hVisited, wVisited;
	static Queue<int[]> waterQ = new LinkedList<int[]>(); // 물의 xpos, ypos
	static Queue<int[]> humanQ = new LinkedList<int[]>();
	
	public static void main(String[] args) throws IOException {
		input();
		


		
		while (true)
		{
			boolean flag = humanMoving();
			
			if (flag)
			{
				System.out.println(res - 1);
				break;
			}
			waterMoving();
			
			//showVisited(hVisited);
			//System.out.println();
			//showVisited(wVisited);
			//System.out.println();
			
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
	
	static void input() throws IOException 
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Row = Integer.parseInt(st.nextToken());
		Col = Integer.parseInt(st.nextToken());
		
		matrix = new char[Row+1][Col+1];
		hVisited = new boolean[Row+1][Col+1];
		wVisited = new boolean[Row+1][Col+1];
		
		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			
			for (int j = 0; j < Col; j++) {
				matrix[i][j+1] = buffer.charAt(j);
				
				if (matrix[i][j+1] == 'S') // 시작점
				{
					humanQ.add(new int[] {i, j+1});
					hVisited[i][j+1] = true;
				}


				else if (matrix[i][j+1] == 'D') // target
				{
					tXpos = i;
					tYpos = j+1;
				}
				else if (matrix[i][j+1] == '*') // 물인 경우
				{
					waterQ.add(new int[] {i, j+1});
					wVisited[i][j+1] = true;
				}
			}
		}
	}
	
	static boolean inTheMatrix(int xpos, int ypos)
	{
		return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}
	
	static boolean humanMoving()
	{
		
		int qSize = humanQ.size();
		++res;
		
		for (int i = 0; i < qSize; ++i)
		{
			
			int[] tmp = humanQ.poll();
			
			int xpos = tmp[0];
			int ypos = tmp[1];
			
			if (wVisited[xpos][ypos]) continue;
			
			if (xpos == tXpos && ypos == tYpos)
				return true;
			for (int j = 0; j < 4; j++) {
				int x = xpos + x_move[j];
				int y = ypos + y_move[j];
				
				if (!inTheMatrix(x,y)) continue;
				if (hVisited[x][y] || wVisited[x][y]) continue;
				if (matrix[x][y] == 'X') continue;
				
				hVisited[x][y] = true;
				humanQ.add(new int[] {x,y});
			}
		}
		
		if (humanQ.isEmpty())
		{
			System.out.println("KAKTUS");
			System.exit(0);
		}
		return false;
	}
	
	static void waterMoving()
	{
		int qSize = waterQ.size();
		
		for (int i = 0; i < qSize; ++i)
		{
			int[] tmp = waterQ.poll();
			int xpos = tmp[0];
			int ypos = tmp[1];
			
			for (int j = 0; j < 4; j++) {
				int x = xpos + x_move[j];
				int y = ypos + y_move[j];
				
				if (!inTheMatrix(x,y)) continue;
				if (wVisited[x][y]) continue;
				if (matrix[x][y] == 'X') continue;
				if (matrix[x][y] == 'D') continue;
				
				wVisited[x][y] = true;
				waterQ.add(new int[] {x,y});
			}
		}
	}

}
