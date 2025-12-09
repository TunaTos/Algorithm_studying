import java.util.*;
import java.io.*;

public class Main {
	static int V,E, node1, node2;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static String buffer;
	static List<int[]>[] adj; // weight to
	static int INF = Integer.MAX_VALUE;
	
	
	public static void main(String[] args) throws IOException {
		/**
		 * 최단거리의 특성 특정 노드에서 노드까지의 최단거리 상의 node간의 거리는 최단거리다
		 * 최단거리 1에서 V까지의 거리로 가는 길이 있는데
		 * node1과 node2까지를 거쳐가는 최단거리가 있는가?
		 * 1 -> node1 -> node2 -> V
		 * 1 -> node2 -> node1 -> V
		 * 위의 경로 상에서 INF가 나오면 안됨
		 */
		input();
		int dis1 = dijkstra(1, node1);
		int dis2 = dijkstra(node1, node2);
		int dis3 = dijkstra(node2, V);
		
		int dis4 = dijkstra(1, node2);
		int dis5 = dijkstra(node1, V);
		
	
		int res1 = 0;
		int res2 = 0;
		
		if (dis1 == INF || dis2 == INF || dis3 == INF)
			res1 = INF;
		else
			res1 = dis1 + dis2 + dis3;
		if (dis4 == INF || dis2 == INF || dis5 == INF)
			res2 = INF;
		else
			res2 = dis4 + dis2 + dis5;
		
		
		//System.out.println(res1 + " " + res2);
		if (res1 == INF || res2 == INF)
			System.out.println(-1);
		else
			System.out.println(Integer.min(res1,res2));
	}
	
	static void input() throws IOException
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		adj = new ArrayList[V+1];
		
		for (int i = 0; i <= V; ++i)
			adj[i] = new ArrayList<int[]>();
			
		int from, to, weight;
		
		for (int i  =0; i < E; ++i) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			weight = Integer.parseInt(st.nextToken());
			
			adj[from].add(new int[] {weight, to});
			adj[to].add(new int[] {weight, from});
		}
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		node1 = Integer.parseInt(st.nextToken());
		node2 = Integer.parseInt(st.nextToken());
	}
	
	static int dijkstra(int start, int end) {
		int[] distance = new int[V+1];
		Arrays.fill(distance, Integer.MAX_VALUE);
		distance[start] = 0;
		
		Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
		pq.add(new int[] {0,start});
		
		while (!pq.isEmpty()) {
			int[] tmp = pq.poll();
			
			int weight = tmp[0];
			int node = tmp[1];
			
			if (distance[node] < weight)
				continue;
			
			for (int[] next: adj[node]) {
				int cost = next[0];
				int nextNode = next[1];
				
				if (distance[nextNode] > distance[node] + cost)
				{
					distance[nextNode] = distance[node] + cost;
					pq.add(new int[] {distance[nextNode], nextNode});
				}
			}
		}
		
	
		
		return distance[end];
	}
	
}
