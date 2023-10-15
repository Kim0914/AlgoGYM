import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        Integer[] waitingLine = new Integer[num];
        for(int i = 0; i < num; i++)
            waitingLine[i] = sc.nextInt();

        long answer = 0;
        Arrays.sort(waitingLine, Collections.reverseOrder());
        for(int i = 0; i < num; i++)
            if((waitingLine[i] - i) > 0)
                answer += (waitingLine[i] - i);

        System.out.print(answer);
    }
}
