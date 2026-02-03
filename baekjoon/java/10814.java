package p_10814;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Node {
        int age;
        int time;
        String name;

        Node(int age, int time, String name) {
            this.age = age;
            this.time = time;
            this.name = name;
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static PriorityQueue<Node> nodes = new PriorityQueue<>((a,b) -> {
        if (a.age == b.age) {
            return Integer.compare(a.time, b.time);
        } else {
            return Integer.compare(a.age, b.age);
        }
    });

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int age = Integer.parseInt(st.nextToken());
            String name = st.nextToken();

            nodes.add(new Node(age, i, name));
        }

        while (!nodes.isEmpty()) {
            Node node = nodes.poll();
            System.out.println(node.age + " " + node.name);
        }
    }
}
