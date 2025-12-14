import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

/*
 * 위상정렬 문제
 * 위상정렬을 푸는 방법은 
 * 	--> DFS를 역행하는 방법
 * 	--> Kahn's Algorithm이 있다
 * 
 * 사용 알고리즘 Kahn's Algorithm
 * 
 */


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder();
	static String buffer = new String();
	static StringTokenizer st;
	static int[] indegree;
	static int V, E;
	static List<Integer> adj[];
	
	public static void main(String[] args) throws IOException {
		input();
		Topological();

	}
	
	
	static void input () throws IOException{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		adj = new ArrayList[V+1];
		
		indegree = new int[V+1];
		for (int i = 0; i <= V; ++i)
		{
			indegree[i] = 0;
			adj[i] = new ArrayList<Integer>();
		}

		int from, to;
		
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			
			adj[from].add(to);
			indegree[to]++;
		}
	}
	
	static void Topological() throws IOException
	{
		int cnt = 1;
		int[] result = new int[V+1];
		Queue<Integer> q = new LinkedList<>();
		
		
		for (int i = 1; i <= V; i++) // indegree가 0인 것을 모두 담아둔다
			if (indegree[i] == 0)
				q.add(i);
		
		
		while (!q.isEmpty())
		{
			int qSize = q.size(); // 한 단계에 있는 모든 노드는 같은 cnt 값을 가져야한다.
			
			for (int i = 0; i < qSize; i++) 
			{
				int node = q.poll();
				result[node] = cnt;
				
				for (int next: adj[node])
				{
					indegree[next]--; // edge를 지워준다 
					if (indegree[next] == 0) // indegree가 0이면 넣는다.
						q.add(next);
				}				
			}
			++cnt;
		}
		
		for (int i = 1; i <= V; i++) 
			sb.append(result[i] + " ");
		
		bw.write(sb.toString());
		bw.flush();
	}
}
