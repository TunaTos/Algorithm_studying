/**
 * 팰린드롬이 아닌 가장 긴 부분 문자열의 길이
 * 연속해야한다
 *
 * 길이를 출력하고 아니면 -1
 *
 * 길이는 1이상 50만 이하의 문자열
 * 문자 하나는 팰린드롬이 아니다.
 * 500000
 * O(N)으로 해결해야함
 *
 * 전체(S)가 팰린드롬이 아니라면? -> 정답은 S
 *
 * 만약 전체가 팰린드롬이라면?
 *      -> 거기서 문자를 하나 뺀다면??
 *          abba -> bba abb [팰린드롬이 아님]
 *          zzz -> zz zz [팰린드롬이 맞음]
 *
 *          즉 모두가 같은 숫자로 이루어진 팰린드롬이면 -> -1
 *          다른 숫자로 이루어진 팰린드롬에서 하나를 빼면 팰린드롬이 아닌가?
 *                  홀수 case
 *                      abtba [btba] [abtb]
 *                      aataa [ataa] [aata]
 *                      ababa [baba] [abab] no
 *                  짝수 case
 *                      abba [bba] [abb]
 *
 *  결론
 *      전체 문자열이 팰린드롬인지 확인한다
 *          팰린드롬이 아니다? -> 문자열의 길이 출력
 *          팰린드롬이 맞다?
 *              하나의 문자로 되어 있다? -> -1
 *              하나의 문자로 되어 있지 않다? -> 문자열의 길이 -1
 */
package p_15927;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String origin;
    static boolean[] tmp = new boolean[30];
    static int charNum = 0;

    public static void main(String[] args) throws Exception {
        origin = br.readLine();
        for (int i = 0; i < origin.length(); ++i) {
            tmp[charToInt(origin.charAt(i))] = true;
        }

        for (int i = 0; i < 30; ++i) {
            if (tmp[i])
                charNum++;
        }

        boolean flag = isPelindrom(origin);

        if (!flag)
            System.out.println(origin.length());
        else {
            // 한 글자로 이루어져 있는 경우
            if (charNum == 1) {
                System.out.println(-1);
            }
            else {
                System.out.println(origin.length() - 1);
            }
        }

    }
    static int charToInt(char c) {
        return (int) c - 'A';
    }
    static boolean isPelindrom(String str) {
        for (int i = 0; i < str.length() / 2; ++i) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i))
                return false;
        }
        return true;

    }
}
