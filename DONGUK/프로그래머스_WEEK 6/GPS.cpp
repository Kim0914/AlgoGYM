#include <vector>
#include <iostream>

#define INF 2e9

using namespace std;

int min(int A, int B){
    if (A < B) return A;
    else return B;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    vector<int> node[201];
    vector<vector<int>> dp(k, vector<int>(n+1, INF));
    
    for(int i=0; i < edge_list.size(); i++){
        int start = edge_list[i][0];
        int end = edge_list[i][1];
        node[start].push_back(end);
        node[end].push_back(start);
        
    }
    
    // 출발지 고정
    // dp[i][cur] = c -> i번째 노드를 cur로 설정할 때
    dp[0][gps_log[0]] = 0;
    for(int i=1; i<k; i++){
        for(int cur=1; cur <=n; cur++){ 
            if(dp[i-1][cur] == INF){ // i-1이 j와 연결 안되있으면 -> No
                continue;
            }
            
            for(int j=0; j < node[cur].size(); j++){
                int next = node[cur][j];
                int alpha = 0;
                
                if(gps_log[i] != next){
                    alpha++;
                }
                dp[i][next] = min(dp[i][next], dp[i-1][cur] + alpha); 
            }
        }
    }
    
    if (dp[k-1][gps_log[k-1]] < INF){
        answer = dp[k-1][gps_log[k-1]];
    }
                       
    else answer = -1;
                         
    return answer;
}