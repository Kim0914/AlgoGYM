import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] storage = new int[1001];
        Integer answer = 0, currMax = 0, maxIdx = 0, endIdx = 0;

        int num = sc.nextInt();
        for(int i = 0; i < num; i++){
            Integer x = sc.nextInt();
            Integer y = sc.nextInt();
            storage[x] = y;

            if(currMax < y){
                currMax = y;
                maxIdx = x;
            }

            if(endIdx < x)
                endIdx = x;
        } // 여기까지 정보 저장

        answer += currMax; // 가장 높은 높이 기둥 미리 더함
        currMax = 0;
        for(int i = 0; i < maxIdx; i++){
            if(currMax < storage[i])
                currMax = storage[i];

            answer += currMax;
        } // 좌측 넓이 총 합

        currMax = 0;
        for(int i = endIdx; i > maxIdx; i--){
            if(currMax < storage[i])
                currMax = storage[i];

            answer += currMax;
        } // 우측 넓이 총합

        System.out.println(answer);
    }
}
