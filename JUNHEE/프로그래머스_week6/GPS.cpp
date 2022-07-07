#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> graph(201);

// DP를 사용해야하는 문제였다.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    const int INF = 999999999;          // 절대 답이 될 수 없는 큰 수로 answer를 지정해준다.
    int answer = INF;
    vector<vector<int>> graph(201);
    int dp[100][201];
    for(int i = 0; i < 100; i++){       // DP graph를 큰 수로 초기화해준다.
        for(int j = 0; j < 201; j++){
            dp[i][j] = INF;
        }
    }
    
    for(auto i : edge_list){            // 간선 리스트 제작
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    
    dp[0][gps_log[0]] = 0;              // 시작점에서는 아무것도 수정하지 않기 때문에 0으로 초기화
    for(int i = 1; i < k; i++){
        for(int j = 1; j < n+1; j++){
            int add = 1;                    // 만약 gps_log와 현재 시간에 있는 정점이 같으면 수정하지 않아도 되니까 0,
            if(gps_log[i] == j) add = 0;    // 다르면 이전 정점에서부터 수정을 해야하니까 1을 더해줄 것이다
            dp[i][j] = min(dp[i][j], dp[i-1][j] + add); // 이전시간부터 현재시간까지 택시가 그 자리에 멈춰있는 경우를 고려하는 부분이다.
            
            for(int z = 0; z < graph[j].size(); z++){
                dp[i][j] = min(dp[i][j], dp[i-1][graph[j][z]] + add);  
              // 택시가 이동을 해서 이전시간과는 위치가 달라진 경우이다. 이 경우는 현재 위치로 올 수 있는 모든 정점을 고려해주었다.
              // 현재 정점이 [3]이고, [3]에 연결되어있는 정점이 [1,2]이면, 3으로 올 수 있는 경우는 이전 시간의 1 지점과 2 지점에서밖에 올 수 없다.
              
            }
        }
    }
    int dest = gps_log.back();
    if(dp[k-1][dest] == INF) return -1; // 도착점이 수정되지 않았으면, 어떻게 고쳐도 도달할 수 없는 경우이기 때문에 -1을 return
    else return dp[k-1][dest];          // 도착점이 수정되었으면, 도착점까지 걸린 최소 수정 횟수를 return해준다.
}
