/**
 *  왼쪽부터 1자리 2자리 3자리 4자리 모두 소수인 경우를 신기한 소수라고 한다.
 */

import java.util.*;
import java.io.*;



public class Main {
	static int N;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[] prime = {2,3,5,7};
	
	
	
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		dfs(1,2);
		dfs(1,3);
		dfs(1,5);
		dfs(1,7);
	}

	static boolean isPrime(int sum)
	{
		for (int i = 2; i <= Math.sqrt(sum); i++) 
			if (sum % i == 0)
				return false;
		return true;
	}
	
	
	static void dfs(int dpt, int sum)
	{
		if (!isPrime(sum))
			return ;
		if (dpt == N)
		{
			System.out.println(sum);
			return ;
		}
		
		for (int i = 1; i <= 9; i += 2) {
			if (i != 5)
				dfs(dpt+1, sum * 10 + i);		
		}
	}
	
}
