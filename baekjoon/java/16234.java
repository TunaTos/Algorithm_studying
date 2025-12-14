import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static int[] x_move = {-1, 1, 0, 0}, y_move = {0, 0, -1, 1};
	static int Len, lBound, uBound;
	static boolean[][] visited;
	static int[][] matrix;
	static int res = 0;

	public static void main(String[] args) throws IOException {
		input();
		
		while (true) {
			boolean flag = false;
			visited = new boolean[Len + 1][Len + 1];
			
			for (int i = 1; i <= Len; i++) {
				for (int j = 1; j <= Len; j++) {
					if (!visited[i][j] && shouldMove(i, j)) {
						if (bfs(i, j)) {
							flag = true;
						}
					}
				}
			}
			
			if (!flag) {
				System.out.println(res);
				return;
			}
			++res;
		}
	}

	static boolean inTheMatrix(int xpos, int ypos) {
		return xpos >= 1 && xpos <= Len && ypos >= 1 && ypos <= Len;
	}

	static boolean bfs(int xpos, int ypos) {
		Queue<int[]> q = new LinkedList<>();
		List<int[]> union = new ArrayList<>();
		
		q.add(new int[] {xpos, ypos});
		union.add(new int[] {xpos, ypos});
		visited[xpos][ypos] = true;
		
		int sum = matrix[xpos][ypos];
		int count = 1;

		while (!q.isEmpty()) {
			int[] tmp = q.poll();
			int xStand = tmp[0];
			int yStand = tmp[1];

			for (int i = 0; i < 4; i++) {
				int x = xStand + x_move[i];
				int y = yStand + y_move[i];

				if (!inTheMatrix(x, y) || visited[x][y]) continue;

				int distance = Math.abs(matrix[xStand][yStand] - matrix[x][y]);

				if (distance >= lBound && distance <= uBound) {
					visited[x][y] = true;
					q.add(new int[] {x, y});
					union.add(new int[] {x, y});
					sum += matrix[x][y];
					count++;
				}
			}
		}

		int newVal = sum / count;
		boolean changed = false;

		for (int[] pos : union) {
			if (matrix[pos[0]][pos[1]] != newVal) {
				changed = true;
			}
			matrix[pos[0]][pos[1]] = newVal;
		}

		return changed;
	}

	static boolean shouldMove(int xpos, int ypos) {
		for (int i = 0; i < 4; ++i) {
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];

			if (!inTheMatrix(x, y)) continue;

			int distance = Math.abs(matrix[xpos][ypos] - matrix[x][y]);
			if (distance >= lBound && distance <= uBound) {
				return true;
			}
		}
		return false;
	}

	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		Len = Integer.parseInt(st.nextToken());
		lBound = Integer.parseInt(st.nextToken());
		uBound = Integer.parseInt(st.nextToken());
		matrix = new int[Len + 1][Len + 1];

		for (int i = 1; i <= Len; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= Len; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
}
