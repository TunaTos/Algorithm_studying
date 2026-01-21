/*
    실패율 :
        스테이지에 도달했으나, 클리어하지 못한 사람 
        /
        스테이지에 도달한 플레이어 수
        
        전체 스테이지 개수 N, "도전중인" 스테이지가 번호가 담긴 stages
        
        출력)
            실패율이 높은 스테이지부터 -> 내림차순
            실패율이 같으면 -> 작은 번호
*/
import java.util.*;
import java.lang.*;
class Node implements Comparable<Node> { 
    int pos;
    double ratio;
    
    Node(int pos, double ratio) {
        this.pos = pos;
        this.ratio = ratio;
    }
    
    @Override
    public int compareTo(Node other) {
        if (this.ratio == other.ratio) 
            return Integer.compare(this.pos, other.pos);
        else 
            return Double.compare(other.ratio, this.ratio);
    }
    
}

class Solution {
    /*
        N : 스테이지 개수
        stages : 멈춰있는 스테이지
    */
    
    public int[] solution(int N, int[] stages) {
        int[] tried = new int[N+1];
        int[] failed = new int[N+1];
        
        int sLen = stages.length;
        
        for (int i = 0; i < sLen; ++i) {
            int n = stages[i];
            
            if (n != N+1)
                failed[n] += 1;
            
            fill(n-1, tried);
        }
        
        Node[] res = getResult(tried, failed, N);
        
        int[] tmp = new int[N];
        
        for (int i = 0; i < N; ++i) {
            tmp[i] = res[i].pos;
        }
        
        
        return tmp;
    }
    
    void fill(int n, int[] arr) {
        for (int i = 1; i <= n; ++i)
            arr[i] += 1;
    }
    
    Node[] getResult(int[] tried, int[] failed, int N) {
        Node[] res = new Node[N+1];
        int idx = 1;
        
        for (int i = 1; i < tried.length; ++i) {
            if (failed[i] == 0)
                res[i] = new Node(idx, 0.0);
            else
                res[i] = new Node(idx, (double)failed[i] / tried[i]);
            ++idx;
        }
        res[0] = new Node(Integer.MAX_VALUE, 0.0);
        Arrays.sort(res);
        return res;
    }
}