#include <string>
#include <vector>
#include <iostream>

using namespace std;
int movie[99*3600 + 59*60 + 60] = {0,};

int time_to_int(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    int second = stoi(time.substr(6,2));
    
    return hour * 3600 + minute * 60 + second;
}
string int_to_time(int num){
    string time = "";
    int hour = num / 3600; num %= 3600;
    int minute = num / 60; num %= 60;
    int second = num;
    
    if(hour >= 10) time += to_string(hour);
    else time += "0" + to_string(hour);
    time += ":";
    if(minute >= 10) time += to_string(minute);
    else time += "0" + to_string(minute);
    time += ":";
    if(second >= 10) time += to_string(second);
    else time += "0" + to_string(second);
    
    return time;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play = time_to_int(play_time);
    int adv = time_to_int(adv_time);
    for(auto log : logs){
        int start_time = time_to_int(log.substr(0,8));
        int end_time = time_to_int(log.substr(9,8));
        for(int i = start_time; i < end_time; i++){
            movie[i]++;
        }
    }
    long long max_time = 0;
    long long sum = 0;
    for(int i = 0; i < adv; i++){
        sum += movie[i];
    }
    max_time = sum;
    int t_answer = 0;
    for(int i = 1, j = adv + 1; j <= play; i++, j++){
        sum -= movie[i];
        sum += movie[j];
        if(max_time < sum){
            max_time = sum;
            t_answer = i + 1;
        }
    }
    answer = int_to_time(t_answer);
    return answer;
}
