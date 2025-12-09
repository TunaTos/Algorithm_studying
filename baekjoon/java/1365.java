
import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static List<Integer> number = new ArrayList<>();
    static List<Integer> res = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        input();
        getResult();
        System.out.println(N - res.size());
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            number.add(Integer.parseInt(st.nextToken()));
        }
    }

    static void getResult() {
        for (int num : number) {
            int idx = Collections.binarySearch(res, num);
            if (idx < 0) {
                idx = -(idx + 1); // lower_bound 위치 구하기
            }
            if (idx == res.size()) {
                res.add(num);
            } else {
                res.set(idx, num);
            }
        }
    }
}
