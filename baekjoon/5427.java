import java.util.*;
import java.io.*;



public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static int x_move[] = {-1,1,0,0}; // 상 하 좌 우
	static int y_move[] = {0,0,-1,1}; 
	
	public static void main(String[] args) throws IOException {
		buffer = br.readLine();
		StringTokenizer st = new StringTokenizer(buffer);
		
		
		int Tcase = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < Tcase; ++i)
		{
			int tmp = solve();
			if (tmp == -1)
				bw.write("IMPOSSIBLE\n");
			else
				bw.write(Integer.toString(tmp) + "\n");
			bw.flush();
		}
	}
	
	
	
	public static void showMatrix(int[][] matrix, int Row, int Col)
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	public static void showVisited(boolean[][] matrix, int Row, int Col)
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				if (matrix[i][j] == true)
					System.out.printf("1 ");
				else
					System.out.printf("0 ");
			}System.out.println();
		}
	}
	
	
	public static boolean inTheMatrix(int xpos, int ypos, int Row, int Col)
	{
		return xpos >= 1 && xpos <= Row && ypos >=1 && ypos <= Col;
	}
	
	public static int solve() throws IOException
	{
		int Col, Row;
		buffer = br.readLine();
		StringTokenizer st = new StringTokenizer(buffer);
		
		Col = Integer.parseInt(st.nextToken());
		Row = Integer.parseInt(st.nextToken());
		
		// visited 와 fire distance배열을 생성한다.
		
		boolean[][] visited = new boolean [Row+1][Col+1];
		int[][] fire = new int[Row+1][Col+1];
		int[][] distance = new  int[Row+1][Col+1];
		
		int sXpos = 0;
		int sYpos = 0;
		Queue<int[]> fires = new ArrayDeque<>();
		Queue<int[]> human = new ArrayDeque<>();
		
			
		// init
		for (int i = 1; i <= Row; ++i)
		{
			buffer = br.readLine();
			for (int j = 0; j < buffer.length(); ++j)
			{
				char c = buffer.charAt(j);
				
				if (c == '#') // 벽 표시
					visited[i][j+1] = true;
				else if (c == '*')
				{
					fires.add(new int[]{i, j+1});
					fire[i][j+1] = 1;
				}
				else if (c == '@')
				{
					sXpos = i;
					sYpos = j+1;
					human.add(new int[] {i, j+1});
				}
			}
		}
		
		if (sXpos == 1 || sXpos == Row || sYpos == 1 || sYpos == Col)
			return 1;
	
		int result = -1;
		

		while (!human.isEmpty())
		{
			int fSize = fires.size();
			int hSize = human.size();
			
			
			// 불이 먼저 움직인다
			for (int i = 0; i < fSize; i++) 
			{
				int[] arr = fires.poll();
				int xpos = arr[0];
				int ypos = arr[1];
				
				
				for (int j = 0; j < 4; j++) 
				{
					int x = xpos + x_move[j];
					int y = ypos + y_move[j];
					
					if (!inTheMatrix(x, y, Row, Col)) continue;
					if (visited[x][y] == true) continue;
					if (fire[x][y] == 1) continue; // 이미 불이 난 경
					
					fire[x][y] = 1;
					fires.add(new int[] {x,y});
				}
			}

			for (int i = 0; i < hSize; i++) 
			{
				int[] arr = human.poll();
				int xpos = arr[0];
				int ypos = arr[1];
				visited[xpos][ypos] = true;
				
				
				for (int j = 0; j < 4; j++) 
				{
					int x = xpos + x_move[j];
					int y = ypos + y_move[j];
					
					if (!inTheMatrix(x, y, Row, Col)) continue; // 밖에 있는 경우
					if (visited[x][y] == true) continue; // 방문한 경우 or 벽
					if (fire[x][y] == 1) continue; // 불인 경우
					
					distance[x][y] = distance[xpos][ypos] + 1;
					if (x == 1 || x == Row || y == Col || y  == 1)
					{
						result = distance[x][y] + 1;
						return result;
					}
					visited[x][y] = true; // 방문처리
					human.add(new int[] {x,y});
				}
			}			
			/*System.out.println("I am fire");
			showMatrix(fire, Row, Col);
			System.out.println("I am distance");
			showMatrix(distance, Row, Col);
			System.out.println("I am visited");
			showVisited(visited, Row, Col);
			*/
		}
		return -1; // 불가능한 경우
		
		
		

		
		
		
		
	}
	
	
}
