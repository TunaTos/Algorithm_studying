import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.*;
/**
 * mst를 구하는 알고리즘
 * edge는 같은 성별이 되면 안된다 {ww} {mm}
 * 간선의 합은 최소가 되어야한다.
 *
 */


public class Main {
	static int V, E;
	static char[] s;
	static int[] parents, weights;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringBuffer sb;
	
	static class Edge implements Comparable<Edge>	{
		int from;
		int to;
		long weight;
		
		Edge(int from, int to, long weight)
		{
			this.from = from;
			this.to = to;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge other) {
			return Long.compare(this.weight, other.weight);
		}

		@Override
		public String toString() {
			return "Edge [from=" + from + ", to=" + to + ", weight=" + weight + "]";
		}
	}
	
	static List<Edge> edges = new ArrayList<Edge>();
	public static void main(String[] args) throws IOException {
		input();
		Collections.sort(edges);
		
		kruskal();
		
		
	}
	
	static void input() throws IOException
	{
		buffer = br.readLine();
		StringTokenizer st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		s = new char[V+1];
		parents = new int[V+1];
		weights = new int[V+1];
		
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		for (int i = 1; i <= V; i++) {
			parents[i] = i; weights[i] = 1;	
			s[i] = st.nextToken().charAt(0);
		}
		
		int from, to;
		long weight;
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());		
			to = Integer.parseInt(st.nextToken());
			weight = Long.parseLong(st.nextToken());	
			
			if (s[from] != s[to])
				edges.add(new Edge(from, to, weight));
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
		
		if (weights[a] <= weights[b])
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
	
	static void kruskal()
	{
		int edgeCount = 0; 
		long totalCost = 0;
		
		for (Edge e: edges)
		{
			int from = e.from;
			int to = e.to;
			long weight = e.weight;
			
			
			if (Find(from) == Find(to)) // cycle
				continue;

			Union(from, to);
			totalCost += weight;
			edgeCount++;
			
			if (edgeCount == V - 1)
			{
				System.out.println(totalCost);
				System.exit(0);
			}
		}
		
		System.out.println(-1);
		
	}
	
	
	
}
