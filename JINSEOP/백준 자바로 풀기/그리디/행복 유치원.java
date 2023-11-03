import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] numAndGroups = br.readLine().split(" ");
        int num = Integer.parseInt(numAndGroups[0]);
        int groupNum = Integer.parseInt(numAndGroups[1]);
        int[] students = new int[num];
        int[] cost = new int[num - 1];

        String[] studentsString = br.readLine().split(" ");
        for(int i = 0; i < num; i++)
            students[i] = Integer.parseInt(studentsString[i]);
        for(int i = 0; i < num - 1; i++)
            cost[i] = Math.abs(students[i] - students[i + 1]);

        Arrays.sort(cost);
        int answer = 0;
        for(int i = 0; i < num - groupNum; i++)
            answer += cost[i];

        System.out.print(answer);
    }
}
