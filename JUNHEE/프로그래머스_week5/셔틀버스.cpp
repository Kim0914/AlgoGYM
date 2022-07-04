#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string>

using namespace std;
priority_queue<int, vector<int>, greater<int>> cru;
void make_cru(vector<string> timetable){
    int hour, minute, time;
    for(int i = 0; i < timetable.size(); i++){
        hour = (timetable[i][0] - '0') * 10 + (timetable[i][1] - '0');
        minute = (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0');
        time = hour*60 + minute;
        cru.push(time);
    }
}
string make_ans(int temp_hour, int temp_minute){
    string hour, minute;
    if(temp_hour < 10){
        hour = "0";
        hour += temp_hour + '0';
    }
    else{
        int ten = temp_hour / 10;
        int one = temp_hour % 10;
        hour = ten + '0';
        hour += one + '0';
    }
    if(temp_minute < 10){
        minute = "0";
        minute += temp_minute + '0';
    }
    else{
        int ten = temp_minute / 10;
        int one = temp_minute % 10;
        minute = ten + '0';
        minute += one + '0';
    }
    return hour + ":" + minute;
}
string solution(int n, int t, int m, vector<string> timetable) {
    int time = 0;
    string answer = "";
    make_cru(timetable);
    vector<int> bus_arr(n);
    vector<vector<int>> bus_time(n);
    
    int b_time = 0;
    for(int i = 0; i < n; i++){
        b_time = 9 * 60 + i * t;
        bus_arr[i] = b_time;
    }
    
    for(int i = 0; i < n*m; i++){
        if(!cru.empty()){
            time = cru.top();
            for(int j = 0; j < n; j++){
                if(time <= bus_arr[j]){
                    if(bus_time[j].size() < m){
                        bus_time[j].push_back(time);
                        cru.pop();
                        break;
                    }
                }
            }
        }
    }
    int temp_time, temp_hour, temp_minute;
    if(bus_time[n-1].size() < m){
        temp_hour = bus_arr[n-1]/60;
        temp_minute = bus_arr[n-1]%60;
    }
    else if(bus_time[n-1].size() == m){
        temp_time = bus_time[n-1][m-1]-1;
        temp_hour = temp_time/60;
        temp_minute = temp_time%60;
    }
    
    answer = make_ans(temp_hour, temp_minute);
    return answer;
}
