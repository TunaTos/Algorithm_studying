/*
    금액을 지불하면 10일동안 회원 자격 부여
    자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치하는 경우
    
    바나나 3, 사과2, 돼지2, 냄비 1
    14일간 회원을 대상으로 하는 거
    치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나
    
    two pointer + HashMap
*/

import java.util.*;

class Solution {
    
    static HashMap<String, Integer> map = new HashMap<>();
    static int idx1 = 0, idx2 = 9, res;
    
    public int solution(String[] want, int[] number, String[] discount) {
        
        // 초기 설정
        for (int i = idx1; i <= idx2; ++i) {
            String d = discount[i];
            if (map.get(d) == null) {
                map.put(d,1);
            } else {
                map.put(d, map.get(d) + 1);
            }
        }
        
        while (true) {
            checkingResult(want,number);
            
            // update idx1            
            int k1 = map.get(discount[idx1]);
            if (k1 == 1)
                map.remove(discount[idx1]);
            else
                map.put(discount[idx1], k1-1);
            ++idx1;
            
            // update idx2
            if (idx2 == discount.length - 1) {
                return res;
            } else {
                idx2++;
                int num = map.getOrDefault(discount[idx2], 0);
                if (num == 0) {
                    map.put(discount[idx2], 1);
                } else {
                    map.put(discount[idx2], num + 1);
                }
            }
        }
    }
    
    static void debug() {
        for (Map.Entry<String,Integer> entry: map.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
    
    
    static void checkingResult(String[] want, int[] number) {
        for (int i = 0; i < want.length; ++i) {
            
            if (map.getOrDefault(want[i], 0) != number[i]) {
                return;
            }
        }
        ++res;
    }
}