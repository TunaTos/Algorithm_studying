
import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static final int INF = 987654321;
	static int V, E, Q;
	static int[][] matrix;
	

	public static void main(String[] args) throws IOException {
		input();
		Floyd();
		//showMatrix();
		doQuery();
	}
	
	static void doQuery() throws IOException
	{
		Q = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			
			int tmp1 = matrix[from][to];
			int tmp2 = matrix[to][from];
			
			
			//System.out.println(tmp1 + " " + tmp2);
			if (tmp1 == tmp2)
				System.out.println(0);
			else
			{
				if (tmp1 == 1)
					System.out.println(-1);
				else
					System.out.println(1);
			}
		}
	}
	
	
	static void showMatrix()
	{
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	static void input() throws IOException
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		matrix = new int[V+1][V+1];
		for (int i = 1; i <= V; i++) {
			Arrays.fill(matrix[i], INF);
			matrix[i][i] = 0;
		}
		
		
		
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			
			matrix[from][to] = 1;
		}
	}
	
	static void Floyd()
	{
		for (int m = 1; m <= V; m++) {
			for (int s = 1; s <= V; s++) {
				for (int e = 1; e <= V; e++) {
					if (matrix[s][m] == 1 && matrix[m][e] == 1)
						matrix[s][e] = 1;
				}
			}
		}
	}

}
