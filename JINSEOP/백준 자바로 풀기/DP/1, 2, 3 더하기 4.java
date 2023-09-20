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
        long[] dp = new long[10001];

        dp[0] = 1; // 0은 1가지 경우 밖에 없다.
        for(int i = 0; i < tc; i++){
            int num = sc.nextInt();

            for(int j = 1; j <= 3; j++){
                // 어떤 점화식을 세울 것인가?
                // DP의 기본, 이전 단계까지의 정보를 이용하라.
                for(int k = j; k <= num; k++)
                    dp[k] += dp[k-j];
                // 직접 다 적어보면, 1은 1이 증가할 때 마다 쌓이고
                // 2는 2가 증가할 때 마다 쌓이며
                // 3은 3이 증가할 때 마다 쌓임을 알 수 있다.
            }

            System.out.println(dp[num]);
            clearDp(dp, num);
        }
    }
}
