import java.util.*;
import java.io.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	
	static int Tcase, res = 0;
	static int[][] matrix;// index 1부터 시작
	static int[] selected;
	static boolean[] visited; // index 1부터 시작
	
	
	public static void main(String[] args)  throws IOException {
		Tcase = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < Tcase; i++) {
			input();
			permutation(0, 0);
			System.out.println(res);
		}
	}
	
	static void input() throws IOException 
	{
		matrix = new int[12][12];
		selected = new int[11];
		visited = new boolean[12];
		res = 0;
		
		for (int i = 1; i <= 11; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			for (int j = 1; j <= 11; j++) 
				matrix[i][j] = Integer.parseInt(st.nextToken());
		}
	}
	
	static boolean prunning(int dpt, int i)
	{
		// dpt자리에 i가 선수입니다!
		
		if (matrix[dpt][i] != 0 && !visited[i])
			return true;
		return false;
	}
	
	
	
	
	static void permutation(int dpt, int sum)
	{
		if (dpt == 11)
		{			
			res = Integer.max(res, sum);
			return ;
		}
		
		
		for (int i = 1; i <= 11; i++) {
			if (prunning(dpt+1, i))
			{
				visited[i] = true;
				selected[dpt] = i;
				
				permutation(dpt+1, sum + matrix[dpt+1][i]);
				
				visited[i] = false;
			}
		}
		
	}
	
	
	
}
