#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int info[101][101] = {0, };
    
    for(int i = 0; i<results.size(); i++) info[results[i][0]][results[i][1]] = 1;
    
    for(int i = 1; i<=n; i++){ // Floyid-Warshall?
        for(int j = 1; j<=n; j++){
            for(int k =1; k<=n; k++){
                if(info[j][i] == 1 && info[i][k]) info[j][k] = 1;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        int can_calc = 0;
        for(int j = 1; j<=n; j++) can_calc += (info[j][i] + info[i][j]);
        if(can_calc == n-1) answer++;
    }
    
    return answer;
}

// Floyid-Warshall Algorithm 공부할 것.
