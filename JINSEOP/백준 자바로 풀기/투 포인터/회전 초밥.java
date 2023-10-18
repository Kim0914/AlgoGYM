import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] numbers = br.readLine().split(" ");
        int num = Integer.parseInt(numbers[0]);
        int seqNum = Integer.parseInt(numbers[2]);
        int couponNum = Integer.parseInt(numbers[3]);
        int answer = 0;

        int[] belt = new int[num];
        for(int i = 0; i < num; i++)
            belt[i] = Integer.parseInt(br.readLine());
        // 초밥 벨트 입력 받자

        HashMap<Integer, Integer> sushiMap = new HashMap<>();
        int rear_ptr = -1;
        sushiMap.put(couponNum, 1); // 쿠폰은 항상 먹을 수 있음

        for(int front_ptr = 0; front_ptr < num; front_ptr++){ // 슬라이딩 윈도우 이용
            while ((rear_ptr - front_ptr) < seqNum - 1){
                rear_ptr++;

                if(!sushiMap.containsKey(belt[rear_ptr % num])) {
                    sushiMap.put(belt[rear_ptr % num], 1);
                    answer = Math.max(answer, sushiMap.size());
                }
                else
                    sushiMap.replace(belt[rear_ptr % num], sushiMap.get(belt[rear_ptr % num]) + 1);
            }

            sushiMap.replace(belt[front_ptr], sushiMap.get(belt[front_ptr]) - 1);
            if(sushiMap.get(belt[front_ptr]) == 0)
                sushiMap.remove(belt[front_ptr]);
        }

        System.out.print(answer);
    }
}
