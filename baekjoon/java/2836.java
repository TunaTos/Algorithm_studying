/*
* M 강의 길이 (0에서 시작)
* N 사람의 수
*
* (2,8,6,4)
* x1, y1 (겹칠 수 있음)
* x2, y2
*
* 규칙
* x(k)가 나온 이후에 y(k)가 나와야한다
* 언제가 그러면 최소인가?
*   역방향으로 가는 경로가 있는 경우
*   역방향으로 가는 경로들을 모두 나열한 뒤 경로를 합친다
*       ex) [3,1] [4,2] -> [4,1]
*   역방향으로 가는 경로가 있으면 그 구간(k)의 2배가 들어간다
*   따라서 정답 : M + (모든 역방향 경로 집합 r[k]) * 2
*
* (3,1), (4,2), (12,11),(14,11), (14,13)
*
* (4,1) (14,11)
* 3 * 2 + 3 * 2 = 12 + 15 = 27 (ok)
*
* Q) 역방향 경로 집합을 어떻게 합칠 것인가?
* 역방향 경로를 모두 select한다
* x좌표, y좌표로 내림차순한다
* 포함되면 -> 그대로
* 포함되지 않으면 -> 기준 변경
* 부분적으로 포함되면 -> 부분 수정
*
*
* */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static class Edge {
        long x;
        long y;

        Edge(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static long M;
    static ArrayList<Edge> revEdges = new ArrayList<>();
    static long revSections = 0;

    public static void main(String[] args) throws Exception {
        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Long.parseLong(st.nextToken());

        long from, to;
        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine());
            from = Long.parseLong(st.nextToken());
            to = Long.parseLong(st.nextToken());

            if (from <= to) continue;

            revEdges.add(new Edge(from,to));
        }

        // solve

        if (revEdges.isEmpty()) {
            System.out.println(M);
            return ;
        }


        Collections.sort(revEdges, (a,b) -> {
            if (a.x != b.x) {
                return Long.compare(b.x, a.x);
            } else {
                return Long.compare(b.y, a.y);
            }
        });

        long n1 = revEdges.get(0).x;
        long n2 = revEdges.get(0).y;

        for (Edge e: revEdges) {
            long nextN1 = e.x;
            long nextN2 = e.y;


            if (nextN1 < n2) {
                revSections += (n1 - n2);
                n1 = nextN1;
                n2 = nextN2;
            } else if (n1 >= nextN1 && nextN2 >= n2) {
                continue;
            } else {
                n2 = nextN2;
            }
        }

        revSections += (n1 - n2);

        System.out.println(M + revSections * 2);

    }
}
