
import java.io.*;
import java.util.*;

public class Main {
	
	static StringTokenizer st;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static String buffer;
	static StringBuilder sb = new StringBuilder();
	
	
	static boolean[][] rowVisited, colVisited,boxVisited;
	static List<int[]> poses;
	
	static int[] result;
	
	
	public static void main(String[] args) throws IOException {
		input();
		
		dfs(0);
	}
	

	static void dfs(int dpt)
	{
	    if (dpt == poses.size())
	    {
	        for (int i = 1; i <= 81; ++i)
	        {
	            System.out.print(result[i]);
	            if (i % 9 == 0) System.out.println();
	        }
	        System.exit(0);
	    }

	    int xpos = poses.get(dpt)[0];
	    int ypos = poses.get(dpt)[1];

	    for (int i = 1; i <= 9; i++) {
	        if (!rowVisited[xpos][i] && !colVisited[ypos][i] && !boxVisited[getBoxIndex(xpos, ypos)][i])
	        {
	            result[getIndex(xpos, ypos)] = i;
	            rowVisited[xpos][i] = true;
	            colVisited[ypos][i] = true;
	            boxVisited[getBoxIndex(xpos, ypos)][i] = true;

	            dfs(dpt + 1);

	            rowVisited[xpos][i] = false;
	            colVisited[ypos][i] = false;
	            boxVisited[getBoxIndex(xpos, ypos)][i] = false;
	        }
	    }
	}



	static int getIndex(int row, int col)
	{
		return 9 * (row - 1) + col;
	}
	
	static int getBoxIndex(int row, int col)
	{
		if (row >= 1 && row <= 3)
		{
			if (col <= 3)
				return 1;
			if (col <= 6)
				return 2;
			if (col <= 9)
				return 3;
		}
		else if (row >= 4 && row <= 6)
		{
			if (col <= 3)
				return 4;
			if (col <= 6)
				return 5;
			if (col <= 9)
				return 6;
		}
		else if (row >= 7 && row <= 9)
		{
			if (col <= 3)
				return 7;
			if (col <= 6)
				return 8;
			if (col <= 9)
				return 9;
		}
		
		return -1;
	}
	static void input() throws IOException
	{
		rowVisited = new boolean[10][10];
		colVisited = new boolean[10][10];
		boxVisited = new boolean[10][10];
		poses = new ArrayList<>();
		
		result = new int[82];
		
		
		for (int r = 1; r <= 9; r++) {
			buffer = br.readLine();
			for (int c = 0; c < 9; c++) {
				char cNum = buffer.charAt(c);
				
				if (cNum != '0')
				{
					result[getIndex(r, c+1)] = cNum - '0';
					rowVisited[r][cNum - '0']= true;
					colVisited[c+1][cNum - '0'] = true;
					boxVisited[getBoxIndex(r, c+1)][cNum - '0'] = true;
				}

				else
					poses.add(new int[] {r, c+1});
			}
		}
	}
}
