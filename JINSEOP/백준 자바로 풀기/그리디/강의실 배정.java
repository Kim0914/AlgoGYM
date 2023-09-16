import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static class Pair implements Comparable<Pair>{
        Integer startTime;
        Integer endTime;

        public Pair(int x, int y){
            this.startTime = x;
            this.endTime = y;
        }

        @Override
        public int compareTo(Pair pair) {
            if(pair.startTime == this.startTime)
                return Integer.compare(this.endTime, pair.endTime);
            return Integer.compare(this.startTime, pair.startTime);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Pair> classList = new ArrayList<>();
        PriorityQueue<Integer> classQueue = new PriorityQueue<>();

        int num = sc.nextInt();
        for(int i = 0; i < num; i++)
            classList.add(new Pair(sc.nextInt(), sc.nextInt()));
        Collections.sort(classList);

        classQueue.add(classList.get(0).endTime);
        for(int i = 1; i < num; i++){
            classQueue.add(classList.get(i).endTime);
            if(classQueue.peek() <= classList.get(i).startTime)
                classQueue.remove();
        }

        System.out.print(classQueue.size());
    }
}
