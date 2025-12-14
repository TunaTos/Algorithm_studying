import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	static int V, E;
	static int[] parents, weights;
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	
	
	public static void main(String[] args) throws IOException {
		input();
		int token = 0;
		int node1, node2;
		for (int i = 0; i < E; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			token = Integer.parseInt(st.nextToken());
			node1 = Integer.parseInt(st.nextToken());
			node2 = Integer.parseInt(st.nextToken());
			
			if (token == 0)
				Union(node1, node2);
			else {
				if (Find(node1) == Find(node2))
					System.out.println("YES");
				else
					System.out.println("NO");
			}
		}
	}
	
	static void input() throws IOException{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		parents = new int[V+1];
		weights = new int[V+1];
		
		for (int i = 1; i <= V; ++i)
			parents[i] = i;
		Arrays.fill(weights, 1);
	}
	
	static int Find(int a) {
		if (parents[a] == a)
			return a;
		else
			return parents[a] = Find(parents[a]);
	}
	
	static void Union(int a, int b) {
		a = Find(a); b = Find(b);
		
		if (a == b)
			return;
		
		else if (weights[a] <= weights[b])
		{
			parents[a] = b;
			weights[b] += weights[a];
		}
		else {
			parents[b] = a;
			weights[a] += weights[b];
		}
	}
}
