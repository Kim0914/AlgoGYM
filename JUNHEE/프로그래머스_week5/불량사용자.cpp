#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
set<string> ans_list;
bool visit[8] = {false, };

bool is_ban(string ban, string user){
    if(ban.size() != user.size()) return false;
    for(int i = 0; i < ban.size(); i++){
        if(ban[i] == '*') continue;
        else if(ban[i] != user[i]) return false;
    }
    return true;
}

void backtrack(vector<string> user_id, vector<string> banned_id,int index){
    if(banned_id.size() == index){
        string ans = "";
        for(int i = 0; i < user_id.size(); i++){
            if(visit[i] == true){
                ans += user_id[i];
            }
        }
        ans_list.insert(ans);
        return;
    }
    for(int i = 0; i < user_id.size(); i++){
        if(visit[i] == false && is_ban(banned_id[index],user_id[i])){
            visit[i] = true;
            backtrack(user_id, banned_id, index + 1);
            visit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    backtrack(user_id, banned_id, 0);
    answer = ans_list.size();
    return answer;
}
