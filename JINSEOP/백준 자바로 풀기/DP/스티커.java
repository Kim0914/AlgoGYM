import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void clearDp(long[] dp, int num){
        for(int i = 1; i <= num; i++)
            dp[i] = 0;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        for(int i = 0; i < tc; i++){
            int num = sc.nextInt();
            int[][] stickers = new int[2][100000];
            int[][] dp = new int[2][100000];

            for(int row = 0; row < 2; row++)
                for(int col = 0; col < num; col++)
                    stickers[row][col] = sc.nextInt();
            // 스티커 입력받음

            dp[0][0] = stickers[0][0]; dp[1][0] = stickers[1][0]; // basis
            dp[0][1] = dp[1][0] + stickers[0][1]; dp[1][1] = dp[0][0] + stickers[1][1];

            for(int col = 2; col < num; col++){
                dp[0][col] = Math.max(dp[1][col-2] + stickers[0][col], dp[1][col-1] + stickers[0][col]);
                dp[1][col] = Math.max(dp[0][col-2] + stickers[1][col], dp[0][col-1] + stickers[1][col]);
            }

            System.out.println(Math.max(dp[0][num - 1], dp[1][num - 1]));
        }
    }
}
