import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        Integer iter = 0, count = 0;

        while(true){
            iter++;

            if (iter.toString().contains("666")) {
                count++;
                if(count == num){
                    System.out.println(iter);
                    break;
                }
            }
        }
    }
}
