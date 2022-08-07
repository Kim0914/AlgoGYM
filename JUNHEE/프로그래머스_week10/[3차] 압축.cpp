#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dic;

vector<int> solution(string msg) {
    vector<int> answer;
    for(int i = 0; i < 26; i++){
        char temp = 'A' + i;
        string t_st = "";
        t_st += temp;
        dic[t_st] = i + 1;
    }
    string t_msg = "";
    int idx = 27;
    for(int i = 0; i < msg.size();){
        t_msg += msg[i];
        if(dic[t_msg] == 0){
            dic[t_msg] = idx;
            idx++;
            t_msg.pop_back();
            answer.push_back(dic[t_msg]);
            t_msg = "";
        }
        else{
            i++;
        }
    }
    answer.push_back(dic[t_msg]);
    return answer;
}
