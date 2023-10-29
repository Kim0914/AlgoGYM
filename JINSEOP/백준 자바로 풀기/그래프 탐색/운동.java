import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int INF = 100000000;
    public static class Pair implements Comparable<Pair>{
        private int to;
        private int cost;

        public Pair(int to, int cost){
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair o){
            return cost - o.cost;
        }
    }

    public static void initSpanningTree(int[][] rmap){
        for(int i = 0; i < rmap.length; i++) {
            for (int j = 0; j < rmap.length; j++) {
                if(i == j) continue; // 자기 자신인 경우 제외
                rmap[i][j] = INF;
            }
        }
    }

    public static void floydWarshall(int[][] rmap, int vertex){
        for(int k = 1; k <= vertex; k++) {
            for (int i = 1; i <= vertex; i++) {
                for (int j = 1; j <= vertex; j++) {
                    if(i == j) continue;
                    rmap[i][j] = Math.min(rmap[i][j], rmap[i][k] + rmap[k][j]);
                }
            }
        }
    }

    public static int findMinimumCycle(int[][] rmap){
        int answer = INF;

        for(int i = 0; i < rmap.length; i++) {
            for (int j = 0; j < rmap.length; j++) {
                if(i == j) continue;
                answer = Math.min(answer, rmap[i][j] + rmap[j][i]);
            }
        }

        if(answer == INF)
            return -1;
        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        int vertex = Integer.parseInt(st1.nextToken());
        int edge = Integer.parseInt(st1.nextToken());

        int[][] runningMap = new int[vertex + 1][vertex + 1];
        initSpanningTree(runningMap);

        for(int i = 0; i < edge; i++){
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st2.nextToken());
            int to = Integer.parseInt(st2.nextToken());
            int cost = Integer.parseInt(st2.nextToken());

            runningMap[from][to] = cost; // 달리기 맵 처음 정보 저장
        }

        floydWarshall(runningMap, vertex);
        System.out.print(findMinimumCycle(runningMap));
    }
}
