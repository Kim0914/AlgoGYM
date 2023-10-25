import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static ArrayList<ArrayList<Integer>> completeBinaryTree = new ArrayList<>();
    public static void binarySearch(int limit, int[] inorderedNodes, int depth, int left, int right){
        int mid = (left + right) / 2;
        completeBinaryTree.get(depth).add(inorderedNodes[mid]);

        if(limit - 1 == depth)
            return;

        binarySearch(limit, inorderedNodes, depth + 1, left, mid - 1);
        binarySearch(limit, inorderedNodes, depth + 1, mid+1, right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int level = Integer.parseInt(br.readLine());
        int nodeCount = (int)Math.pow(2, level) - 1;
        String[] inputNodes = br.readLine().split(" ");
        int[] inorderedNodes = new int[nodeCount];

        for(int i = 0; i < nodeCount; i++)
            inorderedNodes[i] = Integer.parseInt(inputNodes[i]);
        for(int i = 0; i < level; i++)
            completeBinaryTree.add(new ArrayList<>());

        binarySearch(level, inorderedNodes, 0, 0, nodeCount - 1);

        for(int i = 0; i < level; i++) {
            for (int j = 0; j < completeBinaryTree.get(i).size(); j++)
                System.out.print(completeBinaryTree.get(i).get(j) + " ");
            System.out.println();
        }
    }
}
