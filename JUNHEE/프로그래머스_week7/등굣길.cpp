#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int map[101][101] = {0, };
    map[1][1] = 1;
    
    for(auto i : puddles){
        map[i[1]][i[0]] = -1;
    }
    
    for(int i=1; i<n + 1;i++){
        for(int j=1; j< m + 1; j++){
            if(map[i][j]==-1)
                continue;
            if(map[i-1][j]!=-1 && map[i][j-1]!=-1){
                map[i][j] += (map[i-1][j] + map[i][j-1])%1000000007;
            }
            else if(map[i-1][j]!=-1)
                map[i][j] += map[i-1][j]%1000000007;
            else if(map[i][j-1]!=-1)
                map[i][j]= map[i][j-1]%1000000007;
        }
    }
    answer = map[n][m];
    return answer;
}
