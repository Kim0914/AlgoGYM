import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static class Pair{
        Integer x;
        Integer y;

        public Pair(Integer x, Integer y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt(); // 지름길 수
        int highwayDist = sc.nextInt(); // 고속도로 길이
        ArrayList<ArrayList<Pair>> shortcutInfo = new ArrayList<>();
        for(int i = 0; i < 10001; i++)
            shortcutInfo.add(new ArrayList<Pair>());
        // 이렇게 2차원 배열을 초기화 할 수 있다.
        int[] roadInfo = new int[10001];

        for(int i = 0; i < num; i++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            int cost = sc.nextInt();

            shortcutInfo.get(end).add(new Pair(start, cost));
        }

        roadInfo[0] = 0; // 시작 지점
        for(int i = 1; i <= highwayDist; i++){ // 여기서 이제 거리 탐색
            roadInfo[i] = roadInfo[i-1] + 1;
            // 기본적으로 지름길이 없을 시 이전 위치 + 1
            for(int j = 0; j < shortcutInfo.get(i).size(); j++)
                roadInfo[i] = Math.min(roadInfo[i],
                        roadInfo[shortcutInfo.get(i).get(j).x] + shortcutInfo.get(i).get(j).y);
                // 지름길의 시작점 거리 + 지름길을 지나는 거리
        } // DP로 해결가능

        System.out.println(roadInfo[highwayDist]);
    }
}
