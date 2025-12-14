import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {
	
	static StringTokenizer st;
	static BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int start, end;
	static boolean[] visited;
	static class Node implements Comparable<Node> 
	{
		int distance;
		int pos;
		
		public Node(int distance, int pos) {
			super();
			this.distance = distance;
			this.pos = pos;
		}

		@Override
		public int compareTo(Node other) {
			if (Integer.compare(this.distance, other.distance) == 0)
				return Integer.compare(this.pos, other.pos);
			return Integer.compare(this.distance, other.distance);
		}
	}
	
	public static void main(String[] args) throws IOException {
		input();
		dijkstra();
	}
	
	static void input() throws IOException
	{
		String buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		visited = new boolean[100000+1];
		Arrays.fill(visited, false);
	}
	
	static boolean inTheMatrix(int node) {
		return node >= 0 && node <= 100000;
	}
	
	
	
	static void dijkstra() {
		PriorityQueue<Node> pq = new PriorityQueue<>(); // distance pos
		pq.offer(new Node(0, start));
		visited[start] = true;
		
		if (inTheMatrix(start * 2) && !visited[start*2])
		{
			pq.offer(new Node(0, start * 2));
			visited[start * 2] = true;
		}
		
		
		while (!pq.isEmpty())
		{
			Node node = pq.poll();
			int pos = node.pos;
			int distance = node.distance;
			//System.out.println(pos + " " + distance + "\n");
			if (pos == end)
			{
				System.out.println(distance);
				System.exit(0);
			}
	
			// 2배 건너뛰는 거
			if (inTheMatrix(pos * 2) && !visited[pos * 2])
			{
				pq.offer(new Node(distance, pos * 2));
				visited[pos * 2] = true;
			}
			// 1칸 뒤로 가는 것
			if (inTheMatrix(pos-1) && !visited[pos-1])
			{
				pq.offer(new Node(distance+1, pos-1));
				visited[pos-1] = true;
			}
			// 1칸 앞으로 가는 거
			if (inTheMatrix(pos + 1) && !visited[pos + 1])
			{
				pq.offer(new Node(distance+1, pos+1));
				visited[pos+1] = true;
			}
			
		}	
	}
}