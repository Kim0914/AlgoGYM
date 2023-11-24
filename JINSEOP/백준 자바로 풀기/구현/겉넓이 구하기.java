import com.sun.security.jgss.GSSUtil;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int vert = Integer.parseInt(s[0]);
        int hori = Integer.parseInt(s[1]);

        int[][] cubes = new int[vert + 2][hori + 2];
        for(int i = 1; i <= vert; i++){
            String[] oneLine = br.readLine().split(" ");
            for(int j = 1; j <= oneLine.length; j++){
                cubes[i][j] = Integer.parseInt(oneLine[j-1]);
            }
        }

        int answer = 0;
        answer += (vert * hori * 2); // 윗면 아랫면

        for(int i = 1; i <= vert; i++) {
            for (int j = 1; j <= hori; j++) {
                int diff = cubes[i][j] - cubes[i][j - 1];

                if (diff >= 0)
                    answer += diff;
            }
        }
        // Left view

        for(int i = 1; i <= vert; i++) {
            for (int j = hori; j >= 1; j--) {
                int diff = cubes[i][j] - cubes[i][j + 1];

                if (diff >= 0)
                    answer += diff;
            }
        }
        // Right view

        for(int i = 1; i <= hori; i++) {
            for (int j = vert; j >= 1; j--) {
                int diff = cubes[j][i] - cubes[j + 1][i];

                if(diff >= 0)
                    answer += diff;
            }
        }
        // Front view

        for(int i = 1; i <= hori; i++)
            for(int j = 1; j <= vert; j++) {
                int diff = cubes[j][i] - cubes[j - 1][i];

                if(diff >= 0)
                    answer += diff;
            }
        // Rear view

        System.out.print(answer);
    }
}
