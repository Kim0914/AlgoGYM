#include <string>
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<vector<long long>>> dp(m+1, vector<vector<long long>>(n+1, vector<long long> (2)));

    for(int i = 0; i < m; i++) {
        if(city_map[i][0] == 1)
            break;
        dp[i][0][1] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(city_map[0][i] == 1)
            break;
        dp[0][i][0] = 1;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            
            if(city_map[i-1][j] == 0) {
                
                dp[i][j][1] += (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            }
            
            if(city_map[i-1][j] == 2) {
                dp[i][j][1] += (dp[i-1][j][1] % MOD);
            }
            if(city_map[i][j-1] == 0) {
                dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
            }
            if(city_map[i][j-1] == 2) {
                dp[i][j][0] += (dp[i][j-1][0] % MOD);
            }
        }
    }

    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;

    return answer;
}





// #include <vector>
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <string.h>

// using namespace std;

// int MOD = 20170805;
// int dp[501][501];
// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// int solution(int m, int n, vector<vector<int>> city_map) {
//     int answer = 0;
    
//     memset(dp, 0, sizeof(dp));
    
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    
//     q.push(make_pair(0, 0));
    
//     dp[0][0] = 1;
//     while (!q.empty()){
//         int x = q.top().first;
//         int y = q.top().second;
//         // cout << x << " " << y << endl;
//         q.pop();
        
//         if(x == m-1 and y == n-1) continue;
        
//         for(int i=0; i<4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
            
//             if((0 <= nx && nx < m) && (0 <= ny && ny < n)){
//                 if(dp[nx][ny] > 0 && city_map[nx][ny] != 1){
//                     dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MOD;
//                     continue;
//                 }
                
//                 if (city_map[nx][ny] == 0){
//                     dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MOD;
//                     q.push(make_pair(nx, ny));
//                 }
                
//                 else if(city_map[nx][ny] == 2){
//                     if ((nx - x == 0) && (ny - y == 1)){
//                         if(ny + 1 < n){
//                             q.push(make_pair(nx, ny+1));
//                             dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MOD;
//                             dp[nx][ny+1] = (dp[nx][ny+1] + dp[x][y]) % MOD;
//                         }    
//                     }
                    
//                     else if((nx - x == 1) && (ny - y == 0)){
//                         if(nx+1 < m){
//                             q.push(make_pair(nx+1, ny));
//                             dp[nx][ny] = (dp[nx][ny] + dp[x][y]) % MOD;
//                             dp[nx+1][ny] = (dp[nx+1][ny] + dp[x][y]) % MOD;
//                         }
//                     }
//                 }
//                 else continue;
//             }
//         }
//     }
    
//     answer = dp[m-1][n-1] % MOD;
        

//     return answer;
// }