import java.io.*;
import java.util.*;


public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static String buffer;	
	
	static int N, res = Integer.MAX_VALUE;
	static int[][] matrix;
	static boolean[] visited;
	static List<Integer> selected = new ArrayList<>();
	
	
	public static void main(String[] args) throws IOException {
		input();
		dfs();
		System.out.println(res);
	}
	
	

	static void input() throws IOException 
	{
		N = Integer.parseInt(br.readLine());
		
		matrix = new int[N+1][N+1];
		visited = new boolean[N+1];
		
		for (int i = 1; i <= N; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			for (int j = 1; j <= N; j++) 
				matrix[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	
	static boolean prunning(int i)
	{
		if (selected.isEmpty())
			return true;
		
		if (visited[i] || matrix[selected.get(selected.size() - 1)][i] == 0)
			return false;
		
		return true;
		
	}
	
	static void dfs()
	{
		if (selected.size() == N)
		{
			
			int result = 0;
			
			for (int i = 0; i < selected.size() - 1; ++i)
				result += matrix[selected.get(i)][selected.get(i+1)];
			
			int tmp = matrix[selected.get(selected.size() - 1)][selected.get(0)];
			
			if (tmp != 0) {
				res = Math.min(res, result + tmp);
			}
			return;
		}
		
		
		for (int i = 1; i <= N; i++) {
			if (prunning(i))
			{
				selected.add(i);
				visited[i] = true;
				
				dfs();
				
				selected.remove(selected.size() - 1);
				visited[i] = false;
			}
		}
	}
	
}
