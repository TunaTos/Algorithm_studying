/*
    접두사인 경우가 있는가?
    
    전화번호부 전화번호
    
    각 전화번호의 길이 -> 20
    phone_book의 길아 -> 1_000_000
    
    2 * 10 ^ 7
    같은 전화번호 중복은 없음
    
    어떤 전화번호가 접두어인 경우 -> false
    어떤 전화번호가 접두어가 아닌 경우 -> true
    
*/
import java.util.*;


class Solution {
    static HashSet<String> hs = new HashSet<>();
    
    public boolean solution(String[] phone_book) {
        for (String phone: phone_book) {
            hs.add(phone);
        }
        
        for (String phone: phone_book) {
            for (int i = 1; i < phone.length(); ++i) {
                if (hs.contains(phone.substring(0, i))) 
                    return false;
            }
        }
        
        return true;
        
    }
}