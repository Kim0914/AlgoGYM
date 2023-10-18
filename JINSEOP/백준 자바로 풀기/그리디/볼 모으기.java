import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    private static int moveBlueToLeft(String balls){
        int cnt = 0;
        boolean colorFlag = false;

        for(int i = 0; i < balls.length(); i++){
            if(balls.charAt(i) == 'R')
                colorFlag = true;

            if(colorFlag && balls.charAt(i) == 'B')
                cnt++;
        }

        return cnt;
    }

    private static int moveBlueToRight(String balls){
        int cnt = 0;
        boolean colorFlag = false;

        for(int i = balls.length() - 1; i >= 0; i--){
            if(balls.charAt(i) == 'R')
                colorFlag = true;

            if(colorFlag && balls.charAt(i) == 'B')
                cnt++;
        }

        return cnt;
    }

    private static int moveRedToLeft(String balls){
        int cnt = 0;
        boolean colorFlag = false;

        for(int i = 0; i < balls.length(); i++){
            if(balls.charAt(i) == 'B')
                colorFlag = true;

            if(colorFlag && balls.charAt(i) == 'R')
                cnt++;
        }

        return cnt;
    }

    private static int moveRedToRight(String balls){
        int cnt = 0;
        boolean colorFlag = false;

        for(int i = balls.length() - 1; i >= 0; i--){
            if(balls.charAt(i) == 'B')
                colorFlag = true;

            if(colorFlag && balls.charAt(i) == 'R')
                cnt++;
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // PS를 할 때에는 이렇게 입력을 받으면 시간이 빨라요
        int num = Integer.parseInt(br.readLine());
        String balls = br.readLine();
        int answer = Integer.MAX_VALUE;

        answer = Math.min(answer, moveBlueToLeft(balls));
        answer = Math.min(answer, moveBlueToRight(balls));
        answer = Math.min(answer, moveRedToLeft(balls));
        answer = Math.min(answer, moveRedToRight(balls));
        // 경우가 4가지 밖에 되지 않으므로 모두 확인하도록 한다.
      
        System.out.print(answer);
    }
}
