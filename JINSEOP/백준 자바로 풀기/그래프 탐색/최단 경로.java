import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {
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

    public static int[] dist = new int[20001]; // 거리 배열
    public static ArrayList<Pair>[] edges = new ArrayList[20001]; // 간선 정보 저장
    private static final int INF = Integer.MAX_VALUE;

    public static void initDistance(int vertex){
        for(int i = 1; i <= vertex; i++)
            dist[i] = INF; // 거리 배열 초기화
    }

    public static void initEdgeInfo(int vertex){
        for(int i = 1; i <= vertex; i++)
            edges[i] = new ArrayList<>();
        // 간선 정보를 저장할 배열을 초기화 한다. (인접 리스트)
        // Cpp와 다르게 자바는 이런 과정이 추가적으로 필요함
    }

    public static void dijkstra(int startVertex){
        PriorityQueue<Pair> dijkstraHeap = new PriorityQueue<>();

        dijkstraHeap.add(new Pair(startVertex, 0));
        dist[startVertex] = 0;
        // 시작점을 우선순위 큐에 넣고, 거리를 초기화한다.
        while(!dijkstraHeap.isEmpty()){
            Pair curr = dijkstraHeap.poll();
            // peek는 값을 반환, poll은 반환 후 pop까지
            int currNode = curr.to;
            int currCost = curr.cost;
            // 현재 위치하고 있는 노드와 연결된 목적지와 비용
          
            if(currCost > dist[currNode])
                continue;
            // 현재 노드부터 목적지까지의 거리보다 출발지부터 목적지까지가 더 가깝다면?
            // 탐색을 할 필요가 없다.

            for(int i = 0; i < edges[currNode].size(); i++){
            // 현재 노드에 연결된 다음 노드들을 탐색한다.
                int nextCost = dist[currNode] + edges[currNode].get(i).cost;
              
                // 현재 노드까지의 거리 + 다음 노드까지의 거리가 더 가깝다면?
                if(dist[edges[currNode].get(i).to] > nextCost){
                    // 갱신을 진행하도록 한다.
                    dist[edges[currNode].get(i).to] = nextCost;
                    dijkstraHeap.add(new Pair(edges[currNode].get(i).to, nextCost));
                    // 해당 노드는 아직 방문하지 않은 노드이므로, 삽입하고 다음 노드를 탐색한다.
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] vertexAndEdge = br.readLine().split(" ");
        int vertex = Integer.parseInt(vertexAndEdge[0]);
        int edge = Integer.parseInt(vertexAndEdge[1]);
        int startVertex = Integer.parseInt(br.readLine());

        initDistance(vertex); // 거리 벡터 초기화
        initEdgeInfo(vertex); // 간선 받을 벡터 초기화

        for(int i = 0; i < edge; i++) {
            String[] edgeInfo = br.readLine().split(" ");

            int from = Integer.parseInt(edgeInfo[0]);
            int to = Integer.parseInt(edgeInfo[1]);
            int cost = Integer.parseInt(edgeInfo[2]);

            edges[from].add(new Pair(to, cost));
            // 간선 정보 인접리스트에 생성
        }

        dijkstra(startVertex);
        
        for(int i = 1; i <= vertex; i++){
            if(dist[i] == INF)
                System.out.println("INF");
            else
                System.out.println(dist[i]);
        }
    }
}
