import java.util.*;

class Solution {
    
    static Deque<Character> q = new ArrayDeque<>();
    
    boolean solution(String s) {
        
        for (int i = 0 ; i < s.length(); ++i) {
            char c = s.charAt(i);
            
            if (c == '(')
                q.addLast(c);
            else {
                if (q.isEmpty()) return false;
                else if (q.peekLast() == '(')
                    q.pollLast();
            }
        }
        
        return q.isEmpty();
    
    }
}