import java.util.*;
import java.io.*;


public class Main {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringTokenizer st;
	
	static int V, E, S;
	static long[] dis;
	static List<long[]>[] adj; // {weight, node};
	
	
	
	public static void main(String[] args) throws IOException {
		input();
		Dijkstra();
		for (int i = 1; i <= V; i++) {
			if (dis[i] == 987654321)
				System.out.println("INF");
			else
				System.out.println(dis[i]);
		}
}
	
	static void input() throws IOException 
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(br.readLine());
		
		// init Container
		adj = new ArrayList[V+1];
		for (int i = 1; i <= V; i++) {
			adj[i] = new ArrayList<>();
		}
		
		dis = new long[V+1];
		Arrays.fill(dis, 987654321);
		

		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			long w = Integer.parseInt(st.nextToken());
			
			adj[from].add(new long[] {w, to});
		}
	}
	
	static void Dijkstra()
	{
		PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) ->   {
			return Long.compare(a[1], b[1]);
		}) ; // {node , weight}
		
		pq.add(new long[] {S, 0});
		dis[S] = 0;
		
		
		while (!pq.isEmpty())
		{
			long[] tmp = pq.poll();
			int startNode = (int)tmp[0];
			long weight = tmp[1];
			
			if (weight > dis[startNode])
				continue;
			
			
			for (long[] next: adj[(int)startNode])
			{
				long cost = next[0];
				int nextNode = (int)next[1];
				
				if (dis[nextNode] > cost + dis[startNode])
				{
					dis[nextNode] = cost + dis[startNode];
					pq.add(new long[] {nextNode, dis[nextNode]});
				}
			}
		}
	}
}
