import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        long num1 = sc.nextInt();
        long num2 = sc.nextInt();

        BigInteger numerator = BigInteger.ONE;
        BigInteger denominator = BigInteger.ONE;
        // 이항 계수의 각 항은 조합과 동일하다

        for(long i = 0; i < num2; i++)
            numerator = numerator.multiply(new BigInteger(String.valueOf(num1 - i)));
        for(long i = num2; i >= 1; i--)
            denominator = denominator.multiply(new BigInteger(String.valueOf(i)));

        if(!denominator.equals(BigInteger.ZERO))
            System.out.println((numerator.divide(denominator)).mod(BigInteger.valueOf(10007)));
        else
            System.out.println(1);
    }
}

// BigInteger의 사용법에 대해 깨달았습니다.
