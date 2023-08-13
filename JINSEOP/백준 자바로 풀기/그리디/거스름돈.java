import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int change = scanner.nextInt(); // 입력받는 코드
        int answer = 0;

        while(true){
            if(change % 5 == 0){ // 5의 배수이면
                answer += (change/5); // 카운트에 추가
                System.out.println(answer); // 곧바로 정답
                break;
            }
            else{
                answer++; // 아니면 5의 배수가 될 때 까지
                change -= 2; // 2를 뺀다
            }

            if(change < 0){ // 2를 계속 빼도 5의 배수가 안나오는 경우
                System.out.println(-1);
                break;
            }
        }
    }
}
