import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        ArrayList<BigInteger> answer = new ArrayList<>();
        ArrayList<String> finalAnswer = new ArrayList<>();

        for(int i = 0; i < tc; i++){
            String inputString = sc.next();

            String[] split = inputString.split("\\D");
          // 해당 정규식을 이용하면, 숫자가 아닌 문자를 기준으로 split하여 숫자만 남는다.
            for (String s : split)
                if (!s.equals(""))
                    answer.add(new BigInteger(s));
        }

        Collections.sort(answer);
        for (BigInteger num : answer)
            finalAnswer.add(num.toString());
        for(String s : finalAnswer) // 숫자를 다시 문자로 저장
            System.out.println(s);
    }
}
