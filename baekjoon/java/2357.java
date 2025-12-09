/**
 * update는 없는 것 같다!
 */
import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static String buffer;
	
	static int N, M, H, treeSize;
	static long[] maxTree, minTree;
	
	
	
	public static void main(String[] args) throws IOException {
		input();
		makeTree();
		
		//showTree(maxTree);
		//showTree(minTree);
		
		for (int i = 0; i < M; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			
			getQuery(left, right);
		}
		
	}
	
	static void showTree(long[] tree)
	{
		for (int i =1; i < treeSize; ++i)
			System.out.print(tree[i] + " ");
		System.out.println();
	}
	
	static void input() throws IOException {
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = (int) Math.ceil(Math.log(N) / Math.log(2));
		treeSize = 1 << (H + 1);

		// make container
		maxTree = new long[treeSize];
		minTree = new long[treeSize];
	}
	
	static void makeTree() throws IOException
	{

		long num;
		for (int i = 0; i < N; i++) {
			num = Long.parseLong(br.readLine());
			
			
			minTree[treeSize/2 + i] = num;
			maxTree[treeSize/2 + i] = num;			
		}
		
		int parent = treeSize/2 - 1;
		for (int i = parent; i >= 1; --i)
		{
			int left = i * 2;
			int right = left + 1;
			
			minTree[i] = Long.min(minTree[left], minTree[right]);
			maxTree[i] = Long.max(maxTree[left], maxTree[right]);
		}
	}
	
	static void getQuery(int left, int right)
	{
		long minResult = Long.MAX_VALUE;
		long maxResult = Long.MIN_VALUE;
		
		left = treeSize / 2 + left - 1;
		right = treeSize / 2 + right - 1;
		while (left <= right)
		{
			//System.out.println("I am left and right" + left + " " + right);
			if (left % 2 == 1) 
			{
				minResult = Long.min(minResult, minTree[left]);
				maxResult = Long.max(maxResult, maxTree[left]);
				++left;
			}
			if (right % 2 == 0)
			{
				minResult = Long.min(minResult, minTree[right]);
				maxResult = Long.max(maxResult, maxTree[right]);
				--right;
			}
		
			if (left == right)
			{
				minResult = Long.min(minResult, minTree[left]);
				maxResult = Long.max(maxResult, maxTree[left]);
			}
			left = left / 2;
			right = right / 2;
		}
		
		System.out.println(minResult + " " + maxResult);
	}
	
}
