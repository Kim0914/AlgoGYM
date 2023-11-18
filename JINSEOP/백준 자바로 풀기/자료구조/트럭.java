import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static int[] truckList = new int[1000];
    public static Queue<Integer> bridgeQueue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] infoString = br.readLine().split(" ");
        int truckNum = Integer.parseInt(infoString[0]);
        int bridgeLength = Integer.parseInt(infoString[1]);
        int maxWeight = Integer.parseInt(infoString[2]);

        String[] truckString = br.readLine().split(" ");
        for(int i = 0; i < truckString.length; i++)
            truckList[i] = Integer.parseInt(truckString[i]);
        // 트럭 무게 저장

        long answerTimer = 0;
        int currWeight = 0;
        for(int i = 0; i < truckNum; i++){
            while(true){
                if(bridgeQueue.size() == bridgeLength){
                    // 다리 길이랑 큐 길이가 같아지면 더 이상 트럭은 못올라감 (트럭 길이는 1)
                    currWeight -= bridgeQueue.poll();
                    // 현재 무게에서 빼면서 트럭을 다리에서 빼준다.
                }

                if(truckList[i] + currWeight <= maxWeight)
                    break;
                // 가리키고있는 트럭이 올라가도 상관없다면? 다음 트럭을 넣자.
                bridgeQueue.add(0);
                // 무게가 꽉 찼을 때 유령 트럭을 넣어 시간을 가게 하는 것이 핵심이다.
                // 트럭이 더 이상 올라오지 못해도 시간은 계속 가기 때문!!
                answerTimer++;
            }

            bridgeQueue.add(truckList[i]);
            currWeight += truckList[i];
            answerTimer++;
            // 다리에 트럭을 올릴 수 있는 경우에는 트럭을 집어 넣어 준다.
            // 트럭이 올라갈 때도 시간은 간다.
        }

        System.out.print(answerTimer + bridgeLength);
    }
}
