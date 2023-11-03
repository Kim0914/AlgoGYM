import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for(int i = 0; i < tc; i++){
            int num = Integer.parseInt(br.readLine());
            int[] days = new int[num];

            String[] splittedString = br.readLine().split(" ");
            for(int j = 0; j < num; j++)
                days[j] = Integer.parseInt(splittedString[j]);

            long surplusDay = days[num - 1];
            long answer = 0;
            for(int j = num - 2; j >= 0; j--){
                if(surplusDay < days[j])
                    surplusDay = days[j];

                answer += (surplusDay - days[j]);
            }

            System.out.println(answer);
        }
    }
}
