import java.io.*;
import java.util.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	
	static int N, Q, H, treeSize;
	static long[] segTree;
	
	public static void main(String[] args) throws IOException {
		input();
		buildTree();
		doQuery();
	}
	
	static void showTree()
	{
		for (int i = 1; i < treeSize; ++i)
			System.out.print(segTree[i] + " ");
	}
	
	
	static void input() throws IOException {
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		H = (int)Math.ceil(Math.log(N) / Math.log(2));
		treeSize = 1 << (H+1);
		segTree = new long[treeSize];
		
	}
	
	static void buildTree() throws IOException {
		long tmp;
		for (int i = 0; i < N; ++i)
		{
			tmp = Long.parseLong(br.readLine());
			segTree[treeSize / 2 + i] = tmp;
		}
		
		int parents = treeSize / 2 - 1;
		
		for (int i = parents; i >= 1; i--) {
			int left = i * 2;
			int right = i * 2 + 1;
			
			segTree[i] = Long.min(segTree[left], segTree[right]);
		}
	}
	
	static void doQuery() throws IOException {
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			
			getMin(left, right);
		}
	}
	static void getMin(int left, int right)
	{
		left = treeSize/ 2 - 1 + left;
		right = treeSize / 2 - 1 + right;
		
		
		long res = Long.MAX_VALUE;
		
		while (left <= right)
		{
			if (left % 2 == 1) // 오른쪽에 있는 경우
				res = Long.min(res, segTree[left++]);
			if (right % 2 == 0)
				res = Long.min(res, segTree[right--]);
						
			if (left == right)
				res = Long.min(res, segTree[left]);
			left /= 2;
			right /= 2;
			
			
		}
		
		System.out.println(res);
	}
	
	
}
