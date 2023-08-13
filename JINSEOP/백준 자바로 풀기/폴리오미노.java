import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String base = scanner.nextLine();
        base = base.replace("XXXX", "AAAA");
        base = base.replace("XX", "BB");

        if(base.contains("X"))
            System.out.println(-1);
        else
            System.out.println(base);
    }
}
