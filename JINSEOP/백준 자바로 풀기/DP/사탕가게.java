import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static class Pair{
        int calorie;
        int cost;

        public Pair(int calorie, int cost){
            this.calorie = calorie;
            this.cost = cost;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        while(true){
            int num = sc.nextInt();
            int afford = (int) (sc.nextDouble() * 100 + 0.5);
            if(num == 0)
                break;
            // 정수로 변환하는게 편한데, 부동소수점의 오차를 방지한다.

            int[] dp = new int[afford + 1];
            ArrayList<Pair> candies = new ArrayList<>();
            for(int i = 0; i < num; i++){ // 사탕 정보 입력받기
                int calorie = sc.nextInt();
                int cost = (int) (sc.nextDouble() * 100 + 0.5);

                candies.add(new Pair(calorie, cost));
            }

            for(int i = 0; i < num; i++)
                for(int j = 1; j <= afford; j++)
                    if(j - candies.get(i).cost >= 0) // 지불 가능한 금액이면?
                        dp[j] = Math.max(dp[j], dp[j - candies.get(i).cost] + candies.get(i).calorie);
                    // 이전 사탕으로 쌓았던 금액과 현재 사탕으로 쌓이는 금액 비교
            sb.append(dp[afford]).append('\n');
        }
        System.out.print(sb);
    }
}
