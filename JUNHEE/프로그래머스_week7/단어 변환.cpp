#include <string>
#include <vector>
#include <iostream>

using namespace std;
int min_num = 51;
bool visit[50] = {false, };

bool can_fix(string cur, string next){
    int cnt = 0;
    if(cur.size() != next.size()) return false;
    for(int i = 0; i < cur.size(); i++){
        if(cur[i] != next[i]) cnt++;
        if(cnt > 1) return false;
    }
    return true;
}

void dfs(int depth, vector<string> words, string begin, string target){
    if(begin == target){
        if(min_num > depth) min_num = depth;
        return;
    }
    for(int i = 0; i < words.size(); i++){
        if(visit[i] == false && can_fix(begin, words[i])){
            visit[i] = true;
            dfs(depth + 1, words, words[i], target);
            visit[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool can_ans = false;
    for(int i = 0; i < words.size(); i++){
        if(target == words[i]){
            can_ans = true;
            break;
        } 
    }
    if(can_ans == false) return 0;
    dfs(0,words,begin,target);
    answer =  min_num;
    return answer;
}
