import java.util.*;
import java.io.*;

public class Main {
	static int N;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static List<Integer> numbers = new LinkedList<Integer>();
	static int res;

	public static void main(String[] args) throws IOException{
		N = Integer.parseInt(br.readLine());
		int range = 1;
		while (res <= N  && range <= 10) // 감소하는 수의 가장 큰 수 : 1000000000 -> 따라서 range는 <= 10이 되어야 한다. (이거 채크 못해서 고생함)
		{

			for(int i = 0; i <= 9; ++i) {
				numbers.add(i);
				dfs(0,1,range);
				numbers.remove(numbers.size() - 1);
			}
			++range;
		}
		
		System.out.println(-1);
	}
	
	static void dfs(int idx, int dpt, int n) {
		if (numbers.size() == n)
		{
			
			//for (int number: numbers)
			//	System.out.print(number + " ");
			//System.out.println();
			++res;
			if (res == N)
			{
				for (int number: numbers)
					System.out.print(number);
				System.exit(0); // 주의!! exit(0)을 안하면 런타임 에러 (NZEC)이 발생한다.
			}
			//System.out.println("I am range n res : " + n + " " + res);
			return ;
		}
		
		for (int i = 0; i <= 9; ++i) 
		{
			numbers.add(i); // 다음 값을 넣고
			if (numbers.size() >= 2 && numbers.get(numbers.size() - 1) < numbers.get(numbers.size() - 2)) // 감소하지 않는다면
				dfs(idx, dpt+1, n);
			numbers.remove(numbers.size() - 1);
		}
	}	
}