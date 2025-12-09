import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;

class Main {
	/**
	 * a가 b보다 순위가 높다 -> a->b의 방향그래프로 modeling할 수 있다.
	 * Floyd를 사용해서 a에서 b(matrix[i][j] or matrix[j][i]까지 가는 경로가 정해지면 알 수 있는 것
	 */
	
	static int V, E;
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static long[][] matrix;
	static final long INF = 987654321;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		input();
		Floyd();
		
		for (int i = 1; i <= V; i++) {
			int res = 0;
			for (int j = 1; j <= V; j++) {
				if (matrix[i][j] == INF && matrix[j][i] == INF)
					++res;
			}
			sb.append(res + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
	}
	
	static void showMatrix() {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				System.out.print(matrix[i][j] + " ");
			}System.out.println();
		}
	}
	
	
	static void input() throws IOException {
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		matrix = new long[V+1][V+1];
		for (int i = 0; i <= V; i++) {
			Arrays.fill(matrix[i], INF);
			matrix[i][i] = 0;
		}
		
		int from, to;
		long cost;
		for (int i = 0; i < E; i++) {
			String buffer = new String(br.readLine());
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			
			
			matrix[from][to] = Long.min(matrix[from][to], 1);
		}
	}
	
	static void Floyd() {
		
		for (int k = 1; k <= V; k++) 
			for (int s = 1; s <= V; s++) 
				for (int e = 1; e <= V; e++) 
					if (matrix[s][e] > matrix[s][k] + matrix[k][e])
						matrix[s][e] = matrix[s][k] + matrix[k][e];
	}
}