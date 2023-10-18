import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt();
        int col = sc.nextInt();
        char[][] cloudMap = new char[row][col];
        int[][] cloudMovingMap = new int[row][col];

        for(int i = 0; i < row; i++){
            String stringToSplit = sc.next();
            for(int j = 0; j < col; j++){
                cloudMap[i][j] = stringToSplit.charAt(j);
            }
        } // 맵 저장

        for(int i = 0; i < row; i++){
            int cloudCount = -1;
            boolean cloudFlag = false;

            for(int j = 0; j < col; j++){
                if(cloudMap[i][j] == 'c'){
                    cloudCount = 0;
                    cloudFlag = true;
                }

                if(cloudFlag) {
                    cloudMovingMap[i][j] = cloudCount;
                    cloudCount++;
                }
                else{
                    cloudMovingMap[i][j] = cloudCount;
                 }
            }
        }

        for(int i = 0; i < row; i++){
            System.out.println();
            for(int j = 0; j < col; j++){
                    System.out.print(cloudMovingMap[i][j]);
            }
        } // 맵 출력
    }
}
