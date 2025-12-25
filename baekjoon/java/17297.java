/**
 * Memory : 11532 kb
 * Time : 64ms
 *
 */
package p_17297;

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static long M;

    static final String first = "Messi";
    static final String second = "Messi Gimossi";

    public static void main(String[] args) throws IOException {

        M = Long.parseLong(br.readLine().trim());

        ArrayList<Long> L = new ArrayList<>();
        L.add((long) first.length());   // S1
        L.add((long) second.length());  // S2

        while (L.get(L.size() - 1) < M) {
            long next = L.get(L.size() - 1) + L.get(L.size() - 2) + 1;
            L.add(next);
        }

        int idx = L.size() - 1;

        while (idx >= 2) {
            long leftLen = L.get(idx - 1);   // L[n-1]
            long rightLen = L.get(idx - 2);  // L[n-2]

            if (M <= leftLen) {
                idx = idx - 1;
            } else if (M == leftLen + 1) {
                System.out.println("Messi Messi Gimossi");
                return;
            } else {
                M = M - (leftLen + 1);
                idx = idx - 2;
            }
        }

        String base = (idx == 0) ? first : second;
        char c = base.charAt((int) M - 1);

        if (c == ' ') System.out.println("Messi Messi Gimossi");
        else System.out.println(c);
    }
}
