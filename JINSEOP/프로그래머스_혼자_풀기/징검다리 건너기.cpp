class Solution {
    public boolean check(int[] stones, int k, int mid) {
        int cnt = 0;

        for(int i = 0; i < stones.length; i++){
            if(stones[i] < mid){
            // 해당 돌이 현재 지나고자 하는 친구들의 수보다 작다면?
            // 해당 친구들은 해당 돌을 모두 밟을 수 없다.
                cnt++;
                if(cnt >= k)
            // 최대 k칸을 건너뛸 수 있는데, 못 건너는 돌이 k개 연속으로 나오면?
            // 이 강은 더 이상 건널 수 없는 강이다.
                    return false;
            }
            else
            // 하지만 다른 돌을 밟고 건널 수도 있으니 큰 경우엔 초기화
                cnt = 0;
        }

        return true;
    }
    
    public int solution(int[] stones, int k) {
        int answer = 0;
        int left = 0;
        int right = Integer.MAX_VALUE;

        while(left <= right){
        // 효율성 검사를 통과하기 위해 이분탐색 진행
            int mid = (left + right) / 2;
            if(check(stones, k, mid)){
        // 건널 수 있는 수의 친구 수면 더 늘려보자
                left = mid + 1;
                answer = mid;
            }
        // 건널 수 없는 수의 친구 수면 더 줄여보자
            else
                right = mid - 1;
        }
        
        return answer;
    }
}
