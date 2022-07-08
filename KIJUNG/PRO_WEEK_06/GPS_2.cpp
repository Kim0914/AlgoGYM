#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = -1
    int dp[101][201];
    vector<int> edge_list2[201];
    
    fill(&dp[0][0], &dp[100][201], 10000);

    for(vector<int> edge: edge_list){
        edge_list2[edge[0]].push_back(edge[1]);
        edge_list2[edge[1]].push_back(edge[0]);
    }

    dp[0][gps_log[0]] = 0;

    for(int i=0;i<k-1;i++){
        for(int j=1;j<n+1;j++){
            if(dp[i][j] != 10000){
                for(int node: edge_list2[j]){
                    if(gps_log[i+1] == node) dp[i+1][node] = min(dp[i][j], dp[i+1][node]);
                    else dp[i+1][node] = min(dp[i][j]+1, dp[i+1][node]);
                }
            }
        }
    }

    if(dp[k-1][gps_log[k-1]]!=10000) answer = dp[k-1][gps_log[k-1]];

    return answer;
}