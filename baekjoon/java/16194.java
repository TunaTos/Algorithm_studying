/**
 * Memory : 19844 kb
 * Time : 128 ms
 *
 * 8개의 카드가 있음
 *
 * "카드팩"으로 구매 가능
 * 카드팩은 -> 1개, 2개, 3개, ... N개가 있는 것으롲 ㅗㄴ재
 *
 *
 * 돈을 최소로 지불해서 N개를 구매하려고 한다
 *
 * 카드가 i개가 포함된 카드팩의 가격은 p(i)
 *
 * N개의 카드를 구매하기 위해 지불해야하는 금액의 최소값
 * (N개의 카드보다 더 많은 것은 안된다)
 *
 * - 한 카드팩을 여러번 살 수 있음
 * - N개의 카드보다 더 많이 사면 안된다 딱 맞게 사야함
 *
 * P(4)
 *      P(3) + P(1)
 *      P(2) + P(2)
 *
 */
package p_16194;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static long[][] matrix;
    static long[] numbers;


    public static void main(String[] args) throws IOException  {
        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        numbers = new long[N+1];
        matrix = new long[N+1][N+1];

        // init container
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; ++i)
            numbers[i] = Long.parseLong(st.nextToken());

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                matrix[i][j] = Long.MAX_VALUE;

        for (int i = 1; i <= N; ++i) {
            long cost = numbers[i];
            int quantity = i;

            for (int j = 1; j <= N; ++j) {
                if (i == 1) {
                    matrix[i][j] = cost * j;
                } else {
                    if (j < quantity) {
                        matrix[i][j] = Long.min(matrix[i][j], matrix[i - 1][j]);
                    } else {
                        long va1 = matrix[i-1][j];
                        long va2 = matrix[i - 1][j - quantity] + cost;
                        long va3 = matrix[i][j - quantity] + cost;

                        va1 = Long.min(va1, va2);
                        va1 = Long.min(va1, va3);

                        matrix[i][j] = Long.min(matrix[i][j], va1);
                    }
                }
            }
        }

        long res = Long.MAX_VALUE;
        for (int i = 1; i <= N; ++i)
            res = Long.min(res, matrix[i][N]);
        System.out.println(res);
    }
}
