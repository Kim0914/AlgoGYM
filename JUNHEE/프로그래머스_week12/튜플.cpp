#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size(); 
}
bool is_in(vector<int>& tuple, int num){
    for(auto target : tuple){
        if(target == num) return false;
    }
    return true;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuple;
    bool flag = false;
    vector<int> temp;
    string t_num = "";
    for(int i = 1; i < s.size()-1; i++){
        if(flag){
            if('0' <= s[i]  && s[i] <= '9'){
                t_num += s[i];
            }
            if(s[i] == ','){
            temp.push_back(stoi(t_num));
            t_num = "";
            }
        }
        if(s[i] == '{'){
            flag = true;
        } 
        if(s[i] == '}'){
            temp.push_back(stoi(t_num));
            tuple.push_back(temp);
            temp.clear();
            t_num = "";
            flag = false;
        }
        
    }
    
    sort(tuple.begin(), tuple.end(), cmp);
    
    for(int i = 0; i < tuple.size(); i++){
        for(int j = 0; j < tuple[i].size(); j++){
            if(is_in(answer, tuple[i][j])){
                answer.push_back(tuple[i][j]);
            }
        }
    }
    
    
    return answer;
}
