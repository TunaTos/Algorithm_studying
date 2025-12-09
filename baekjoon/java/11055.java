
import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;

	static int N;
	static int[] numbers, dp;
	
	
	public static void main(String[] args) throws IOException {
		input();
		Lis();
		//System.out.println(Arrays.toString(dp));
		int result = Arrays.stream(dp)
						.max()
						.orElse(-1);
		System.out.println(result);

	}

	static void input() throws IOException 
	{
		N = Integer.parseInt(br.readLine());
		
		numbers = new int[N+1];
		dp = new int[N+1];
		
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		for (int i = 1; i <= N; i++) 
		{
			numbers[i] = Integer.parseInt(st.nextToken());
			dp[i] = numbers[i];
		}

		dp[1] = numbers[1];
	}
	
	static void Lis()
	{
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j < i; j++) {
				if (numbers[i] > numbers[j])
					dp[i] = Math.max(dp[i], dp[j] + numbers[i]);
			}
		}
	}
}
