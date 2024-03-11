import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int[] sequence = new int[1001];
    public static int[] dp = new int[1001];
    public static int[] answerArr = new int[1001];
    public static int[] reversedAnswerArr = new int[1001];
    public static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int len = Integer.parseInt(br.readLine());
        String[] seq = br.readLine().split(" ");
        for(int i = 0; i < seq.length; i++)
            sequence[i] = Integer.parseInt(seq[i]);

        for(int i = 0; i < len; i++){ // LIS를 구해야 함
            dp[i] = 1; // 기본적으로 1

            for(int j = 0; j < i; j++){
                if(sequence[i] > sequence[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }

            answer = Math.max(dp[i], answer);
            answerArr[i] = answer;
        } // 여기서 O(N^2) => 1000 * 1000

        answer = 0;
        for(int i = len - 1; i >= 0; i--){ // LIS를 거꾸로 구하자
            dp[i] = 1; // 기본적으로 1

            for(int j = len - 1; j > i; j--){
                if(sequence[i] > sequence[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }

            answer = Math.max(dp[i], answer);
            reversedAnswerArr[i] = answer;
        } // 여기서 다시 O(N^2) => 1000 * 1000

        answer = 0;
        for(int i = 0; i < len; i++) // 여기서 O(N) => 1000
            answer = Math.max(answer, (answerArr[i] + reversedAnswerArr[i]));
        System.out.print(answer - 1);
        // 최종 시간복잡도는 O(N^2), 시간초과 안날 듯
    }
}
