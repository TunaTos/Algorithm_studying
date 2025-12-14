import java.util.*;

public class Main {
    static int N;
    static int[] selected;
    static int[] numbers = {1, 2, 3};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        selected = new int[N];
        dfs(0);
    }

    static boolean prunning(int dpt) 
    {
    	
    	for (int len = 1; len <= dpt / 2; len++) 
    	{
    		// dpt는 len의 절반이다
            boolean isBad = true;
            for (int i = 0; i < len; i++) 
            {
            	// dpt - len + i -> 오른쪽, dpt - 2 * len + i -> 왼쪽
                if (selected[dpt - len + i] != selected[dpt - 2 * len + i]) {
                    isBad = false;
                    break;
                }
            }
            if (isBad) 
            	return false;
        }
        return true;
    }

    static void dfs(int dpt) 
    {
        if (dpt == N) {
            for (int i = 0; i < N; i++) 
            {
                System.out.print(selected[i]);
            }
            System.out.println();
            System.exit(0); // 가장 작은 좋은 수열을 찾으면 즉시 종료
        }

        for (int i = 0; i < 3; i++) // 중복순열을 구현하는데
        {
            selected[dpt] = numbers[i];
            if (prunning(dpt + 1)) // 선택된 것이 좋은 순열인가?
            {
                dfs(dpt + 1);
            }
        }
    }
}

