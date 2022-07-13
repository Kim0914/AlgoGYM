#include <string>
#include <vector>

#define div 1000000007;

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101];
    int dp[101][101];
    fill(&map[0][0], &map[100][101], 0);
    fill(&dp[0][0], &dp[100][101], 0);

    for(vector<int> puddle: puddles){
        map[puddle[0]][puddle[1]] = 1;
    }
    
    dp[0][1]=1;
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(map[i][j] == 1) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%div;
        }
    }
    
    return dp[m][n];
}