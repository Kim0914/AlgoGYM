import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int coinKind = scanner.nextInt();
        int money = scanner.nextInt();
        int count = 0;
        ArrayList<Integer> coinList = new ArrayList<>();

        for(int i = 0; i < coinKind; i++)
            coinList.add(scanner.nextInt());

        for(int i = coinKind - 1; i >= 0; i--) {
            if(money >= coinList.get(i)){
                count += (money / coinList.get(i));
                money %= coinList.get(i);
            }
        }

        System.out.println(count);
    }
}
