
import java.util.*;
import java.io.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static int Row, Col;
	static int[][] matrix, dis;
	static int[] x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
	
	public static void main(String[] args) throws IOException {
		input();
		System.out.println(Dijkstra());
	}
	
	static void input() throws IOException {
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Col = Integer.parseInt(st.nextToken());
		Row = Integer.parseInt(st.nextToken());
		
		matrix = new int[Row + 1][Col + 1];
		dis = new int[Row + 1][Col + 1];
		
		for (int i = 1; i <= Row; i++) {
			Arrays.fill(dis[i], 987654321);
			buffer = br.readLine();
			for (int j = 0; j < buffer.length(); j++) {
				matrix[i][j + 1] = buffer.charAt(j) - '0';
			}
		}
	}
	
	static boolean inTheMatrix(int xpos, int ypos) {
		return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}
	
	static int Dijkstra() {
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);  // 벽을 부순 횟수 기준 오름차순
			}
		});
		
		pq.offer(new int[] {0, 1, 1}); // {벽 부순 수, x, y}
		dis[1][1] = 0;
		
		while (!pq.isEmpty()) {
			int[] tmp = pq.poll();
			int w = tmp[0];
			int xpos = tmp[1];
			int ypos = tmp[2];
			
			if (w > dis[xpos][ypos]) continue;
			if (xpos == Row && ypos == Col) return w;
			
			for (int i = 0; i < 4; i++) {
				int x = xpos + x_move[i];
				int y = ypos + y_move[i];
				
				if (!inTheMatrix(x, y)) continue;
				
				if (dis[x][y] > matrix[x][y] + dis[xpos][ypos]) {
					dis[x][y] = matrix[x][y] + dis[xpos][ypos];
					pq.offer(new int[] {dis[x][y], x, y});
				}
			}
		}
		return -1;
	}
}
