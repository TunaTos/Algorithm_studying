
import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;
	
	static final int INF = 987654321;
	static int V, E;
	static int[][] matrix;
	
	
	
	public static void main(String[] args) throws IOException {
		input();
		Floyd();
		//showMatrix();
		
		int result= Arrays.stream(matrix[1])
							.filter(n -> (n != 0 && n != INF))
							.reduce(0, (a,b) -> a + 1);
		
		System.out.println(result);
		
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
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		
		// init Matrix
		matrix = new int[V+1][V+1];
		
		for (int i = 1; i <= V; i++) {
			Arrays.fill(matrix[i], INF);
			matrix[i][i] = 0;
		}
		
		int from, to;
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			
			matrix[from][to] = 1;
			matrix[to][from] = 1;		
		}
	}
	
	static void Floyd()
	{
		for (int m = 1; m <= V; m++) {
			for (int s = 1; s <= V; s++) {
				for (int e = 1; e <= V; e++) {
					matrix[s][e] = Math.min(matrix[s][e], matrix[s][m] + matrix[m][e]);
				}
			}

		}
	}

}
