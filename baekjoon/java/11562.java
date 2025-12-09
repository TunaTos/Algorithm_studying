/*
 * 
 * 일방통행인 길들을 양방향으로 바꾸어야하는가?
 * 출발지와 도착지를 입력할 때 도착지까지 가기 위해 몇가지의 길을 양방향으로 변경해야하나?
 * 
 * input)
 * 건물의 수, 길의 수
 * node1 node2 (0,1) -> 0 : 일방통행 // 1 : 양방향 길
 * query 
 * from -> to
 * 쿼리에서 시작점과 도착점이 같은 경우도 있다!
 * 
 * 
 * 두 건물을 잇는 길은 최대 한개이다.
 * 
 * 몇개의 일방통행을 변경해야 갈 수 있는가?
 * 
 */

import java.util.*;
import java.io.*;


public class Main {
	static int V, E, Q;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[][] matrix;
	static String buffer;
	static StringTokenizer st;
	static final int INF = 987654321;
	
	
	public static void main(String[] args) throws IOException{
		input();
		floyd();
		solve();
	}
	
	static void showMatrix() 
	{
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	static void floyd()
	{
		for (int k = 1; k <= V; k++) {
			for (int s = 1; s <= V; s++) {
				for (int e = 1; e <= V; e++) {
					if (matrix[s][k] != INF && matrix[k][e] != INF && matrix[s][e] > matrix[s][k] + matrix[k][e])
						matrix[s][e] = Integer.min(matrix[s][e],matrix[s][k] + matrix[k][e]);
				}
			}
		}
	}
	
	static void input() throws IOException {
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		// init container
		matrix = new int[V+1][V+1];
		for (int i = 0; i <= V; i++) {
			Arrays.fill(matrix[i], INF);
			matrix[i][i] = 0;
		}
		
		
		
		int node1, node2, direct;
		
		for (int i = 0; i < E; i++) 
		{
			buffer = br.readLine();
			st= new StringTokenizer(buffer);
			
			
			node1 = Integer.parseInt(st.nextToken());
			node2 = Integer.parseInt(st.nextToken());
			direct = Integer.parseInt(st.nextToken());
			
			if (direct == 1) // 양방향
				matrix[node1][node2] = matrix[node2][node1] = 0;
			else
			{
				matrix[node1][node2] = 0;
				matrix[node2][node1] = 1;
			}
		}		
	}
	
	static void solve() throws IOException
	{
		Q = Integer.parseInt(br.readLine());
		
		int node1, node2;
		for (int i = 0; i < Q; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			node1 = Integer.parseInt(st.nextToken());
			node2 = Integer.parseInt(st.nextToken());
			
			System.out.println(matrix[node1][node2]);
		}
		
		
		
		
	}
	
}
