/**
 * 수열의 인덱스는 1부터 시작한다
 * segTree에서 어떤 값을 넣을 것인가?
 * 
 * 그냥 짝수의 개수를 넣자!
 * 그러면 홀수의 개수는 빼면 되니까!
 * 
 */


import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	static int N, H, treeSize, Q, startNode;
	static int[] segTree; // 짝수의 개수는 몇개인가?
	static int[] numbers;

	
	public static void main(String[] args) throws IOException {
		input();	
		buildTree();
		//showTree();
		doQuery();
	}
	
	
	static void showTree()
	{
		for (int i = 1; i < treeSize; ++i)
			System.out.printf("%d ", segTree[i]);
	}
	static void input() throws IOException {
		N = Integer.parseInt(br.readLine());
		H = (int)Math.ceil(Math.log(N) / Math.log(2));
		treeSize = 1 <<(H+1);
		segTree = new int[treeSize];
		startNode = treeSize / 2 - 1;
		
	}
	
	static void buildTree() throws IOException
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		int tmp;
		numbers = new int[N+1];
		
		for (int i = 0; i < N; i++) {
			tmp = Integer.parseInt(st.nextToken());
			numbers[i+1] = tmp;
			if (tmp % 2 ==0)
				segTree[startNode + i + 1] = 1;
		}
		
		int parents = startNode;
		
		for (int i = parents; i >= 1; --i)
		{
			int left = i * 2;
			int right = i * 2 + 1;
			
			segTree[i] = segTree[left] + segTree[right];
		}
	}
	
	static void doQuery() throws IOException {
		Q = Integer.parseInt(br.readLine());
		int flag, left, right;
		
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st= new StringTokenizer(buffer);
			
			flag = Integer.parseInt(st.nextToken());
			left = Integer.parseInt(st.nextToken());
			right = Integer.parseInt(st.nextToken());
			
			if (flag == 1)
				update(left, right);
			if (flag == 2) // 짝수의 개수를 출력하라
			{
				int res = getEvenNumber(left, right);
				sb.append(res).append("\n");
			}

			else if (flag == 3)
			{
				int res = getEvenNumber(left, right);
				res = right - left + 1 - res;
				
				sb.append(res).append("\n");
			}	
		}
		bw.write(sb.toString());
		bw.flush();
	}
	
	static int getEvenNumber(int left, int right) {
		int res = 0;
		
		left = treeSize / 2 + left - 1;
		right = treeSize / 2 + right - 1;
		
		while (left <= right)
		{
			// 범위를 벗어나는 경우
			if (left % 2 ==1)
				res += segTree[left++];
			if (right % 2 == 0)
				res += segTree[right--];
			
			if (left == right)
				res += segTree[left];
			
			left = left / 2;
			right = right / 2;
		}
		
		
		
		return res;
	}
	
	static void update(int idx, int number)
	{
		if (number % 2 == numbers[idx] % 2) // 변경을 할 필요가 없는 경우!
			return ;
		
		
		// 트리에서의 리프 인덱스 //  부모 idx
		int treeIdx = startNode + idx;		
		int parents = treeIdx / 2;
		
		numbers[idx] = number; // 원본 배열 update

		if (segTree[treeIdx] == 1)
			segTree[treeIdx] = 0;
		else if (segTree[treeIdx] == 0)
			segTree[treeIdx] = 1;
		
		for (int i = parents; i >= 1; i = i/2)
		{
			int left = i * 2;
			int right = i * 2 + 1;
			
			segTree[i] = segTree[left] + segTree[right];
		}
	}
}
