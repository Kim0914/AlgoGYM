import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static class Tuple{
        private int from;
        private int to;
        private long cost;

        public Tuple(int from, int to, long cost){
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    public static void initDistance(long[] dist, int vertex){
        for(int i = 1; i <= vertex; i++)
            dist[i] = Long.MAX_VALUE;
        // 시작 시, 거리 배열을 모두 무한대로 초기화
        dist[1] = 0; // 1번 도시에서 시작하므로 본인은 0
    }

    public static void bellmanFord(long[] dist, ArrayList<Tuple> edges, int vertex) {
        for(int i = 0; i <= vertex - 1; i++){
          // 정점의 수 - 1만큼 반복을 해야 한다.
          // 왜? 벨만 포드는 그리디가 아닌, DP 처럼 동작하며 모든 정점을 탐색한다.
          // 
            for(int j = 0; j < edges.size(); j++){
                int from = edges.get(j).from;
                int to = edges.get(j).to;
                long cost = edges.get(j).cost;

                if(dist[from] == Long.MAX_VALUE)
                    continue;
                // 갱신되지 않은 정점은 계산에 포함하지 않는다.
                // 왜? 갱신되지 않은 정점은 갈 수 없는 정점이기 때문에, 계산에 포함해선 안된다.
                if(dist[to] > dist[from] + cost)
                    dist[to] = dist[from] + cost;
                // 현재 저장된 거리보다 새로 이은 길의 거리가 더 짧으면?
                // 거리를 갱신한다.
            }
        }
    }

    public static boolean checkNegativeCycle(long[] dist, ArrayList<Tuple> edges){
        for(int i = 0; i < edges.size(); i++){
            int from = edges.get(i).from;
            int to = edges.get(i).to;
            long cost = edges.get(i).cost;

            if(dist[from] == Long.MAX_VALUE)
                continue;
            if(dist[to] > dist[from] + cost)
                return false;
          // N-1 회의 반복을 했는데도 정점이 갱신이 된다면?
          // 음의 사이클이 존재하여 문제가 발생했다는 것!
          // 무한루프가 돌게 될 여지가 있으므로 탐색을 중단한다.
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] vertexAndEdge = br.readLine().split(" ");
        int vertex = Integer.parseInt(vertexAndEdge[0]);
        int edge = Integer.parseInt(vertexAndEdge[1]);

        ArrayList<Tuple> edges = new ArrayList<>();
        for(int i = 0; i < edge; i++) {
            String[] edgeInfo = br.readLine().split(" ");

            int from = Integer.parseInt(edgeInfo[0]);
            int to = Integer.parseInt(edgeInfo[1]);
            long cost = Long.parseLong(edgeInfo[2]);

            edges.add(new Tuple(from, to, cost));
        }

        long[] dist = new long[501];
        // 거리 배열
        initDistance(dist, vertex);
        bellmanFord(dist, edges, vertex);

        if(!checkNegativeCycle(dist, edges))
            System.out.println(-1);
        // 사이클을 검사하여 사이클이 없으면 정답을 출력한다.
        else{
            for(int i = 2; i <= vertex; i++){
                if(dist[i] == Long.MAX_VALUE)
                    System.out.println(-1);
                else
                    System.out.println(dist[i]);
            }
        }
    }
}
