import java.util.*;

class Pos {
    final int xpos;
    final int ypos;

    Pos(int xpos, int ypos) {
        this.xpos = xpos;
        this.ypos = ypos;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Pos)) return false;
        Pos p = (Pos) o;
        return xpos == p.xpos && ypos == p.ypos;
    }

    @Override
    public int hashCode() {
        return Objects.hash(xpos, ypos);
    }
}

class Solution {
    static final int[] dx = {-1, 1, 0, 0}; // U D L R
    static final int[] dy = {0, 0, -1, 1};

    static int dirToInt(char c) {
        if (c == 'U') return 0;
        if (c == 'D') return 1;
        if (c == 'L') return 2;
        return 3; // 'R'
    }

    static int opposite(int d) {
        // U<->D, L<->R
        if (d == 0) return 1;
        if (d == 1) return 0;
        if (d == 2) return 3;
        return 2;
    }

    static boolean inRange(int x, int y) {
        return -5 <= x && x <= 5 && -5 <= y && y <= 5;
    }

    public int solution(String dirs) {
        HashMap<Pos, HashSet<Integer>> hm = new HashMap<>();

        int cx = 0, cy = 0;

        for (int i = 0; i < dirs.length(); i++) {
            int d = dirToInt(dirs.charAt(i));
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (!inRange(nx, ny)) continue;

            Pos cur = new Pos(cx, cy);
            Pos nxt = new Pos(nx, ny);

            HashSet<Integer> curSet = hm.computeIfAbsent(cur, k -> new HashSet<>());
            HashSet<Integer> nxtSet = hm.computeIfAbsent(nxt, k -> new HashSet<>());

            if (!curSet.contains(d)) {
                curSet.add(d);
                nxtSet.add(opposite(d));
            }

            cx = nx; cy = ny;
        }

        int sum = 0;
        for (HashSet<Integer> s : hm.values()) sum += s.size();

        return sum / 2; 
    }
}
