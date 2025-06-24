import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.concurrent.PriorityBlockingQueue;

public class Main {
	static int V, E;
	static StringTokenizer st;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static class Edge implements Comparable<Edge>{
		int from;
		int weight;
		
		Edge(int from, int weight) {
			this.from = from;
			this.weight = weight;
		}

		@Override
		public int compareTo(Main.Edge o) {
			return Integer.compare(this.weight, o.weight);

		}		
	}
	static List<Edge>[] adj;
	static String buffer;
	public static void main(String[] args) throws IOException{
		input();
		
		int[] result = new int[V+1];
		int resultIdx = 0;
		int tmp = Integer.MAX_VALUE;
		
		for (int i = 1; i <= V; ++i)
		{
			result[i] = Dijkstra(i);
			if (tmp > result[i])
			{
				tmp = result[i];
				resultIdx = i;
			}
		}
		System.out.println(resultIdx);
	}
	
	static void input() throws IOException{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		adj = new List[V+1];
		
		for (int i = 0; i <= V; ++i)
			adj[i] = new ArrayList<Edge>();
		
		int from, to, weight;
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			weight = 1;
			
			adj[from].add(new Edge(to, weight)); // edge weight
			adj[to].add(new Edge(from, weight));
			
		}
	}
	static int Dijkstra(int start) // 시작점을 기준으로 다익스트라를 실행한다
	{
		int[] distance = new int[V+1];
		Arrays.fill(distance, Integer.MAX_VALUE);
		
		PriorityQueue<Edge> pq = new PriorityQueue<>(); // node weight
		distance[start] = 0; // 시작점 초기화
		pq.add(new Edge(start, 0));
	
		
		while (!pq.isEmpty())
		{
			Edge edge = pq.poll();
			int node = edge.from;
			int weight = edge.weight;
			
			for (Edge nextEdge: adj[node])
			{
				int nextNode = nextEdge.from;
				int cost = nextEdge.weight;
				
				
				if (distance[nextNode] > distance[node] + cost)
				{
					distance[nextNode] = distance[node] + cost;
					pq.add(new Edge(nextNode, distance[nextNode]));
				}
			}
		}
		
		int res = 0;
		for (int i = 1; i <= V; ++i)
		{
			if (distance[i] == 0 || distance[i] == Integer.MAX_VALUE)
				continue;
			res += distance[i];
		}
		return res;
	}
}
