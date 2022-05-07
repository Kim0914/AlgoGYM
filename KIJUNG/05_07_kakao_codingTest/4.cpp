#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

bool visited[50000];
vector<pair<int,int>> edge[50000];
vector<int> answer;

void dfs(int start, int end, int intensity){
    if(start == end){
        if(answer[1] > intensity){
            answer[1] = intensity;
            answer[0] = end;
        }
        else if(answer[1] == intensity){
            answer[0] = min(answer[0])
        }
    }
    FOR(i,0,edge[start].size()){

    }
}

void possible(int gate, int summit){
    dfs(gate,summit);
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    FOR(i,0,gates.size()){
        visited[gates[i]] = true;
    }

    FOR(i,0,paths.size()){
        edge[paths[i][0]].first = paths[i][1];
        edge[paths[i][0]].second = paths[i][2];
        edge[paths[i][1]].first = paths[i][0];
        edge[paths[i][1]].second = paths[i][2];
    }

    answer.push_back(50001);
    answer.push_back(10000001);

    //가능한 경우
    FOR(i,0,gates.size()){
        FOR(j,0,summits.size()){
            possible(gates[i], summmits[i]);
        }
    }
}   
//산봉우리, 최소 intensity