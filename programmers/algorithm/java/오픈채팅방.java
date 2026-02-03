/*
    본래의 닉네임이 아니라 가상의 닉네임 사용가능
    
    닉네임이 들어왔다
    닉네임이 나갔다
    
    닉네임을 변경하는 방법
        채팅방 나간 뒤 -> 새로운 닉네임
        채팅방에서 변경
    
    닉네임 변경하면 기존에 있는 닉네임 전부 변경된다.
    
    Muzi 들
    Prodo 들
    Muzi -> 나갔음   
    
    중복 닉네임끼리도 구분해야한다.
    
    record -> 1 <= x 100_000
    
    유저의 구분 -> 유저 아이디
    
    첫단어 -> Entrry,Leave,Change
    유저 아이디와 닉네임의 길이는 1이상 10이하
    잘못된 입력은 없다.
*/


import java.io.*;
import java.util.*;


class Solution {
    static class Node {
        public String id;
        public int action; // 들어옴 -> 1, 나갔음 -> 2
        
        Node(String id, int action) {
            this.id = id;
            this.action = action;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Node> nodes = new ArrayList<>();
    
    static String[] res;
    static String order, id, nickName;
    static HashMap<String, String> hm = new HashMap<>(); // {id, nickName}
    public String[] solution(String[] record) {
        
        // init  container 
        
        
        for (int i = 0; i < record.length; ++i) {
            StringTokenizer st = new StringTokenizer(record[i]);
            String order = st.nextToken();
            
            if (order.equals("Enter")) {
                id = st.nextToken();
                nickName = st.nextToken();
                
                handleEnter(i);
            }
            else if (order.equals("Change")) {
                id = st.nextToken();
                nickName = st.nextToken();
                
                handleChange(i);
            } else if (order.equals("Leave")) {
                id = st.nextToken();
                handleLeave(i);
            }
        }
        
        
        
        // set Result
        res = new String[nodes.size()];
        
        for (int i = 0; i < nodes.size(); ++i) {
            // System.out.println(nodes.get(i).id + " " +nodes.get(i).action);
                
            
            String nickName = hm.get(nodes.get(i).id);
            String a = "";
            
            if (nodes.get(i).action == 1) {
                a = "님이 들어왔습니다.";
            } else {
                // action == 2
                a = "님이 나갔습니다.";
            }
            res[i] = new String(nickName + a);
            
        }
        return  res;
    }
    
    static void handleEnter(int i) {
        nodes.add(new Node(id,1));
        hm.put(id, nickName);
    }
    
    static void handleChange(int i) {
        hm.put(id, nickName);
    }
    
    static void handleLeave(int i) {
        nodes.add(new Node(id,2));
    }
    
    
    
}