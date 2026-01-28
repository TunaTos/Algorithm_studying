class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int idx1 = 0 , idx2 = 0, idx3 = 0;
        
        while (idx3 < goal.length) {
            
            if (idx1 < cards1.length && cards1[idx1].equals(goal[idx3])) {
                idx1++;
                idx3++;
                continue;
            }
            
            if (idx2 < cards2.length && cards2[idx2].equals(goal[idx3])) {
                idx2++;
                idx3++;
                continue;
            }
            
            return "No";
        }
        
        return "Yes";
    }
}