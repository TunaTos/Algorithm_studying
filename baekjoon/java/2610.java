import java.util.*;
import java.awt.Container;
import java.io.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	static List<Integer>[] adj;
	static List<Integer>[] groups;
	static List<Integer> list = new ArrayList<Integer>();
	
	
	static int V, E, groupNum;
	static long[][] matrix;
	static final long INF = Long.MAX_VALUE;	
	
	public static void main(String[] args) throws IOException {
		input();
		Floyd();
		//showMatrix();
		splitGroup();
		System.out.println(groupNum);
		//showContainer(groups[1]);
		//showContainer(groups[2]);
		//showContainer(groups[3]);
		
		for (int i = 1; i <= groupNum; i++) {
			list.add(getMinVal(i));
		}
		Object[] arr = list.toArray();
		Arrays.sort(arr);
		
		for (Object number : arr)
			System.out.println(number);
		
		//sb.append(groupNum).append("\n");
		
		
	}
	
	static void showMatrix()
	{
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				System.out.print(matrix[i][j] + " ");
			}System.out.println();
		}
	}
	
	static void showContainer(List<Integer> list)
	{
		for (int a: list)
			System.out.print(a + " ");
		System.out.println();
	}
	
	
	static void input() throws IOException {
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		
		matrix = new long[V+1][V+1];
		adj = new ArrayList[V+1];
		groups = new ArrayList[V+1];
		
		
		for (int i = 1; i <= V; i++)
		{
			Arrays.fill(matrix[i], Long.MAX_VALUE);
			matrix[i][i] = 0;
			adj[i] = new ArrayList<Integer>();
		}
		
		
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int node1 = Integer.parseInt(st.nextToken());
			int node2 = Integer.parseInt(st.nextToken());
		
			// 양방향
			matrix[node1][node2] = matrix[node2][node1] = 1;
			adj[node1].add(node2);
			adj[node2].add(node1);
		}
	}
	static void Floyd()
	{
		for (int k = 1; k < V; k++) {
			for (int s = 1; s <= V; s++) {
				for (int e = 1; e <= V; e++) {
					if (matrix[s][k] == INF || matrix[k][e] == INF)
						continue;
					matrix[s][e] = Long.min(matrix[s][e], matrix[s][k] + matrix[k][e]);
				}
			}
		}
	}
	
	static void dfs(int node, boolean[] visited)
	{
		visited[node] = true;
		groups[groupNum].add(node);
		
		for (int next: adj[node])
		{
			if (!visited[next])
				dfs(next, visited);	
		}
	}
	
	
	static void splitGroup()
	{
		boolean[] visited = new boolean[V+1];
		
		for (int i = 1; i <= V; i++) {
			if (!visited[i])
			{
				++groupNum;
				groups[groupNum] = new ArrayList<Integer>();
				dfs(i, visited);
			}
		}
	}
	
	static int getMinVal(int i)
	{
		//List<Integer> list = groups[i];
		Object[] list = groups[i].toArray();
		int maxVal = Integer.MAX_VALUE;
		int res =  -1;
		
		for (int j = 0; j < list.length; j++) {
			int tmp = 0;
			for (int j2 = 0; j2 < list.length; j2++) {
				tmp =  Integer.max(tmp,(int) matrix[(int) list[j]][(int) list[j2]]);
			}
			if (tmp < maxVal)
			{
				res = (int) list[j];
				maxVal = tmp;
			}
		}
		return res;
	}
	
	
	
}
