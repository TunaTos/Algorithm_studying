
import java.io.*;
import java.util.*;

public class Main {

    static class Block implements Comparable<Block> {
        int index;  // 원래 벽돌 번호
        int area;   // 밑면 넓이
        int height; // 높이
        int weight; // 무게

        public Block(int index, int area, int height, int weight) {
            this.index = index;
            this.area = area;
            this.height = height;
            this.weight = weight;
        }

        // 넓이 내림차순 정렬 (넓이 큰 게 아래로 가야 하므로)
        public int compareTo(Block o) {
            return o.area - this.area;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Block[] blocks = new Block[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int area = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            blocks[i] = new Block(i + 1, area, height, weight); // 1-based index
        }

        // 넓이 내림차순으로 정렬
        Arrays.sort(blocks);

        int[] dp = new int[N]; // i번째 벽돌이 맨 아래일 때의 최대 높이
        int[] prev = new int[N]; // 경로 추적용 (이전 벽돌의 index)

        int maxHeight = 0;
        int lastIndex = 0;

        for (int i = 0; i < N; i++) {
            dp[i] = blocks[i].height;
            prev[i] = -1; // 초기화

            for (int j = 0; j < i; j++) {
                if (blocks[j].weight > blocks[i].weight) { // 무게 조건
                    if (dp[j] + blocks[i].height > dp[i]) {
                        dp[i] = dp[j] + blocks[i].height;
                        prev[i] = j;
                    }
                }
            }

            // 최대 높이 갱신
            if (dp[i] > maxHeight) {
                maxHeight = dp[i];
                lastIndex = i;
            }
        }

        // 탑 구성 벽돌 추적 (위에서 아래로)
        List<Integer> result = new ArrayList<>();
        while (lastIndex != -1) {
            result.add(blocks[lastIndex].index);
            lastIndex = prev[lastIndex];
        }

        // 출력
        System.out.println(result.size());
        for (int i = 0; i <  result.size() ; i++) {
            System.out.println(result.get(i));
        }
    }
}
