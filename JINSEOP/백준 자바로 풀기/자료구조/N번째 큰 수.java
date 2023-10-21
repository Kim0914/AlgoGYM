import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());

        int[][] board = new int[num][num];
        PriorityQueue<Integer> counterQueue = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < num; i++) {
            String[] valueStream = br.readLine().split(" ");
            for(int j = 0; j < num; j++) {
                board[i][j] = Integer.parseInt(valueStream[j]);
                counterQueue.add(board[i][j]);
            }
        }

        int counter = 1;
        while(counter < num){
            counterQueue.poll();
            counter++;
        }

        System.out.print(counterQueue.peek());
    }
}
