import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int limit = sc.nextInt();
        int[][] dp = new int[101][100001];
        // DP 배열 가로가 무게, 세로가 아이템 수
        int[] weights = new int[101];
        int[] costs = new int[101];

        for(int i = 1; i <= num; i++){
            weights[i] = sc.nextInt();
            costs[i] = sc.nextInt();
        }

        for(int i = 1; i <= num; i++){
            for(int j = 1; j <= num; j++){ // 가로가 무게이다.
                if(j - weights[i] >= 0) // 수용 가능한 무게이면
                    dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j - weights[i]] + costs[i]);
                // 그냥 이전 값을 가져올 것이냐?
                // 현재 가리키고 있는 아이템의 무게를 뺸 이전 값에 현재 아이템의 가치를 더한다.
                else // 수용이 불가능하면 이전 아이템 값 그대로 가져옴
                    dp[i][j] = dp[i-1][j];
            }
        }

        System.out.print(dp[num][limit]);
        // DP 배열의 세로가 아이템 수, 가로가 무게
    }
}
