import java.util.*;
import java.util.stream.IntStream;
import java.io.*;


public class Main {
	
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String buffer;
	static StringTokenizer st;

	
	static int V, E;
	static List<long[]> edges; // {from, to, w}
	static int[] parents;
	
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
		
		parents[a] = b;
	}
	
	
	public static void main(String[] args) throws IOException {
		
		V = Integer.parseInt(br.readLine());
		E = Integer.parseInt(br.readLine());
		
		// init Container
		parents = IntStream.rangeClosed(0, V).toArray();
		edges = new ArrayList<>();
		
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			long from = Long.parseLong(st.nextToken());
			long to = Long.parseLong(st.nextToken());
			long w = Long.parseLong(st.nextToken());
			
			edges.add(new long[] {from, to, w});
		}
		
		
		// Kruskal
		int edgeCount = 0;
		long treeSum = 0;
		
		Collections.sort(edges, Comparator.comparingLong(a -> a[2]));
		
	
		for (long[] edge: edges)
		{
			int from = (int)edge[0];
			int to = (int)edge[1];
			long w = edge[2];
			
			if (Find(from) == Find(to))
				continue;
			
			Union(from, to);
			edgeCount++;
			treeSum += w;
			
			
			if (edgeCount == V-1)
				break;
			
		}
		
		System.out.println(treeSum);
	}



}
