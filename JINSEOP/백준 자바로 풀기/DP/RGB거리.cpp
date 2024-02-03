import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void initDp(int[][] dp, int[][] houseColor){
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] dp = new int[3][1001];
        int[][] houseColor = new int[3][1001];

        int num = Integer.parseInt(br.readLine());
        for(int col = 0; col < num; col++){
            String[] colorValues = br.readLine().split(" ");

            for(int row = 0; row < colorValues.length; row++)
                houseColor[row][col] = Integer.parseInt(colorValues[row]);
        } // 여기까지가 입력

        initDp(dp, houseColor);
        for(int i = 1; i <= num; i++){
            dp[0][i] = Math.min(dp[1][i-1], dp[2][i-1]) + houseColor[0][i-1];
            dp[1][i] = Math.min(dp[0][i-1], dp[2][i-1]) + houseColor[1][i-1];
            dp[2][i] = Math.min(dp[0][i-1], dp[1][i-1]) + houseColor[2][i-1];
        }

        System.out.print(Math.min(Math.min(dp[0][num], dp[1][num]), dp[2][num]));
    }
}
