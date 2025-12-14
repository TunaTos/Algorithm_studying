import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String buffer;
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int N, res; // N은 이닝
    static int[][] matrix;
    static int[] selected;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        input();
        getPermutation(0);
        System.out.println(res);
    }

    // 가지치기 함수
    static boolean prunning(int dpt) {
        // 4번 타자(dpt == 3)가 1번 선수인지 확인
        if (dpt == 4 && selected[3] != 1) {
            return false; // 더 이상 탐색하지 않음
        }
        return true; // 계속 탐색
    }

    static void getPermutation(int dpt) {
        if (dpt == 9) {
            int score = 0;
            int currentHitter = 0; // 현재 타자의 위치 (0부터 시작)

            for (int i = 1; i <= N; i++) { // 각 이닝
                int outCount = 0;
                int[] bases = new int[3]; // 1루, 2루, 3루

                while (outCount < 3) {
                    int hitter = selected[currentHitter]; // 현재 타자
                    int action = matrix[i][hitter]; // 타자의 행동

                    if (action == 0) { // 아웃
                        outCount++;
                    } else if (action == 1) { // 안타
                        score += bases[2]; // 3루 주자 득점
                        bases[2] = bases[1]; // 2루 -> 3루
                        bases[1] = bases[0]; // 1루 -> 2루
                        bases[0] = 1; // 타자 -> 1루
                    } else if (action == 2) { // 2루타
                        score += bases[2] + bases[1]; // 3루, 2루 주자 득점
                        bases[2] = bases[0]; // 1루 -> 3루
                        bases[1] = 1; // 타자 -> 2루
                        bases[0] = 0; // 1루 비움
                    } else if (action == 3) { // 3루타
                        score += bases[2] + bases[1] + bases[0]; // 3루, 2루, 1루 주자 득점
                        bases[2] = 1; // 타자 -> 3루
                        bases[1] = 0; // 2루 비움
                        bases[0] = 0; // 1루 비움
                    } else if (action == 4) { // 홈런
                        score += bases[2] + bases[1] + bases[0] + 1; // 모든 주자 + 타자 득점
                        bases[2] = 0; // 3루 비움
                        bases[1] = 0; // 2루 비움
                        bases[0] = 0; // 1루 비움
                    }

                    currentHitter = (currentHitter + 1) % 9; // 다음 타자
                }
            }

            res = Math.max(res, score);
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                selected[dpt] = i;

                // 가지치기 조건 확인
                if (prunning(dpt)) {
                    getPermutation(dpt + 1);
                }

                visited[i] = false;
            }
        }
    }

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        matrix = new int[N + 1][10]; // 이닝은 1부터, 선수는 1부터 9까지

        for (int i = 1; i <= N; i++) {
            buffer = br.readLine();
            st = new StringTokenizer(buffer);

            for (int j = 1; j <= 9; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        selected = new int[9];
        visited = new boolean[10];
    }
}