import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class Tuple{
        int clipboard;
        int currImoji;
        int timer;

        public Tuple(int clipboard, int currImoji, int timer){
            this.clipboard = clipboard;
            this.currImoji = currImoji;
            this.timer = timer;
        }
    }
    public static Queue<Tuple> bfs_q = new LinkedList<>();
    public static boolean visit[][] = new boolean[2001][2001];
    public static int target = 0, answer = 0;

    public static void bfs(){
        bfs_q.add(new Tuple(0, 1, 0));
        // 클립보드, 현재 입력된 이모티콘, 지난 시간
        visit[1][0] = true;

        while(!bfs_q.isEmpty()){
            int currImoji = bfs_q.peek().currImoji;
            int clipboard = bfs_q.peek().clipboard;
            int timer = bfs_q.peek().timer;
            bfs_q.poll();

            if(currImoji == target){
              // 목표한 갯수의 이모티콘 갯수가 만들어지면 중지
                answer = timer;
                return;
            }

            if(currImoji > 0 && currImoji < 2000){
              // 현재 이모티콘이 최대 갯수를 넘어가는 경우엔 아래의 동작 수행 불가
                // 클립보드에 저장하는 경우
                if(!visit[currImoji][currImoji]){
                    bfs_q.add(new Tuple(currImoji, currImoji, timer + 1));
                    visit[currImoji][currImoji] = true;
                }
                // 이모티콘을 하나 삭제하는 경우
                if(!visit[currImoji - 1][clipboard]){
                    bfs_q.add(new Tuple(clipboard, currImoji - 1, timer + 1));
                    visit[currImoji - 1][clipboard] = true;
                }
            }
            // 클립보드에 저장된 것을 붙여넣는 경우
            if(currImoji + clipboard < 2000){
                if(!visit[currImoji + clipboard][clipboard]){
                    bfs_q.add(new Tuple(clipboard, currImoji + clipboard, timer + 1));
                    visit[currImoji + clipboard][clipboard] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        target = Integer.parseInt(br.readLine());

        // DP와 유사한 방식의 bfs였다.
        bfs();
        System.out.println(answer);
    }
}
