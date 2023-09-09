import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer num = sc.nextInt();
        Deque<Integer> card_deque = new ArrayDeque<>();

        for(Integer i = 1; i <= num; i++)
            card_deque.push(i); // 덱에 카드를 쌓는다.

        while (card_deque.size() != 1){ // 한 장 남을 때 까지
            card_deque.removeLast(); // 제일 위에서 제거
            Integer topOfDeque = card_deque.pollLast(); // 그 다음 장
            card_deque.push(topOfDeque); // 제일 아래로 내림
        }

        System.out.print(card_deque.pollFirst());
    }
}
