#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, { 0, 0 }));
    for (int i = 1; i < m; ++i){
        if (city_map[i][0] == 1)
            break;
        dp[i][0].first = 1;
    }
        
    for (int i = 1; i < n; ++i){
        if (city_map[0][i] == 1)
            break;
        dp[0][i].second = 1;
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(city_map[i-1][j] == 0){
                dp[i][j].first = (dp[i-1][j].first + dp[i-1][j].second) % 20170805;
            }
            if(city_map[i-1][j] == 2){
                dp[i][j].first = dp[i-1][j].first;
            }
            if(city_map[i-1][j] == 1){
                dp[i][j].first = 0;
            }
            if(city_map[i][j-1] == 0){
                dp[i][j].second = (dp[i][j-1].first + dp[i][j-1].second) % 20170805;
            }
            if(city_map[i][j-1] == 2){
                dp[i][j].second = dp[i][j-1].second;
            }
            if(city_map[i][j-1] == 1){
                dp[i][j].second = 0;
            }
            
        }
    }
    answer = (dp[m-1][n-1].first + dp[m-1][n-1].second) % 20170805;
    return answer;
}
