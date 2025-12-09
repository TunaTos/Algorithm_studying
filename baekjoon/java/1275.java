import java.io.*;
import java.util.*;



public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static String buffer;
	
	
	static  int N, Q, treeSize, K;
	static long[] tree;
	
	public static void main(String[] args) throws IOException {
		buffer = br.readLine();
		st = new StringTokenizer(buffer);

		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		
		// get TreeSize and make Tree
		K = Math.incrementExact((int) (Math.log(N) / Math.log(2)));


		
		treeSize = (int)Math.pow(2,K + 1) + 1;
		tree = new long[treeSize];
		
		
		// buildTree
		int start = treeSize / 2;
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);

		for (int i = start; i < N + start; ++i)
			tree[i] = Long.parseLong(st.nextToken());
		
		
		start = treeSize / 2 - 1;
		
		for (int i = start; i >= 1; --i)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			
			int idx = Integer.parseInt(st.nextToken());
			Long num = Long.parseLong(st.nextToken());
			
			if (left > right)
			{
				int tmp = left;
				left = right;
				right = tmp;
			}
			System.out.println(getSum(left, right));
			update(idx, num);
		}
		
	}
	
	
	
	static long getSum(int left, int right)
	{
		left = treeSize / 2 - 1 + left;
		right = treeSize / 2 - 1 +right;
		

		long res = 0 ;
		while (left <= right)
		{
			
			if(left == right)
			{
				res += tree[left];
				break;
			}
			if (left % 2 == 1) 
				res += tree[left++];
			if (right % 2 == 0)
				res += tree[right--];
			
		
			left /= 2;
			right /= 2;
			
		}
		
		return res;
	}
	
	static void update(int idx, long number)
	{
		idx = treeSize / 2 - 1 + idx;
		long dis = number - tree[idx];
		//System.out.println(dis);
		while (idx >= 1)
		{
			tree[idx] += dis;
			idx = idx / 2;
		}
	}
}
