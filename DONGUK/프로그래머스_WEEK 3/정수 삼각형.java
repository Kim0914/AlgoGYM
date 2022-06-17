class Solution {
    public int solution(int[][] triangle) {
        
        int[][] dp = new int[triangle.length][];
        
        for(int i=0; i<triangle.length; i++){
            dp[i] = new int[triangle[i].length];
        }
        
        dp[0][0] = triangle[0][0];
        for(int i=1; i<triangle.length; i++){
            for(int j=0; j<triangle[i].length; j++){
                if(j==0 || j == triangle[i].length-1){
                    if (j == 0){
                        dp[i][j] = triangle[i][j] + dp[i-1][j];
                    }
                    else{
                        dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                    }
                }
                
                else{
                    dp[i][j] = triangle[i][j] + Math.max(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        
        int answer = 0;
        int N = triangle.length;
        for(int i=0; i<dp[N-1].length; i++){
            answer = Math.max(answer, dp[N-1][i]);
        }
        
        return answer;
    }
}