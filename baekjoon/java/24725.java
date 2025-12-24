/**
 * N과 M이 200 이내니까
 * 완탐으로 하면 될 것 같음
 * Memory : 12286KB
 * Time : 96ms
 */

package p_24725;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.BufferOverflowException;
import java.util.Arrays;
import java.util.DoubleSummaryStatistics;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int Row, Col, res;
    static char[][] matrix;
    static int[] x_move = {-1,-1,0,1,1,1,0,-1};
    static int[] y_move = {0,1,1,1,0,-1,-1,-1};



    public static void main(String[] args) throws  Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        Row = Integer.parseInt(st.nextToken());
        Col = Integer.parseInt(st.nextToken());
        matrix = new char[Row+1][Col+1];

        for (int i = 1; i <= Row; ++i) {
            String buffer = br.readLine();
            for (int j = 1; j <= Col; ++j) {
                matrix[i][j] = buffer.charAt(j-1);
            }
        }

        for (int i = 1; i <= Row; ++i) {
            for (int j = 1; j <= Col; ++j) {
                for (int d = 0; d < 8; ++d) {
                    int xThresh = i + x_move[d] * 3;
                    int yThresh = j + y_move[d] * 3;

                    if (!inTheMatrix(xThresh, yThresh)) continue;

                    char c1 = matrix[i + x_move[d] * 0][j + y_move[d] * 0];
                    char c2 = matrix[i + x_move[d] * 1][j + y_move[d] * 1];
                    char c3 = matrix[i + x_move[d] * 2][j + y_move[d] * 2];
                    char c4 = matrix[i + x_move[d] * 3][j + y_move[d] * 3];

                    if (isMBTI(c1,c2,c3,c4)) ++res;
                }
            }
        }
        System.out.println(res);
    }

    static boolean inTheMatrix(int xpos, int ypos) {
        return (xpos >= 1 && xpos <= Row && ypos >= 1 && ypos <= Col);
    }

    static boolean isMBTI(char c1, char c2, char c3, char c4) {
        return (
                (c1 == 'E' || c1 == 'I') && (c2 == 'N' || c2 == 'S') && (c3 == 'T' || c3 == 'F') && (c4 == 'P' || c4 == 'J')
                );

    }

}