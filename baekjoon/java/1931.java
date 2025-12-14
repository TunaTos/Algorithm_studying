import java.util.*;
import java.io.*;

public class Main {
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	
	static class Edge implements Comparable<Edge>
	{
		int start;
		int end;
		
		Edge(int start, int end)
		{
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Edge o) {
			if (this.end == o.end)
				return Integer.compare(this.start, o.start);
			
			return Integer.compare(this.end, o.end);
		}

		@Override
		public String toString() {
			return "Edge [start=" + start + ", end=" + end + "]";
		}	
	}
	
	static Edge[] edges;
	static int Len;
	public static void main(String[] args) throws IOException {
		Len = Integer.parseInt(br.readLine());
		edges = new Edge[Len];
		

		for (int i = 0; i < Len; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			
			edges[i] = new Edge(start,end);
		}
		
		Arrays.sort(edges);
				
		int stand = edges[0].end;
		int res = 1;
		
		

		for (int i = 1; i < Len; i++) {
			if (edges[i].start < stand)
				continue;
			if (edges[i].start >= stand)
			{
				++res;
				stand = edges[i].end;
			}
		}
		System.out.println(res);

	}

}
