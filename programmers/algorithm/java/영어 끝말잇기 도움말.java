import java.util.*;

class Solution {

    static HashSet<String> set = new HashSet<>();
    static String back = "", cur = "";

    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0, 0};

        for (int i = 1; i <= words.length; ++i) {
            cur = words[i - 1];
            if (i != 1) back = words[i - 2];

            if (i != 1) {
                if (back.charAt(back.length() - 1) != cur.charAt(0)) {
                    return new int[]{
                        ((i - 1) % n) + 1,
                        ((i - 1) / n) + 1
                    };
                }
            }

            if (set.contains(cur)) {
                return new int[]{
                    ((i - 1) % n) + 1,
                    ((i - 1) / n) + 1
                };
            }

            set.add(cur);
        }

        return answer;
    }
}
