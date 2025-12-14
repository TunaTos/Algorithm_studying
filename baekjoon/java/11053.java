
import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	
	static int Len;
	static int[] numbers, dp;
	
	
	public static void main(String[] args) throws IOException {
		input();
		LIS();
		//System.out.println(Arrays.toString(dp));


		int result = Arrays.stream(dp)
							.max()
							.orElse(-1);
		System.out.println(result);

	}
	
	static void input() throws IOException
	{
		Len = Integer.parseInt(br.readLine());
		
		numbers = new int[Len+1];
		dp = new int[Len+1];
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		for (int i = 1; i <= Len; i++) 
			numbers[i] = Integer.parseInt(st.nextToken());
		Arrays.fill(dp, 1);
	}
	
	static void LIS() 
	{
		
		for (int i = 1; i <= Len; i++) {
			for (int j = 1; j < i; j++) {
				if (numbers[i] > numbers[j])
					dp[i] = Math.max(dp[i], dp[j] + 1);
			}
		} 
	}

}
