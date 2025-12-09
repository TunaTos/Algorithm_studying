import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * 계란은 내구도와 무게가 정해져있다.
 * 
 * 계란으로 계란을 치게 되면 
 * 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다
 * 내구도 = 내구도 - 상대방의 무게
 * 내구도가 <= 0이 되는 순간 계란은 깨진다.
 * 
 * 1) 가장 왼쪽의 계란을 든다
 * 2) 깨지지 않은 다른 계란 중에 하나를 친다
 * 		-> 손에 든계란이 깨졌거나
 * 		-> 다른 계란이 다 깨졌다면 넘어간다
 * 3) 그 다음 오른쪽으로 넘어간다.
 *
 * 최대 몇 개 깰 수 있는지를 알아봐라!
 */




public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static String buffer;
    
    static int N, res;
    static int[] weights, durable;
    
    
	public static void main(String[] args) throws IOException {
		
		input();
		res = 0;

		dfs(0, 0);
		
		System.out.println(res);
	}
	
	static void dfs(int grab, int breakCount) // 내가 잡고있는 계란의 idx
	{
		if (grab >= N)
		{
			res = Integer.max(res, breakCount);
			return ;
		}
		
		
		boolean isHit = false;
		for (int target = 0; target < N; target++) {
			if (durable[grab] <= 0)
				continue;
			if (target == grab) // 내가 잡고있는 것을 깰 수는 없음
				continue;
			if (durable[target] <= 0) // 이미 깨진 것은 꺨 수 없음
				continue;
			
			isHit = true;
			durable[grab] -= weights[target]; // 내가 가지고 있는 계란을 내린다
			durable[target] -= weights[grab]; // 상대방 계란을 깬다.
			
			int newBreakCount = breakCount;
			if (durable[grab] <= 0)
				newBreakCount ++;
			if (durable[target] <= 0)
				newBreakCount ++;
			
			dfs(grab+1, newBreakCount );
			
			durable[grab] += weights[target]; // 원상복구
			durable[target] += weights[grab]; // 원상복구
			

		}
		if (!isHit)
			dfs(grab+1, breakCount);
		
		
	}
	static void input() throws IOException {
		N = Integer.parseInt(br.readLine());
		
		weights = new int[N];
		durable = new int[N];
		
		
		
		for (int i = 0; i < N; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			durable[i] = Integer.parseInt(st.nextToken());
			weights[i] = Integer.parseInt(st.nextToken());
		}
	}

}
