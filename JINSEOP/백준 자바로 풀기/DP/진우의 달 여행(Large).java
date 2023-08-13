import java.util.Scanner;

public class Main {
    public static boolean validate(int row, int col, int rowLimit, int colLimit){
        return (0 <= row && row < rowLimit) && (0 <= col && col < colLimit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int result = Integer.MAX_VALUE;
        // 마지막 칸은 어느 방향에서 왔는지 저장

        int row = sc.nextInt(); int col = sc.nextInt();
        int[][] spaceMap = new int[row][col];
        int[][][] dp = new int[row][col][3];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                spaceMap[i][j] = sc.nextInt();
                if(i == 0) {
                    dp[i][j][0] = spaceMap[i][j];
                    dp[i][j][1] = spaceMap[i][j];
                    dp[i][j][2] = spaceMap[i][j];
                }
                else if(j == 0)
                    dp[i][j][2] = Integer.MAX_VALUE;
                else if(j == col - 1)
                    dp[i][j][0] = Integer.MAX_VALUE;
            }
        }


        for(int i = 1; i < row; i++){
            for(int j = 0; j<col; j++){
                if(validate(i-1, j+1, row, col)) // 0은 왼쪽 대각선으로 내려오는 경우
                    dp[i][j][0] = Math.min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + spaceMap[i][j];
                    // 연속으로 같은 두 방향으로 갈 수 없어 1과 2만 검사함
                if(validate(i-1, j, row, col)) // 1은 아래로 내려오는 경우
                    dp[i][j][1] = Math.min(dp[i-1][j][0], dp[i-1][j][2]) + spaceMap[i][j];
                if(validate(i-1, j-1, row, col)) // 2는 오른쪽 대각선으로 내려오는 경우
                    dp[i][j][2] = Math.min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + spaceMap[i][j];
            }
        }

        for(int j = 0; j < col; j++)
            for(int k = 0; k < 3; k++)
                result = Math.min(result, dp[row-1][j][k]); 
        // 마지막 행의 최솟값

        System.out.println(result);
    }
}
