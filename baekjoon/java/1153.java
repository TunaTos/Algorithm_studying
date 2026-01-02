/**
 * 임의의 자연수가 주어지면
 * 4개의 소수의 합으로 분해하는 프로그램
 * 38 = 5 + 7 + 13 + 13
 *
 * 첫 줄에 자연수 1,000,000
 * int 형 배열 안이다 -> eratos 가능
 *
 * 10 ^ 6
 * N log (N) 아니면 N으로 끝내야하는데
 *
 * 강한 골드바흐 추측
 *      2보다 큰 모든 짝수는 두 개의 소수의 합으로 표현할 수 있다.
 *
 * N = (소수 + 소수 + 소수 + 소수)
 * N이 짝수라면 -> (2[가장 작은 소수] + 2 + 소수 + 소수)
 * N이 홀수라면 -> (2 + 3 + 소수 +소수)
 *
 */
package p_1153;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static boolean[] eratos;

    public static void main(String[] args) throws Exception{
        input();
        if (N < 8)
            System.out.println(-1);

        setEratos();
        if (N % 2 == 0) {
            N -= 4;
            for (int i = 2; i <= N; ++i) {
                for (int j = 2; j <= N; ++j) {
                    if (eratos[i] && eratos[j] && i + j == N) {
                        System.out.println("2 2 " + i + " " + j);
                        return ;
                    }
                }
            }
        } else {
            N -= 5;
            for (int i = 2; i <= N; ++i) {
                for (int j =2; j <= N; ++j) {
                    if (eratos[i] && eratos[j] && i + j == N) {
                        System.out.println("2 3 " + i + " " + j);
                        return ;
                    }
                }
            }
        }
    }


    static void input() throws  Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
    }

    static void setEratos() {
        eratos = new boolean[N+1];
        Arrays.fill(eratos, true);
        eratos[0] = false;
        eratos[1] = false;
        for (int i = 2; i * i <= N; ++i) {
            if (eratos[i]) {
               for (int j = i * 2; j <= N; j += i) {
                    eratos[j] = false;
                }
            }
        }

    }


}
