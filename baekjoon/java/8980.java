/**
 * 각 마을은 배송할 물건들을 박스에 넣는다
 *
 * 보내는 마을 번호, 받는 마을번호, 보낼 박스의 개수
 *
 * 크기는 같음, 트럭의 용량이 있음
 * 최대한 많은 박스를 배송하려 한다
 *
 * 조건1) 트럭 실으면, 받는 마을에서만 내린다
 * 조건2) 지나온 마을 되돌아가지 않는다
 * 조건3) 일부만 배송 가능하다
 *
 * 마을의 개수, 트럭의 용량, 박스 정보 -> 최대 박스의 수는?
 *
 */



import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, C, M;
 …