import java.util.*;import javax.print.attribute.standard.OutputDeviceAssigned;

import java.io.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static String buffer;
	
	static int V, E;
	static List<long[]> adj[];
	static boolean[] visited;


	public static void main(String[] args) throws IOException {
		while (input())
		{
			prim();
		}
	}

	static boolean input() throws IOException 
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		if (V == 0)
			return false;
		E = Integer.parseInt(st.nextToken());
		
		
		// init Container
		visited = new boolean[V+1];
		adj = new ArrayList[V+1];
		
		int from, to;
		long w;
		
		
		for (int i = 1; i <= V; i++)
			adj[i] = new ArrayList<>();
			
	
		
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			w = Long.parseLong(st.nextToken());
			
			adj[from].add(new long[] {w, to});
			adj[to].add(new long[] {w, from});
		}
		br.readLine();
		return true;
	}
	
	static void prim()
	{
		int nodeCount = 0;
		long treeSum = 0;
		
		
		
		PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(a[0], b[0])); // {cost, node}
		pq.add(new long[] {0, 1});
		
		
		while (!pq.isEmpty())
		{
			long weight = pq.peek()[0];
			int node = (int)pq.peek()[1];
			
			pq.poll();
			
			if (visited[node])
				continue;
			
			visited[node] = true;
			nodeCount++;
			treeSum += weight;
			
			for (long[] next : adj[node])
			{
				long nextCost = next[0];
				int nextNode = (int)next[1];
				
				pq.add(new long[] {nextCost, nextNode});				
			}
		}
		
		
		
		System.out.println(treeSum);
		
		
	}
}
