import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static String[] gears = new String[4];
    public static int[][] gearPointer = new int[3][4];
    // 각각 12시 3시 9시에 어느 칸이 오는지 저장
    public static boolean[] visit = new boolean[4];

    public static void clearVisit(){
        for(int i = 0; i < 4; i++)
            visit[i] = false;
    }
    public static void initPointer(){
        for(int i = 0; i < 4; i++){
            gearPointer[0][i] = 0; // 12시는 0번 칸
            gearPointer[1][i] = 2; // 3시는 2번 칸
            gearPointer[2][i] = 6; // 9시는 6번 칸
        }
    }

    public static int flipDirection(int rotateDir){
        return (rotateDir == 1) ? -1 : 1;
    }

    public static void rotateGear(int gearNum, int rotateDir){
        visit[gearNum] = true;

        if(gearNum - 1 >= 0) {
            if(!visit[gearNum - 1]) {
                if (gears[gearNum].charAt(gearPointer[2][gearNum]) != gears[gearNum - 1].charAt(gearPointer[1][gearNum - 1])) {
                    rotateGear(gearNum - 1, flipDirection(rotateDir));
                }
            }
        }
        if(gearNum + 1 < 4) {
            if(!visit[gearNum + 1]) {
                if (gears[gearNum].charAt(gearPointer[1][gearNum]) != gears[gearNum + 1].charAt(gearPointer[2][gearNum + 1])) {
                    // 현재 톱니바퀴의 2번, 다음 톱니바퀴의 6번 자리가 서로 다른 극이면 서로 반대 방향으로 돌려야 함
                    rotateGear(gearNum + 1, flipDirection(rotateDir));
                }
            }
        }

        // 검사를 다 마친 뒤, 마지막 톱니부터 돌리면서 처음 톱니로 가야함
        // 왜? 그래야 상태 검사가 가능함.
        if(rotateDir == 1){
            gearPointer[0][gearNum] = (gearPointer[0][gearNum] + 7) % 8;
            gearPointer[1][gearNum] = (gearPointer[1][gearNum] + 7) % 8;
            gearPointer[2][gearNum] = (gearPointer[2][gearNum] + 7) % 8;
            // 시계 방향으로 회전 시킴, 즉 12시, 3시, 9시 포인터가 한 칸씩 뒤로 밀림
        }
        else{
            gearPointer[0][gearNum] = (gearPointer[0][gearNum] + 1) % 8;
            gearPointer[1][gearNum] = (gearPointer[1][gearNum] + 1) % 8;
            gearPointer[2][gearNum] = (gearPointer[2][gearNum] + 1) % 8;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 4; i++) {
            String gearState = br.readLine();
            // 톱니바퀴를 입력받는다.
            // 맞닿는 부분은 3시 9시 즉, 3번 칸과 9번 인덱스
            gears[i] = gearState;
        }

        initPointer();
        int transitionNum = Integer.parseInt(br.readLine());
        for(int i = 0; i < transitionNum; i++){
            String[] inputState = br.readLine().split(" ");
            int gearNum = Integer.parseInt(inputState[0]) - 1;
            int rotateDir = Integer.parseInt(inputState[1]);

            // 회전 동작이 재귀적으로 돌아가야할 것 같은데?
            rotateGear(gearNum, rotateDir);
            clearVisit();
        }

        int answer = 0, partialPoint = 1;
        for(int i = 0; i < 4; i++){
            if(gears[i].charAt(gearPointer[0][i]) == '1')
                answer += partialPoint;
            // 12시 포인터가 가리키는 톱니의 극이 S이면 점수 추가
            partialPoint *= 2;
        }

        System.out.print(answer);
    }
}
