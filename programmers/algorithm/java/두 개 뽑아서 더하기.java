import java.util.*;

class Solution {
        
    public int[] solution(int[] numbers) {
        int[] answer = {};
        Set<Integer> set = new TreeSet<>();
        
        int nSize = numbers.length;
        
        for (int i = 0; i < nSize; ++i) {
            for (int j = i +1; j < nSize; ++j) {
                set.add(numbers[i] + numbers[j]);
            }
        }
        
        answer = new int[set.size()];
        int idx = 0;
        for (Integer num: set) {
            answer[idx] = num;
            idx++;
        }
        
        return answer;
    }
}