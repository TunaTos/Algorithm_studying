// 친구이거나, 친구의 친구인 경우? 
// bfs를 돌려서 dpt가 1이거나, dpt가 2인 경우를 출력하면 될 것 같음


import java.io.*;
import java.util.*;



public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static int V, E;
	static ArrayList<Integer>[] adj;
	static int[] dptList;
	static boolean[] visited;
	
	public static void main(String[] args)throws IOException {
		input();
		bfs();
		int res = 0;
		
		for (int i =1; i <= V; ++i)
			if (dptList[i] == 1 || dptList[i] == 2)
				++res;
		
		System.out.println(res);
	}
	
	static void input() throws IOException {
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		
		// init Container
		adj = new ArrayList[V+1];
		for (int i = 0; i <= V; i++)
			adj[i] = new ArrayList<Integer>();
			
		
		int v1, v2;
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
		
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			
			
			adj[v1].add(v2);
			adj[v2].add(v1);
		}
		
		dptList = new int[V+1];
		visited = new boolean[V+1];
		
	}
	
	static void bfs()
	{
		Queue<int[]> q = new LinkedList<>(); // node, dpt
		
		q.add(new int[] {1,0});
		visited[1] = true;
		
		while (!q.isEmpty())
		{
			int qSize = q.size();
			
			
			for (int i = 0; i < qSize; i++) 
			{
				int[] tmp = q.poll();
				int node = tmp[0];
				int dpt = tmp[1];
				
				dptList[node] = dpt;
				
				
				for (int next: adj[node])
				{
					if (!visited[next])
					{
						visited[next] = true;
						q.add(new int[] {next, dpt+1});
					}
				}
			}
		}
		
	
	}
}
