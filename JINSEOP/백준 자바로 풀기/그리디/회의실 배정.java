import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static class Pair{
        Integer x;
        Integer y;

        public Pair(Integer x, Integer y){
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Pair> rooms = new ArrayList<>();
        Integer answer = 1; // 회의는 무조건 하나 넣고 시작
        Integer num = sc.nextInt();
        for(int i = 0; i < num; i++){
            Integer start = sc.nextInt();
            Integer end = sc.nextInt();
            rooms.add(new Pair(start, end));
        }

        rooms.sort((o1, o2) -> { // Java의 정렬 customizing
            if(o1.y.equals(o2.y)) // 끝나는 시간
                return o1.x - o2.x; // 시작 시간
            return o1.y - o2.y; // 빨리 끝나는 회의 부터 정렬
        });

        Integer curr = rooms.get(0).y; // 가장 빨리 끝나는 회의
        for(int i = 1; i < num; i++) {
            if(curr <= rooms.get(i).x) { // 겹치지 않는 회의면?
                answer++;
                curr = rooms.get(i).y; // 끝나는 시간 갱신
            }
        }

        System.out.print(answer);
    }
}
