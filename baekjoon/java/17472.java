import java.io.*;
import java.util.*;

// 섬의 개수는 2개 이상이다!

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;
	
	static int[][] matrix;
	static boolean[][] visited;
	static int[] weights, parents, x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
	static List<int[]> edges = new ArrayList<>(); // weight, pos1, pos2
	static int Row, Col, V; // V -> Conponent의 개수

	public static void main(String[] args) throws IOException {
		
		input();
		V = getVertex();
		initParents();
		//showMatrix();
		setEdges();
		
		//for (int[] tmp: edges)
		//{
		//	System.out.println(Arrays.toString(tmp));
		//}
		Collections.sort(edges, (a,b) -> {
			return Integer.compare(a[0], b[0]);
		});
		
		Runnable r = () -> {
			System.out.println(Kruskal());
		};
		r.run();
		
		



	}
	
	static int Kruskal()
	{
		int treeSum = 0;
		int edgeCount = 0;
		
		
		for (int[] edge: edges)
		{
			int cost = edge[0];
			int node1 = edge[1];
			int node2 = edge[2];
			
			if (Find(node1) == Find(node2))
				continue;
			
			if (cost < 2)
				continue;
			
			Union(node1, node2);
			edgeCount++;
			treeSum += cost;
			
			if (edgeCount == V - 1)
				return treeSum;
		}
		
		return -1;
	}
	static void moving(int dir, int xpos, int ypos)
	{
		// flag인 초기값을 기준으로 dir으로 움직인다 -> 정답은 cnt임!
		// 마지막 정답은 cnt를 하나 빼줘야함!
		// 1 -> 상 , 2 -> 하, 3 -> 좌, 4 -> 우
		int res = 1;
		int flag = matrix[xpos][ypos];
	
		
		while (true)
		{
			int x = xpos + (x_move[dir] * res);
			int y = ypos + (y_move[dir] * res);
		
			if (!inTheMatrix(x,y)) return ;
			if (flag == matrix[x][y]) return ;
			
			if (matrix[x][y] != 0 && matrix[x][y] != flag)
			{
				edges.add(new int[] {res - 1, matrix[xpos][ypos], matrix[x][y]});
				//System.out.println(res - 1 + " " + matrix[xpos][ypos] + " " + matrix[x][y] + " " + dir);
				//System.out.println("original pos : " + xpos+ " " + ypos);
				//System.out.println("target pos : " + x + " " + y);
				return ;
			}
			++res;
		}
	}
	
	
	static void setEdges()
	{
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				if (matrix[i][j] == 0) continue;
				
				int flag = matrix[i][j];
				
				moving(0, i,j);
				moving(1, i,j);
				moving(2, i,j);
				moving(3, i,j);
			}

		}
	}
	
	
	
	static void showMatrix()
	{
		for(int i = 1; i <= Row; ++i)
		{
			for (int j = 1; j <= Col; j++) {
				System.out.printf("%d ", matrix[i][j]);
			}System.out.println();
		}
	}
	
	
	static void initParents()
	{
		parents = new int[V+1];
		weights = new int[V+1];
		
		Arrays.fill(weights, 1);
		for (int i = 1; i <= V; ++i)
			parents[i] = i;
	}
	
	static void dfs(int xpos, int ypos, int flag)
	{
		visited[xpos][ypos] = true;
		matrix[xpos][ypos] = flag;
		for (int i = 0; i < 4; ++i)
		{
			int x = xpos + x_move[i];
			int y = ypos + y_move[i];
			
			if (!inTheMatrix(x,y)) continue;
			if (visited[x][y]) continue;
			if (matrix[x][y] == 0) continue;
			
			dfs(x,y, flag);
		}
	}
	
	static int getVertex()
	{
		// matrix를 탐색해서 Component의 갯수를 가져온다!
		int res = 0;
		
		for (int i = 1; i <= Row; i++) {
			for (int j = 1; j <= Col; j++) {
				if (matrix[i][j] == 0) continue;
				if (visited[i][j]) continue;
				
				++res;
				dfs(i,j, res);
			}
		}
		return res;
	}
	
	
	static boolean inTheMatrix(int xpos, int ypos)
	{
		return xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col;
	}
	
	static void input() throws IOException
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		Row = Integer.parseInt(st.nextToken());
		Col = Integer.parseInt(st.nextToken());
		
		matrix = new int[Row+1][Col+1];
		visited = new boolean[Row+1][Col+1];
		
		
		for (int i = 1; i <= Row; i++) {
			buffer = br.readLine();
			st= new StringTokenizer(buffer);
			for (int j = 1; j <= Col; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static int Find(int a)
	{
		if (parents[a] == a)
			return a;
		else 
			return parents[a] = Find(parents[a]);
	}
	
	static void Union(int a, int b)
	{
		a = Find(a); b = Find(b);
		if (a == b)
			return ;
		
		else if (weights[a] <= weights[b])
		{
			parents[a] = b;
			weights[b] += weights[a];
		}
		else
		{
			parents[b] = a;
			weights[a] += weights[b];
		}
	}
	
}
