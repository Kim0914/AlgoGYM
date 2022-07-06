import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for(String[] cloth : clothes){
            String type = cloth[1];
            
            if (map.containsKey(type)){
                map.put(type, map.get(type)+1);
            }
            else{
                map.put(type, 1);
            }
        }
        
        for(Map.Entry<String, Integer> e : map.entrySet()){
			answer = answer * (e.getValue() + 1);
        }
        
        answer -= 1;

        return answer;
    }
}