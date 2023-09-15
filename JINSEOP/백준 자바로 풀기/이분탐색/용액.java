import java.lang.reflect.Array;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt(); // 용액 수
        long[] liquids = new long[100001]; // Java style array
        long answer_left = 0L, answer_right = 0L;
        for(int i = 0; i < num; i++)
            liquids[i] = sc.nextInt();
        // 중요한 것은 용액이 오름차순으로 주어짐

        int left = 0; int right = num - 1;
        // 시작칸과 마지막칸의 인덱스를 양 끝점으로 저장
        long minCharacteristicValue = 9999999999L; // 최소 특성값
        while(left < right){ // 둘이 같아지기 전까지
            long characteristicValue = liquids[left] + liquids[right];

            if(minCharacteristicValue > Math.abs(characteristicValue)){
                minCharacteristicValue = Math.abs(characteristicValue);
                answer_left = liquids[left];
                answer_right = liquids[right];
            }

            if(characteristicValue < 0)
                left++;
            else if(characteristicValue > 0)
                right--;
            else if(characteristicValue == 0)
                break; // 0이면 더 이상 탐색하지 않아도 된다.
        }

        System.out.print(answer_left + " " + answer_right);
    }
}
