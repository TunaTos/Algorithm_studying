import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] numbers;
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        numbers = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        dp = new long[N][21]; // dp[i][j] : i번째 숫자로 j를 만들 수 있는 경우
        dp[0][numbers[0]] = 1; // 첫 번째 숫자는 그대로 사용

        for (int i = 1; i < N - 1; i++) 
        { 
            for (int j = 0; j <= 20; j++) 
            {
                if (dp[i - 1][j] > 0) 
                {
                    if (j + numbers[i] <= 20) dp[i][j + numbers[i]] += dp[i - 1][j];
                    if (j - numbers[i] >= 0) dp[i][j - numbers[i]] += dp[i - 1][j];
                }
            }
        }

        System.out.println(dp[N - 2][numbers[N - 1]]); 
    }
}
