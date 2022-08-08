#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long max_play_time = 0;
    int max_play_time_idx = 0;
    int play_time_i = stoi(play_time.substr(0,2))*3600 + stoi(play_time.substr(3,2))*60 + stoi(play_time.substr(6,2));
    int adv_time_i = stoi(adv_time.substr(0,2))*3600 + stoi(adv_time.substr(3,2))*60 + stoi(adv_time.substr(6,2));
    vector<pair<int,int> > logs_i;
    for(string log: logs){
        pair<int,int> tmp;
        tmp.first = stoi(log.substr(0,2))*3600 + stoi(log.substr(3,2))*60 + stoi(log.substr(6,2));
        tmp.second = stoi(log.substr(9,2))*3600 + stoi(log.substr(12,2))*60 + stoi(log.substr(15,2));
        logs_i.push_back(tmp);
    }
    sort(logs_i.begin(), logs_i.end());

    for(int k=0;k<play_time_i-adv_time_i;k++){
        long long possible_time = 0;
        for(pair<int,int> log: logs_i){
            if(log.first>k+play_time_i) break;
            if(log.second<=k || log.first>=k+adv_time_i) continue;
            int start_time = max(log.first, k);
            int end_time = min(log.second, k+adv_time_i);
            possible_time += end_time - start_time;
        }
        if(max_play_time<possible_time){
            max_play_time = possible_time;
            max_play_time_idx = k;
        }
    }

    if(max_play_time_idx/3600 < 10) answer += "0" + to_string(max_play_time_idx/3600) + ":";
    else answer += to_string(max_play_time_idx/3600) + ":";
    max_play_time_idx = max_play_time_idx%3600;
    if(max_play_time_idx/60 < 10) answer += "0" + to_string(max_play_time_idx/60) + ":";
    else answer += to_string(max_play_time_idx/60) + ":";
    if(max_play_time_idx%60 < 10) answer += "0" + to_string(max_play_time_idx%60);
    else answer += to_string(max_play_time_idx%60);

    return answer;
}