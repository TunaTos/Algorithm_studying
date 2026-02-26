/**
 * 한 번에 M명의 사람을 태울 ㅅ 있음
 * t만큼의 시간이 걸린다
 * 처음 배는 왼쪽이다
 *
 * 정류장으로 가려고 하는 사람 모두 내린다
 * 그 다음에 손님들을 가장 오래 기다린 사람 순으로다 태운다
 * 기다리는 손님이 없으면 다음 손님을 기다린다
 * 기다리다가 반대 쪽 정박장에 손님이 도착하면 정박장으로 간다
 *
 * 각 손님이 원하는 곳이 도착하는 시간
 *
 * 태울 수 있는 사람 판단을 어떻게 하느냐?
 *      left랑 right랑 우선순위큐로 해서
 *      현재 시간 >= t -> 탄다
 * 태울 수 있는 사람이 없다
 *      다음에 오는 사람이 내쪽에 있는지, 반대편인지 판단을 한다.
 *
 *      만약 반대편에 사람이 없어서 기다려야한다? (현재 내 시간 < 반대 pq.top)
 *          반대편에 간 뒤에 -> 현재 내 시간 =  pq.top + t [사람이 있는 걸 보고 가니까]
 *      만약 반대편에 사람이 있다면? (현재 내 시간 >= 반대 pq.top())
 *          반대편에 간 뒤에 -> 현재 내 시간 + t
 * 도착시간은? -> 배가 반대편에 간 시간
 *
 */
package p_2065;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int LEFT = 0;
    static final int RIGHT = 1;

    static class Node {
        int id;
        long time;
        int dir; // {left 0, right 1}

        Node(int id, long time, String dir) {
            this.id = id;
            this.time = time;
            if (dir.equals("left")) {
                this.dir = LEFT;
            } else {
                this.dir = RIGHT;
            }
        }
    }

    static class Arrived {
        int id;
        long arrived;

        Arrived(int id, long arrived) {
            this.id = id;
            this.arrived = arrived;
        }
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int M, N; // 최대 태울 수 있는 사람, 걸리는 시간, tacse
    static long T, curTime = 0;
    static PriorityQueue<Node> left = new PriorityQueue<>((a,b) -> {
        if (a.time != b.time) {
            return Long.compare(a.time, b.time);
        } else {
            return Integer.compare(a.id, b.id);
        }
    });
    static PriorityQueue<Node> right = new PriorityQueue<>((a,b) -> {
        if (a.time != b.time) {
            return Long.compare(a.time, b.time);
        } else {
            return Integer.compare(a.id, b.id);
        }
    });
    static Deque<Node> boat = new ArrayDeque<>();
    static int curDir = LEFT;
    static ArrayList<Arrived> arrived = new ArrayList<>();


    public static void main(String[] args) throws Exception{
        input();
        solve();
        Collections.sort(arrived, (a,b) -> {
            return Integer.compare(a.id, b.id);
        });
        for (Arrived arr: arrived) {
            System.out.println(arr.arrived);
        }
    }

    static void solve() {
        while (true) {
            if (boat.isEmpty() && left.isEmpty() && right.isEmpty()) break;

            // 도착한 사람 내리기
            while (!boat.isEmpty()) {
                arrived.add(new Arrived(boat.peekFirst().id, curTime));
                boat.pollFirst();
            }

            PriorityQueue<Node> curSide = (curDir == LEFT) ? left : right;
            PriorityQueue<Node> otherSide = (curDir == LEFT) ? right : left;
            int nextDir = (curDir == LEFT) ? RIGHT : LEFT;

            // 현재 쪽에 탈 수 있는 사람이 있음
            if (!curSide.isEmpty() && curSide.peek().time <= curTime) {
                while (!curSide.isEmpty() && curSide.peek().time <= curTime && boat.size() < M) {
                    boat.addLast(curSide.poll());
                }
                curDir = nextDir;
                curTime += T;
            }



            // 현재 쪽에 탈 사람 없음
            else {
                long nextCur = curSide.isEmpty() ? Long.MAX_VALUE : curSide.peek().time;
                long nextOther = otherSide.isEmpty() ? Long.MAX_VALUE : otherSide.peek().time;



                if (nextOther == Long.MAX_VALUE && nextCur == Long.MAX_VALUE) {
                    // 둘 다 없음
                    break;
                }

                if (nextOther < nextCur) {
                    // 반대편이 더 빨리 옴 → 반대편으로 이동
                    curTime = Math.max(curTime, nextOther) + T;
                    curDir = nextDir;
                } else {
                    // 현재 쪽이 더 빠르거나 같음 → 현재 쪽에서 기다림
                    curTime = nextCur;
                }
            }
        }
    }

    static void input() throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        T = Long.parseLong(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        long time;
        String dir;
        for (int i = 1; i <= N; ++i) {
            st = new StringTokenizer(br.readLine());
            time = Long.parseLong(st.nextToken());
            dir = st.nextToken();

            Node node = new Node(i,time,dir);
            if (node.dir == LEFT) {
                left.add(node);
            } else {
                right.add(node);
            }
        }
    }
}
