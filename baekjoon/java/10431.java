/**
 * 20명이 키 순서대로 있음
 *
 *
 * 그냥 하면 될 것 같은데?
 * 20명
 *      400 -> 1000 : 브루트 포스
 *
 * 조건)
 *      같은 키를 가진 사람은 없다
 *      정렬이 되어 있으면 정답이 0
 * 로직)
 *      아무나 한 명 뽑아서 줄의 맨 앞에 세운다
 *      다음부터는 학생이 맨 뒤에 선다
 *          앞에 키 큰 사람이 없다면 -> 그냥 자리에 선다
 *          앞에 키 큰 사람이 있다면 -> 가장 앞에 있는 학생 앞에 선다, 그리고 A부터 그 뒤에 모든 학생이 한 발씩 내려간다.
 *
 * 사람들이 몇 번 뒤로 물러갔는가?
 *
 */
package p_10431;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int tCase;
    static ArrayList<Integer> students;


    public static void main(String[] args) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        tCase = Integer.parseInt(st.nextToken());

        for (int i = 1; i<= tCase; ++i) {
            solve();
        }
        System.out.println(sb.toString());
    }

    static int solve() throws Exception {
        int res = 0;
        students = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int tNum = Integer.parseInt(st.nextToken());


        for (int i = 0; i < 20; ++i) {
            int num = Integer.parseInt(st.nextToken());
            if (i == 0)
                students.add(num);
            else if (i != 0) {
                int idx = 0;
                // 자기보다 높은 가장 앞에 있는 수는 검색한다
                for (idx = 0; idx < i; ++idx) {
                    if (num < students.get(idx))
                        break;
                }
                res += (i - idx);
                students.add(idx, num);
            }
        }

        sb.append(tNum  + " " + res + "\n");
        return res;
    }
}
