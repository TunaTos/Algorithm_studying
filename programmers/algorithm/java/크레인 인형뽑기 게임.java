/*
    만약 인형이 없는 경우는 아무 일도 작동하지 않는다.
    바구니는 무한하다
    정사각형
    
    작동시켜 터트린 후 사라진 인형의 개수는?
    board는 5 * 5 ~ 30 * 30
    
*/

import java.util.*;

class Solution {
    static Deque<Integer> dq = new ArrayDeque<>();
    static int N, res;
    public int solution(int[][] board, int[] moves) {
        N = board[0].length;
        
        for (int i = 0; i < moves.length; ++i) {
            int picked = move(board, moves[i]);
            if (picked == 0)
                continue;
            if (dq.isEmpty() || (dq.peekLast() != picked)) {
                dq.addLast(picked);
            } else {
                dq.pollLast();
                res += 2;
            }
        }
        
        return res;
    }
    
    static int move(int[][] board, int dir) {
        // dir은 시작점
        for (int i = 0; i < N; ++i) {
            if (board[i][dir-1] != 0) {
                int res = board[i][dir-1];
                board[i][dir-1] = 0;
                return res;
            }
        }
        
        return 0;
    }
}