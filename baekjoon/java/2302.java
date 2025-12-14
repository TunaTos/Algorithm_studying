/**
 * 표시된 자석에 앉아야 한다
 * 그러나 바로 왼쪽이나, 오른쪽으로 옮길 수 있다
 * 
 * VIP는 반드시 자기 좌석에 앉아야 한다.
 * 
 * 1번부터 N번까지는 다 팔렸다.
 * VIP 회원들의 좌석 번호가 주어졌는데, 사람들이 앉을 수 있는 방법의 가짓수를 구하라
 * 
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 
 * 입력 좌석의 개수가 N이 입력된다.
 * 고정석의 개수 M이 입력되는데, M은 0이상 N이하이다.
 */



import java.util.*;
import java.io.*;


public class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	
	static int N, M;
	static int[] vip, dp;
	


	
	
	public static void main(String[] args) throws IOException {
		input();
		long res = 1;
		for (int i = 1; i <= M; i++) {
			int dis = vip[i] - vip[i-1] - 1;
			res *= dp[dis];
		}
		res *= dp[N - vip[M]];
		if (N == M)
			res = 1;
		System.out.println(res);
	}
	
	static void input() throws IOException {
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		// init container
		vip = new int[N+1];
		dp = new int[41];
		
		// init dp
		dp[0] = 1;
		dp[1] = 1; dp[2] = 2;
		for (int i = 3; i <= 40; i++) 
			dp[i] = dp[i-1] + dp[i-2];


	for (int i = 1; i <= M; i++) 
			vip[i] = Integer.parseInt(br.readLine());
	}
}
