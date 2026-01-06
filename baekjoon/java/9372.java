/**
 * Tcase
 * 줄에 a랑 b랑 입력된다.
 *
 * a랑 b를 왕복하는 비행기가 존재한다.
 *
 * 1 -> 2 -> 3
 *      4 ->
 *      4->5
 *
 * Fuck
 */
package p_9372;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int Tcase, V, E;
    static int[][] edges;

    public static void main(String[] args) throws Exception {
        Tcase = Integer.parseInt(br.readLine());

        for (int i = 0; i < Tcase; ++i) {
            input();
            System.out.println(V-1);
        }
    }

    static void input() throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        edges = new int[E][2];

        for (int i = 0; i < E; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            edges[i][0] = x;
            edges[i][1] = y;
        }
    }
}
