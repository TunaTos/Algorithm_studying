import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int n = progresses.length;
        ArrayList<Integer> out = new ArrayList<>();

        int curDay = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int remain = 100 - progresses[i];
            int day = (remain + speeds[i] - 1) / speeds[i];

            if (cnt == 0) {
                curDay = day;
                cnt = 1;
            } else if (day <= curDay) {
                cnt++;
            } else {
                out.add(cnt);
                curDay = day;
                cnt = 1;
            }
        }

        out.add(cnt);

        int[] res = new int[out.size()];
        for (int i = 0; i < out.size(); i++) res[i] = out.get(i);
        return res;
    }
}
