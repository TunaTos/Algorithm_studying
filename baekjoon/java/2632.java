import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	static StringBuilder sb;
	
	static final int MAX_LEN = 2_000_000;
	static int N, Len1, Len2;
	static int[] number1, number2, dp1, dp2; 
	static int[] pieces1, pieces2;
	

	public static void main(String[] args) throws IOException {
		input();
		
		//showArray(number1);
		//showArray(dp1);
		//showArray(number2);
		//showArray(dp2);
		

		updatePieces(number2, dp2, pieces2, Len2);
		updatePieces(number1, dp1, pieces1, Len1);
		int res =0;
		pieces1[0] = 1;
		pieces2[0] = 1;
		
		// 
		for (int i = 0; i <= N; ++i)
		{
			int i2 = N - i;
			
			res += pieces1[i] * pieces2[i2];
		}
		
		System.out.println(res);
	}
	
	static int nextIndex(int idx, int maxLen)
	{
		if (maxLen == idx)
			return 1;
		else
			return ++idx;
	}
	
	static void updatePieces(int[] number, int[] dp, int[] piece, int Len)
	{
		// 전체를 주는 것을 input한다
		piece[dp[Len]]++;
		
		for (int i = 1; i <= Len - 1; i++) {
			
			int left = 0;
			int right = i;
			int sum = dp[right] - dp[left];
			for (int j = 1; j <= Len; j++) {	
				piece[sum]++;
				
				left = nextIndex(left, Len);
				right = nextIndex(right, Len);
				sum -= number[left];
				sum += number[right];
			}
		}
	}
	
	
	
	
	static void showArray(int[] arr)
	{
		System.out.println(Arrays.toString(arr));
	}
	
	static void input() throws IOException {
		N = Integer.parseInt(br.readLine());
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Len1 = Integer.parseInt(st.nextToken());
		Len2 = Integer.parseInt(st.nextToken());
		
		// init Container;
		pieces1 = new int[MAX_LEN+1];
		pieces2 = new int[MAX_LEN+1];
		number1 = new int[Len1+1];
		dp1 = new int[Len1+1];

		number2 = new int[Len2+1];
		dp2 = new int[Len2+1];
		
		
		for (int i = 1; i <= Len1; i++) {
			number1[i] = Integer.parseInt(br.readLine());
			dp1[i] = number1[i];
			
			dp1[i] += dp1[i-1];
		}
		
		for (int i = 1; i <= Len2; i++) {
			number2[i] = Integer.parseInt(br.readLine());
			dp2[i] = number2[i];
			
			dp2[i] += dp2[i-1];
		}
	}
}
