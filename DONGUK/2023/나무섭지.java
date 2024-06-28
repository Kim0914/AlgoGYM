import java.io.*;
import java.util.*;

public class Main {

    // 유령이 탈출하는데 걸리는 시간과 남우가 탈출하는데 걸리는 시간 비교
    // 남우는 유령보다 무조건 빨리 탈출해야 함

    private static final int[] dx = {1, -1, 0, 0};
    private static final int[] dy = {0, 0, 1, -1};

    private static int moveNamwoo(String[][] graph, Position namwoo) {
        int n = graph.length;
        int m = graph[0].length;
        
        PriorityQueue<Position> pq = new PriorityQueue<>();
        pq.add(namwoo);
        
        boolean[][] visited = new boolean[n][m];
        visited[namwoo.x][namwoo.y] = true;
        
        while (!pq.isEmpty()) {
            Position top = pq.poll();

            if (isExit(graph, top)) {
                return top.time;
            }

            for (int i = 0; i < 4; i++) {
                int nx = top.x + dx[i];
                int ny = top.y + dy[i];
                
                if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visited[nx][ny]) {
                    if (graph[nx][ny].equals(".") || graph[nx][ny].equals("D")) {
                        
                        Position nextPosition = new Position(nx, ny, top.time + 1);
                        visited[nx][ny] = true;
                        pq.add(nextPosition);
                    }
                }
             }

        }
        return -1;
    }

    private static int moveGhost(String[][] graph, Position ghost) {
        if (ghost == null) {
            return Integer.MAX_VALUE;
        }
        int n = graph.length;
        int m = graph[0].length;
        
        PriorityQueue<Position> pq = new PriorityQueue<>();
        pq.add(ghost);
        
        boolean[][] visited = new boolean[n][m];
        visited[ghost.x][ghost.y] = true;
        
        while (!pq.isEmpty()) {
            Position top = pq.poll();

            if (isExit(graph, top)) {
                return top.time;
            }

            for (int i = 0; i < 4; i++) {
                int nx = top.x + dx[i];
                int ny = top.y + dy[i];
                
                if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visited[nx][ny]) {
                    Position nextPosition = new Position(nx, ny, top.time + 1);
                    visited[nx][ny] = true;
                    pq.add(nextPosition);
                }
             }

        }
        return Integer.MAX_VALUE;
    }

    private static Position findNearestGhost(List<Position> ghosts, Position exit) {
        Position nearestGhost = null;
        int distance = Integer.MAX_VALUE;
        for (Position ghost : ghosts) {
            int curDistance = Math.abs(exit.x - ghost.x) + Math.abs(exit.y - ghost.y);

            if (curDistance < distance) {
                nearestGhost = ghost;
                distance = curDistance;
            }
        }
        return nearestGhost;
    }

    private static boolean isExit(String[][] graph, Position position) {
        return graph[position.x][position.y].equals("D");
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        String[][] graph = new String[n][m];

        Position namwoo = null;
        Position exit = null;
        List<Position> ghosts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                String value = String.valueOf(row.charAt(j));
                if (value.equals("G")) {
                    ghosts.add(new Position(i, j, 0));
                }

                if (value.equals("N")) {
                    namwoo = new Position(i, j, 0);
                }

                if (value.equals("D")) {
                    exit = new Position(i, j, 0);
                }
                graph[i][j] = value;
            }
        }

        Position nearestGhost = findNearestGhost(ghosts, exit);

        int namWooTime = moveNamwoo(graph, namwoo);
        int ghostTime = moveGhost(graph, nearestGhost);

        if (namWooTime == -1) {
            bw.write("No");
        } else {
            if (namWooTime < ghostTime) {
                bw.write("Yes");
            } else {
                bw.write("No");
            }
        }
        bw.flush();
    }

    static class Position implements Comparable<Position> {
        public int x;
        public int y;
        public int time;

        public Position (int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }

        public int compareTo(Position position) {
            return this.time - position.time;
        }
    }
}
