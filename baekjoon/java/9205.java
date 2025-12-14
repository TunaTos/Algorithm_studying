
import java.io.*;
import java.util.*;

public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;
	
	static class pos
	{
		int xpos;
		int ypos;
		
		public pos(int xpos, int ypos)
		{
			this.xpos = xpos;
			this.ypos = ypos;
		}

		@Override
		public String toString() {
			return "pos [xpos=" + xpos + ", ypos=" + ypos + "]";
		}
		
		
	}
	
	static int Tcase, V;
	static boolean[] visited;
	static pos[] poses;
	static List<Integer>[] adj;

	public static void main(String[] args) throws IOException {
		Tcase = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < Tcase; i++) {
			input();
			init();
			dfs(1);
			if (visited[V])
				System.out.println("happy");
			else
				System.out.println("sad");
		}
	}
	
	static void input() throws IOException
	{
		V = Integer.parseInt(br.readLine());
		
		V = V + 2;
		
		adj = new List[V+1];
		for (int i = 1; i <= V; i++) 
			adj[i] = new ArrayList<>();

		visited = new boolean[V+1];
		poses = new pos[V+1];
		
		for (int i = 1; i <= V; i++) {
			buffer = br.readLine();
			st =  new StringTokenizer(buffer);
			
			int xpos = Integer.parseInt(st.nextToken());
			int ypos = Integer.parseInt(st.nextToken());
			
			poses[i] = new pos(xpos,ypos);
		}
	}
	
	static void init()
	{
		for (int i = 1; i <= V; i++) {
			for (int j = i+1; j <= V; j++) {
				int dis = Math.abs(poses[i].xpos - poses[j].xpos) + 
						Math.abs(poses[i].ypos - poses[j].ypos);
				if (dis <= 1000) {
					adj[i].add(j);
					adj[j].add(i);
				}
			}
		}
	}
	
	static void dfs(int node)
	{
		// 시작점 1에서 도착점 2로 갈 수 있는가?
		
		visited[node] = true;
		
		for (int next: adj[node])
		{
			if (!visited[next])
				dfs(next);
		}
	}

}
