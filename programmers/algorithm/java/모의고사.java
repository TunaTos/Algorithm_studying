import java.util.*;

class Solution {
    static final int[] first  = {1, 2, 3, 4, 5};
    static final int[] second = {2, 1, 2, 3, 2, 4, 2, 5};
    static final int[] third  = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    public int[] solution(int[] answers) {
        int fRes = 0, sRes = 0, tRes = 0;
        int fIdx = 0, sIdx = 0, tIdx = 0;

        for (int i = 0; i < answers.length; i++) {
            int ans = answers[i];

            if (first[fIdx] == ans)  fRes++;
            if (second[sIdx] == ans) sRes++;
            if (third[tIdx] == ans)  tRes++;

            // 인덱스 순환
            fIdx = (fIdx + 1) % first.length;
            sIdx = (sIdx + 1) % second.length;
            tIdx = (tIdx + 1) % third.length;
        }

        int max = Math.max(fRes, Math.max(sRes, tRes));
        ArrayList<Integer> res = new ArrayList<>();

        if (fRes == max) res.add(1);
        if (sRes == max) res.add(2);
        if (tRes == max) res.add(3);

        int[] answer = new int[res.size()];
        for (int i = 0; i < res.size(); i++) answer[i] = res.get(i);
        return answer;
    }
}
