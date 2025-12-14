
import java.io.*;
import java.util.*;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;

	static int N, K, Q, treeSize;
	static long[] tree;

	public static void main(String[] args) throws IOException {
		while ((buffer = br.readLine()) != null) {
			input();
			makeTree();
			doQuery();
			System.out.println();
		}
	}

	static void doQuery() throws IOException {
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);

			String Query = st.nextToken();
			int num1 = Integer.parseInt(st.nextToken());
			int num2 = Integer.parseInt(st.nextToken());

			if (Query.equals("C"))
				change(num1, num2);
			else if (Query.equals("P"))
				getMult(num1, num2);
		}
	}

	static void input() throws IOException {
		st = new StringTokenizer(buffer);

		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());

		K = (int) Math.ceil(Math.log(N) / Math.log(2));
		treeSize = (int) (2 * Math.pow(2, K));

		tree = new long[treeSize];

		buffer = br.readLine();
		st = new StringTokenizer(buffer);

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(st.nextToken());
			
			if (num > 0)
				tree[treeSize/2 + i] = 1;
			else if (num < 0)
				tree[treeSize/2 + i] = -1;
			else if (num == 0)
				tree[treeSize/2 + i] = 0;
		}
	}

	static void makeTree() {
		for (int i = treeSize / 2 - 1; i >= 1; --i) {
			long left = tree[i * 2];
			long right = tree[i * 2 + 1];
			
			tree[i] = left * right;
		}
	}

	static void change(int idx, int num) {
		idx = treeSize / 2 - 1 + idx;
		
		if (num > 0)
			tree[idx] = 1;
		else if (num < 0)
			tree[idx] = -1;
		else if (num == 0)
			tree[idx] = 0;


		for (int i = idx / 2; i >= 1; i = i / 2)
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
	}

	static void getMult(int left, int right) {
		left = treeSize / 2 - 1 + left;
		right = treeSize / 2 - 1 + right;

		long res = 1;

		while (left <= right) {
			if (left == right) {
				res *= tree[left];
				break;
			}

			if (left % 2 == 1)
				res *= tree[left++];
			if (right % 2 == 0)
				res *= tree[right--];

			left = left / 2;
			right = right / 2;
		}

		if (res == 0)
			System.out.print("0");
		else if (res > 0)
			System.out.print("+");
		else
			System.out.print("-");
	}
}
