import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.*;

public class Main {
    static int N, M;
    static int[] numbers;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static List<Integer> selectedNum = new ArrayList<>();
    static StringBuilder sb = new StringBuilder(); 

    public static void main(String[] args) throws IOException {
        input();
        Arrays.sort(numbers);
        dfs(0, 1);
        bw.write(sb.toString()); 
        bw.flush();
    }

    static void input() throws IOException {
        String buffer = br.readLine();
        st = new StringTokenizer(buffer);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        numbers = new int[N + 1];

        buffer = br.readLine();
        st = new StringTokenizer(buffer);

        for (int i = 1; i <= N; ++i)
            numbers[i] = Integer.parseInt(st.nextToken());
    }

    static void dfs(int idx, int dpt) throws IOException {
        if (dpt == M + 1) {
            for (Integer num : selectedNum)
                sb.append(num).append(" ");
            sb.append("\n");
            return; // No need to flush here
        }

        for (int i = 1; i <= N; ++i) {
            selectedNum.add(numbers[i]);
            dfs(0, dpt + 1);
            selectedNum.remove(selectedNum.size() - 1);
        }
    }
}