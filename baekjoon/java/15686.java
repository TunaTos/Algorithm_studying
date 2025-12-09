import java.util.*;
import java.io.*;


/**
 * @author SJ
 * 
 * 치킨거리 : 집과 가장 가까운 치킨집 사이의 거리
 * 
 * 치킨집을 M개로 줄인다 -> 그 후에 계산을 진행함
 * 
 */


public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String buffer;
	
	static int Len, M, hLen, cLen, Result = Integer.MAX_VALUE;
	static List<int[]> houses, chickens, selected;
	
	public static void main(String[] args) throws IOException {
		input();
		
		Combination(0);
		System.out.println(Result);
		
	}

	static void input() throws IOException 
	{
		buffer = br.readLine();
		st = new StringTokenizer(buffer);

		
		Len = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		houses = new ArrayList<>();
		chickens = new ArrayList<>();
		selected = new ArrayList<>();
		
		
		
		for (int i = 1; i <= Len; i++) {
			buffer = br.readLine();
			st = new StringTokenizer(buffer);
			
			for (int j = 1; j <= Len; j++) {
				int n = Integer.parseInt(st.nextToken());
				
				if (n == 1)
					houses.add(new int[] {i,j});
				if (n == 2)
					chickens.add(new int[] {i,j});
			}

		}
	}
	
	static void Combination(int idx)
	{
		if (selected.size() == M)
		{
			int res = 0;
			for (int[] house: houses)
			{
				res += getMinDistance(house);
			}
			
			Result = Integer.min(Result, res);
			
			
			return ;
		}
		

		for (int i = idx; i < chickens.size(); i++) {
			selected.add(chickens.get(i));
			
			Combination(i + 1);
			
			selected.remove(selected.size() - 1);
		}
	
		
		
		
	}
	
	static int getMinDistance(int[] house)
	{
		// 특정 치킨집의 치킨거리를 return한다.
		int res = Integer.MAX_VALUE;
		
		for (int[] chicken: selected)
			res = Integer.min(res, (Math.abs(house[0] - chicken[0]) + Math.abs(house[1] - chicken[1])));
		
		return res;
	}
}
