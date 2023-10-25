import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int level = Integer.parseInt(br.readLine());
        int[][] dp = new int[101][10];
        long divisor = 1000000000;

        for(int i = 1; i <= 9; i++)
            dp[1][i] = 1; // 한 자리수는 무조건 자기 자신 뿐

        for(int i = 2; i <= level; i++){
            for(int j = 0; j <= 9; j++){
                if(j == 0) // 0은 1만 생각하면 됨
                    dp[i][j] += dp[i-1][1] % divisor;
                else if(j == 9) // 9는 8만 생각하면 됨
                    dp[i][j] += dp[i-1][8] % divisor;
                else // 나머지는 앞 뒤로 두 개 생각해야 함
                    dp[i][j] += (dp[i-1][j-1] + dp[i-1][j+1]) % divisor;
            }
        }

        long answer = 0;
        for(int i = 0; i <= 9; i++)
            answer += dp[level][i];
            // 해당 자릿수의 계단 수 개수를 0부터 9까지 쭉 더해준다.

        System.out.println(answer % divisor);
    }
}
