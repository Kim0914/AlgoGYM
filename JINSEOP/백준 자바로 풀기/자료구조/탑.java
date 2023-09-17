import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static class Pair{
        Integer height;
        Integer index;

        public Pair(Integer height, Integer index){
            this.height = height;
            this.index = index;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Pair> towerStack = new Stack<>();
        ArrayList<Integer> towerInfo = new ArrayList<>();
        ArrayList<Integer> answerList = new ArrayList<>();

        for(int i = 0; i < num; i++)
            towerInfo.add(Integer.parseInt(st.nextToken())); // 탑 높이 저장

        towerStack.push(new Pair(towerInfo.get(0), 0));
        answerList.add(0); // 시작 탑은 반드시 0
        for(int i = 1; i < num; i++){
            while(!towerStack.isEmpty() && towerStack.peek().height <= towerInfo.get(i)){
                towerStack.pop();
            } // 내 앞에 보이는 탑이 나보다 높을 때 까지 Pop

            if(!towerStack.isEmpty())
                answerList.add(towerStack.peek().index + 1);
            else
                answerList.add(0);

            towerStack.push(new Pair(towerInfo.get(i), i)); // 스택에 푸쉬
        }

        for(Integer i : answerList)
            System.out.print(i + " ");
    }
}
