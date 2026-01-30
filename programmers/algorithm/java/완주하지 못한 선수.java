import java.util.*;


class Solution {
    static HashMap<String, Integer> hm = new HashMap<>();
    
    public String solution(String[] participant, String[] completion) {
        String res = "";
        
        for (int i = 0; i < participant.length; ++i) {
            String key = participant[i];
            hm.put(key, hm.getOrDefault(key, 0) + 1);
        }
         
        for (int i = 0; i < completion.length; ++i) {
            String key = completion[i];
            hm.put(key, hm.get(key) - 1);
        }
        
        
        for (Map.Entry<String, Integer> entry: hm.entrySet()) {
            if (entry.getValue() != 0)
                res = entry.getKey();
        }
        
        return res;
    }
}