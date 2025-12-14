import java.util.*;
import java.awt.image.DataBufferDouble;
import java.io.*;

public class Main {
	static int Row, Col, Time;
	static int[][] matrix;
	static boolean[][] visited;
	static Queue<int[]> meltingQueue = new ArrayDeque<>(); // xpos, ypos, meltCount
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static final int[] x_move = { -1, 1, 0, 0 }; // 상 하 좌 우
	static final int[] y_move = { 0, 0, -1, 1 };
	static boolean isWater = false; // water이 있는지 없는지 -> 없으면 Time = 0
	static boolean isIce = false;
	public static void main(String args[]) throws IOException {
		input();
		if (isIce == false) {
			bw.write("0");
			bw.flush();
			System.exit(0);
		}
		/*
		 * System.out.println("THis is initial matrix"); showMatrix();
		 * System.out.println();
		 */

		while (checkComponent()) {
			if (allMelting())
			{
				bw.write("0");
				bw.flush();
				System.exit(0);
			}
			melting();
			//showMatrix();
			resetVisited();
			Time++;
		}
		bw.write(Integer.toString(Time));
		bw.flush();
	}
	
	static boolean allMelting()
	{
		boolean res = true;
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++)
			{
				if (matrix[i][j] != 0)
					return false;				
			}
		}
		return true;
	}
	
	static void showMatrix() {
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++)
				System.out.printf("%d ", matrix[i][j]);
			System.out.println();
		}
	}

	static void showMeltingQueue() {
		for (int[] arr : meltingQueue) {
			String str = Integer.toString(arr[0]) + Integer.toString(arr[1]) + Integer.toString(arr[2]);
			System.out.println(str);
		}
	}

	static void input() throws IOException {
		String buffer = br.readLine();
		StringTokenizer st = new StringTokenizer(buffer);

		Row = Integer.parseInt(st.nextToken());
		Col = Integer.parseInt(st.nextToken());

		matrix = new int[Row + 1][Col + 1];
		visited = new boolean[Row + 1][Col + 1];

		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			for (int j = 0; j < Col; j++) {
				matrix[i][j + 1] = Integer.parseInt(st.nextToken());
				if (matrix[i][j + 1] == 0)
					isWater = true;
				else if (matrix[i][j+1] != 0 )
					isIce = true;
			}
		}
	}

	static boolean inTheMatrix(int xpos, int ypos) {
		return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}

	static int checkMeltingCount(int xpos, int ypos) {
		/**
		 * 4방탐색으로 melting할 count를 return한다 return값 : melting할 개수 만약 안에 있다면 0을 return함
		 */

		int res = 0;

		for (int i = 0; i < 4; i++) {
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];

			if (!inTheMatrix(x, y) || matrix[x][y] != 0) // matrix밖에 있거나, 물이 아니라면
				continue;
			res++;
		}
		return res;
	}

	static void dfs(int xpos, int ypos) {
		visited[xpos][ypos] = true;

		int meltingCount = checkMeltingCount(xpos, ypos);

		if (meltingCount != 0) // 겉에 있는 경우
			meltingQueue.add(new int[] { xpos, ypos, meltingCount });

		for (int i = 0; i < 4; i++) {
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];

			if (!inTheMatrix(x, y) || visited[x][y] || matrix[x][y] == 0) // map 밖이거나 방문했거나 물인 경우
				continue;
			dfs(x, y);
		}
	}

	static void resetVisited() {
		for (int i = 1; i <= Row; i++)
			Arrays.fill(visited[i], false);
	}

	static boolean checkComponent() {
		/**
		 * 그래프 탐색과 녹을 좌표를 checking한다. 만약 component가 2개 이상이라면 false return한다.
		 */

		int dfsCount = 0;

		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				if (visited[i][j] == true || matrix[i][j] == 0)
					continue;
				++dfsCount;
				if (dfsCount > 1)
					return false;
				dfs(i, j);
			}
		}
		return true;
	}

	static void melting() {
		int qSize = meltingQueue.size();

		for (int i = 0; i < qSize; i++) {
			int[] tmp = meltingQueue.poll();

			int xpos = tmp[0];
			int ypos = tmp[1];
			int meltingCount = tmp[2];

			if (matrix[xpos][ypos] <= meltingCount)
				meltingQueue.add(new int[] { xpos, ypos, 0 });
			matrix[xpos][ypos] -= meltingCount;
		}

		//showMeltingQueue();
		qSize = meltingQueue.size();
		for (int i = 0; i < qSize; i++) {
			int[] tmp = meltingQueue.poll();

			int xpos = tmp[0];
			int ypos = tmp[1];
			int count = tmp[2];
			matrix[xpos][ypos] = count;
		}
	}
}
