#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> winEdge[101];
vector<int> loseEdge[101];
int check[101][101];

void loserDFS(int target, int cur){
    if(check[target][cur] != 0) return;
    check[target][cur] = 1;
    for(int node: loseEdge[cur]){
        loserDFS(target,node);
    }
}

void winnerDFS(int target, int cur){
    if(check[target][cur] != 0) return;
    check[target][cur] = 1;
    for(int node: winEdge[cur]){
        winnerDFS(target,node);
    }
}

bool valid(int person, int n){
    for(int j=1;j<n+1;j++){
        if(check[person][j] == 0) return false;
    }
    return true;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(vector<int> result: results){
        winEdge[result[1]].push_back(result[0]);
        loseEdge[result[0]].push_back(result[1]);
    }

    for(int i = 1;i<n+1;i++){
        loserDFS(i,i);
        check[i][i] = 0;
        winnerDFS(i,i);
    }

    for(int i=1;i<n+1;i++){
        if(valid(i,n)) answer++;
    }

    return answer;
}