import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        String[] inputString = br.readLine().split(" ");

        int[] budgets = new int[num];
        int right = 0;
        for(int i = 0; i < inputString.length; i++) {
            budgets[i] = Integer.parseInt(inputString[i]);
            right = Math.max(right, budgets[i]);
        }

        int limit = Integer.parseInt(br.readLine());
        int left = 0; int answer = 0;
        while (left <= right){
            int mid = (left + right) / 2;
            int partialSum = 0;

            for(int i = 0; i < budgets.length; i++){
                if(budgets[i] < mid)
                    partialSum += budgets[i];
                else
                    partialSum += mid;
            }

            if(partialSum <= limit) {
                left = mid + 1;
                answer = Math.max(answer, mid);
            }
            else
                right = mid - 1;
        }

        System.out.print(answer);
    }
}
