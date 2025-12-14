
import java.io.*;
import java.util.*;


public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static String buffer;
	
	static int V;
	static Long[][] matrix;
	static long[] maxVal;
	
	
	public static void main(String[] args) throws IOException {
		input();
		//showMatrix();
		//System.out.println();
		Floyd();
		
		maxVal = new long[V+1];
		maxVal[0] = 987654321L;
		
		for (int i = 1; i <= V; ++i)
		{
			long tmp = 0;
			for (int j = 1; j <= V; ++j)
			{
				if (matrix[i][j] == 987654321L)
					continue;
				if (tmp < matrix[i][j])
					tmp = matrix[i][j];
			}
			maxVal[i] = tmp;
		}
		
		//showMatrix();
		//System.out.println(Arrays.toString(maxVal));
		
		long minVal = Arrays.stream(maxVal)
							.min()
							.orElse(-1);
		
		List<Integer> l = new ArrayList<>();
		
		int cnt = 0;
		for (int i = 1; i <= V; ++i)
		{
			if (maxVal[i] == minVal)
			{
				++cnt;
				l.add(i);
			}
		}
		
		System.out.println(minVal + " " + cnt);
		for (int num: l)
			System.out.print(num + " ");
		


	}
	
	static void showMatrix()
	{
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				System.out.print(matrix[i][j] + " ");
			}System.out.println();
		}
	}
	
	static void input() throws IOException
	{
		V = Integer.parseInt(br.readLine());
		
		matrix = new Long[V+1][V+1];
		
		for (int i = 1; i <= V; i++) {
			Arrays.fill(matrix[i], 987654321L);
			matrix[i][i] = 0L;
		}
		
		int from, to;
		
		while (true)
		{
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			

			
			if (from == -1 && to == -1)
				break;
			matrix[from][to] = 1L;
			matrix[to][from] = 1L;
		}
	}
		
	static void Floyd()
	{
		for (int m = 1; m <= V; m++) 
		{
				for (int s = 1; s <= V; s++) 
				{
					for (int e = 1; e <= V; e++) 
					{
						if (matrix[s][m] != 987654321L && matrix[m][e] != 987654321L)
							matrix[s][e] = Math.min(matrix[s][e], matrix[s][m] + matrix[m][e]);
					}
				} 			
		}
	}
	
}

