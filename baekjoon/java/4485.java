import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static int Len;
	static int[][] matrix, dis;
	static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};

	// ✅ 새로운 클래스 정의
	static class Node implements Comparable<Node> {
		int cost;
		int x;
		int y;

		Node(int cost, int x, int y) {
			this.cost = cost;
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Node other) {
			return Integer.compare(this.cost, other.cost);
		}
	}
	
	public static void main(String[] args) throws IOException {
		int Case = 1;
		
		while (true) {
			Len = Integer.parseInt(br.readLine());
			if (Len == 0) break;

			input();
			int Result = Dijkstra();
			System.out.printf("Problem %d: %d\n", Case, Result);
			++Case;
		}
	}
	
	static void input() throws IOException {
		matrix = new int[Len+1][Len+1];
		dis = new int[Len+1][Len+1];
		
		for (int i = 1; i <= Len; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			Arrays.fill(dis[i], 987654321);
			for (int j = 1; j <= Len; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static boolean inTheMatrix(int xpos, int ypos) {
		return xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len;
	}
	
	static int Dijkstra() {
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(matrix[1][1], 1, 1));
		dis[1][1] = matrix[1][1];
		
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			int w = cur.cost;
			int xpos = cur.x;
			int ypos = cur.y;

			if (w > dis[xpos][ypos]) continue;
			if (xpos == Len && ypos == Len) return w;
			
			for (int i = 0; i < 4; i++) {
				int x = xpos + x_move[i];
				int y = ypos + y_move[i];
				
				if (!inTheMatrix(x, y)) continue;
				if (dis[x][y] > dis[xpos][ypos] + matrix[x][y]) {
					dis[x][y] = dis[xpos][ypos] + matrix[x][y];
					pq.offer(new Node(dis[x][y], x, y));
				}
			}
		}
		return -1;
	}
}
