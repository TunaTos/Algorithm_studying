import java.util.*;

class Solution
{
    static Deque<Character> dq = new ArrayDeque<>();
    
    public int solution(String s)
    {
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            
            if (dq.isEmpty() || dq.peekLast() != c)
                dq.addLast(c);
            else if (dq.peekLast() == c)
                dq.pollLast();
        }
        
        if (dq.isEmpty())
            return 1;
        else
            return 0;
        
    }
}