/*
    주식 가격이 담긴 배열
    가격이 떨어지지 않은 기간은 몇 초인가? (a,b) -> (a <= b)
    
    각각의 price는 10,000
    price의 길이는 2 <= x <= 100_000
    
    n * n은 안됨,
*/
import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] result = new int[prices.length];
        
        for (int i = 0; i < prices.length; ++i) {
            int tmp = 0;
            for (int j = i + 1; j < prices.length; ++j) {
                ++tmp;
                if (prices[j] < prices[i]) {
                    result[i] = tmp;
                    break;
                }
            }
            result[i] = tmp;
        }
        
        return result;
    }
}