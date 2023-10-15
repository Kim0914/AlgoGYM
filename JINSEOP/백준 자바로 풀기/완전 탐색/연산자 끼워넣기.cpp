import java.io.IOException;
import java.util.Scanner;

public class Main {
    static int min_answer = Integer.MAX_VALUE;
    static int max_answer = Integer.MIN_VALUE;

    public static void bruteForce(int[] seq, int length, int sum, int depth, int add, int minus, int multiply, int divide){
        if(depth == length){
            max_answer = Math.max(max_answer, sum);
            min_answer = Math.min(min_answer, sum);

            return;
        }

        if(add > 0)
            bruteForce(seq, length, sum + seq[depth], depth + 1, add - 1, minus, multiply, divide);
        if(minus > 0)
            bruteForce(seq, length, sum - seq[depth], depth + 1, add, minus - 1, multiply, divide);
        if(multiply > 0)
            bruteForce(seq, length, sum * seq[depth], depth + 1, add, minus, multiply - 1, divide);
        if(divide > 0)
            bruteForce(seq, length, sum / seq[depth], depth + 1, add, minus, multiply, divide - 1);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int[] seq = new int[11];
        for(int i = 0; i < num; i++){
            int digit = sc.nextInt();
            seq[i] = digit;
        }

        int add = sc.nextInt(); int minus = sc.nextInt();
        int multiply = sc.nextInt(); int divide = sc.nextInt();

        bruteForce(seq, num, seq[0], 1, add, minus, multiply, divide);
        System.out.println(max_answer);
        System.out.print(min_answer);
    }
}
