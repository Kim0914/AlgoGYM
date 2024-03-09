import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static ArrayList<Long> seq = new ArrayList<>();
    static ArrayList<Long> lisList = new ArrayList<>();

    public static int binarySearch(int left, int right, Long target){
        while (left < right) {
            int mid = (left + right) / 2;

            if (lisList.get(mid) < target)
                left = mid + 1;
            else
                right = mid;
        }

        return right;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Long num = Long.parseLong(br.readLine());

        String[] seqString = br.readLine().split(" ");
        for(int i = 0; i < num; i++)
            seq.add(Long.parseLong(seqString[i]));

        lisList.add(seq.get(0));
        for(int i = 1; i < num; i++){
            Long currBack = lisList.get(lisList.size() - 1);
            Long currTarget = seq.get(i);

            if(currBack < currTarget)
                lisList.add(currTarget);
            else
                lisList.set(binarySearch(0, lisList.size(), currTarget), currTarget);
        }

        System.out.print(lisList.size());
    }
}
