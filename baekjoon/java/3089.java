/*
* 클로버는 N개의 점으로 나타나 있다
*
* 처음 위치 -> (0,0)
* 명령 M
* 명령은 네 방향 중 하나이며, 방향에서 가장 가까운 네잎 클로버로 간다
*
* 항상 주어지는 방향에는 네잎 클로버가 존재함이 보장된다.
*
* 풀이)
* - 방향에 존재하는 네잎 클로버를 어떻게 찾을 것인가?
* - 왼쪽, 오른쪽 -> 현재 내가 있는 xpos에서 가장 작은 것
* */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Pos {
        int xpos;
        int ypos;

        Pos (int xpos, int ypos) {
            this.xpos = xpos;
            this.ypos = ypos;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Pos curPos = new Pos(0,0);
    static int N, M; // 네잎 클로버, 명령의 수
    static String orders;
    static Map<Integer, TreeSet<Integer>> xMap = new HashMap<>(), yMap = new HashMap<>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }

    static void input() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int xpos, ypos;
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());

            xpos = Integer.parseInt(st.nextToken());
            ypos = Integer.parseInt(st.nextToken());

            xMap.putIfAbsent(xpos, new TreeSet<>());
            xMap.get(xpos).add(ypos);

            yMap.putIfAbsent(ypos, new TreeSet<>());
            yMap.get(ypos).add(xpos);
        }

        orders = br.readLine();
    }

    static void solve() {
        for (int i = 0; i < M; ++i) {
            char c = orders.charAt(i);
            traverse(c);
        }

        System.out.println(curPos.xpos + " " + curPos.ypos);
    }

    static void traverse(char dir) {
        TreeSet<Integer> ts;
        int nextXpos = curPos.xpos;
        int nextYpos = curPos.ypos;

        if (dir == 'L') {
            ts = yMap.get(curPos.ypos);
            nextXpos = ts.lower(curPos.xpos);

        } else if (dir == 'R')  {
            ts = yMap.get(curPos.ypos);
            nextXpos = ts.higher(curPos.xpos);
        }
        else if (dir == 'U') {
            ts = xMap.get(curPos.xpos);
            nextYpos = ts.higher(curPos.ypos);
        } else if (dir == 'D') {
            ts = xMap.get(curPos.xpos);
            nextYpos = ts.lower(curPos.ypos);
        }

        curPos.xpos = nextXpos;
        curPos.ypos = nextYpos;

    }
}
