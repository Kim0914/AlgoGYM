#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[8] = {false , };
int max_d = 0;
void quest(int depth, int fatigue, vector<vector<int>> dungeons){
    if(depth > max_d){
        max_d = depth;
    }
    for(int i = 0; i < dungeons.size(); i++){
        if(visit[i] == false && fatigue >= dungeons[i][0]){
            visit[i] = true;
            quest(depth + 1, fatigue - dungeons[i][1], dungeons);
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    quest(0, k, dungeons);
    answer =  max_d;
    return answer;
}
