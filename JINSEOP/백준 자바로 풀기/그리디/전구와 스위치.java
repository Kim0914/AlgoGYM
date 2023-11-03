import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static int answer = 999999999;
    public static int counter = 0;
    public static void flipBulb(String[] temp, int targetIndex) {
        temp[targetIndex - 1] = (temp[targetIndex - 1].equals("0")) ? "1" : "0";
        temp[targetIndex] = (temp[targetIndex].equals("0")) ? "1" : "0";
        if (targetIndex < temp.length - 1)
            temp[targetIndex + 1] = (temp[targetIndex + 1].equals("0")) ? "1" : "0";
    }

    public static void matchBulb(boolean firstSwitch, String[] source, String[] target){
        String[] temp = Arrays.copyOf(source, source.length);
        // 얕은 복사를 해야 source가 안바뀜
        // 왜? source는 call by reference로 넘어왔으니까.
        counter = 0;

        if(firstSwitch){
            temp[0] = (temp[0].equals("0")) ? "1" : "0";
            temp[1] = (temp[1].equals("0")) ? "1" : "0";
            counter++;
        }

        for(int i = 1; i < target.length; i++){
            if(!temp[i - 1].equals(target[i - 1])) {
              // 핵심은 현재 가리키고 있는 전구의 바로 이전 전구만 확인하면 된다는 점!
                flipBulb(temp, i);
                counter++;
            }
        }

        if(Arrays.equals(temp, target))
            answer = Math.min(counter, answer);
        // 똑같은 전구 모양을 만들 수 있는 경우 중, 최소를 정답으로 가져감
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        String[] source = br.readLine().split("");
        String[] target = br.readLine().split("");

        matchBulb(false, source, target);
        // 첫 스위치를 안누르는 경우
        matchBulb(true, source, target);
        // 첫 스위치를 누르는 경우

        if(answer == 999999999)
            System.out.println(-1);
          // 정답이 없다면 -1로
        else
            System.out.print(answer);
    }
}
