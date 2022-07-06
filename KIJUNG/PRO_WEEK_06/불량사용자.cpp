#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[8];
vector<vector<int> > lists;
vector<vector<int> > possible_id;
vector<int> tmp;

bool check(string b, string u){
    for(int i=0;i<b.size();i++){
        if(b[i] != u[i] && b[i] != '*') return false;
    }
    return true;
}

void dfs(int cur){
    if(lists.size() == cur && tmp.size() == lists.size()) {
        possible_id.push_back(tmp);
        return;
    }
    for(int i: lists[cur]){
        if(visited[i] == 1) continue;
        visited[i] = 1;
        tmp.push_back(i);
        dfs(cur+1);
        visited[i] = 0;
        tmp.pop_back();
    }
}

bool isSame(vector<int> a, vector<int> b){
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    for(int i=0;i<banned_id.size();i++){
        vector<int> list;
        for(int j=0;j<user_id.size();j++){
            if(banned_id[i].size() == user_id[j].size() && check(banned_id[i], user_id[j])) list.push_back(j);
        }
        if(list.empty()) return 0;
        lists.push_back(list);
    }

    dfs(0);
    answer = possible_id.size();
    for(int i=0;i<possible_id.size();i++) sort(possible_id[i].begin(), possible_id[i].end());
    sort(possible_id.begin(), possible_id.end());
    if(possible_id.size()>1){
        for(int i=0;i<possible_id.size()-1;i++){
            if(isSame(possible_id[i], possible_id[i+1])) answer--;
        }
    }
    
    return answer;
}