import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    static ArrayList<Integer> answer;
    static boolean[] visit;
    static int[] seq;

    public static void clearVisit(int num){
        for(int i = 0; i <= num; i++)
            visit[i] = false;
    }
    public static void dfs(int start, int curr){
        if(visit[curr]){ // 이미 방문했던 노드에 왔다.
            if(curr == start){ // 시작점과 같으면 싸이클이 생겼다!
                answer.add(curr);
            }
        }
        else{ // 방문한 적이 없으면 계속 파고 들어감
            visit[curr] = true;
            dfs(start, seq[curr]);
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        seq = new int[num + 1];
        visit = new boolean[num + 1];
        answer = new ArrayList<>();
        for(int i = 1; i <= num; i++)
            seq[i] = sc.nextInt(); // 수열 입력 받기

        for(int i = 1; i <= num; i++) {
            clearVisit(num);
            dfs(i, i); // 사이클이 존재하는지 찾으면 된다.
        }

        System.out.println(answer.size());
        for(Integer i : answer)
            System.out.println(i);
        // 정렬 할 필요가 없음.
        // 왜? 앞에서 부터 싸이클이 생기는 노드를 훑었으니까.
    }
}
