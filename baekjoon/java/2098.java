
import java.io.*;
import java.util.*;


public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	
	static int N;
	static int[][] matrix;
	static long[][] dp;
	static final long INF = 1_000_000_000_000L;
	
	
	public static void main(String[] args) throws IOException {
		input();
		System.out.println(tsp(1,0));	
	}
	
	
	
	static void input() throws IOException 
	{
		N = Integer.parseInt(br.readLine());
		
		matrix = new int[N][N];
		dp = new long[1 << N][N];
		
		for (long[] arr: dp)
			Arrays.fill(arr, -1);
		
		for (int i = 0; i < N; i++) 
		{
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			for (int j = 0; j < N; j++) 
				matrix[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	
	static long tsp(int visited, int current)
	{
		// dp의 의미 visited까지 다 방문한 상태에서 현재 current에서 출발지까지의 최단거리
		
		if (visited == (1 << N) - 1) // 모두 방문한 경우
		{
			if (matrix[current][0] == 0) // 돌아갈 길이 없는 경우
				return INF;
			else
				return matrix[current][0];
		}
		
		if (dp[visited][current] != -1)
			return dp[visited][current];
		
		long minCost = INF;
		
		for (int next = 0; next < N; next++) {
			if ((visited & (1 << next))!= 0 || matrix[current][next] == 0)
				continue;
			
			long nextVisited = visited | (1 << next);
			long costToNext = matrix[current][next];
			long nextCost = tsp((int)nextVisited, next);
			
			minCost = Math.min(minCost, costToNext + nextCost);
		}
		
		dp[visited][current] = minCost;
		return minCost;
	}
}