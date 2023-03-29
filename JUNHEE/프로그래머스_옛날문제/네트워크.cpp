#include <string>
#include <vector>

using namespace std;

int answer = 0;

bool is_visit[200] = {false, };

void dfs(vector<vector<int>> computers, int curr, int n) {
    is_visit[curr] = true;
    
    for(int i = 0; i < n; i++){
        if(computers[curr][i] == 1 && !is_visit[i]){
            dfs(computers, i, n);
        }
    }
    
}
int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < n; i++){
        if(!is_visit[i]){
            dfs(computers, i, n);
            answer++;
        }
    }
    return answer;
}
