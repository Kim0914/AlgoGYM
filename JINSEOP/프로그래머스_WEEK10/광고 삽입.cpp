#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int timeline[360000] = { 0, };
vector<pair<int, int>> new_logs;
pair<int, int> adv_info;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) 
        return a.second < b.second;
    return a.first < b.first;
}

int convert_to_time(string str) {
    int hour = 0, min = 0, sec = 0;
    int time_to_sec = 0;

    hour = ((str[0] - '0') * 10) + (str[1] - '0');
    min = ((str[3] - '0') * 10) + (str[4] - '0');
    sec = ((str[6] - '0') * 10) + (str[7] - '0');

    time_to_sec = hour * 3600 + min * 60 + sec;

    return time_to_sec;
}

void convert_logs(string& play_time, string& adv_time, vector<string> logs) {
    int st_time = 0, en_time = 0;

    adv_info.first = convert_to_time(play_time);
    adv_info.second = convert_to_time(adv_time);

    for (auto log : logs) {
        st_time = convert_to_time(log.substr(0, 8));
        en_time = convert_to_time(log.substr(9, 8));
        new_logs.push_back({ st_time, en_time });
    }

    sort(new_logs.begin(), new_logs.end());
}

void write_play_section() {
    for (auto log : new_logs) {
        for (int i = log.first; i < log.second; i++)
            timeline[i]++;
    }
}

int calc_max_section(int play_time, int adv_time) {
    long long max_time = 0;
    int res = 0;

    for (int i = 0; i < adv_time; i++)
        max_time += timeline[i];

    long long sliding_window = max_time;

    for (int i = adv_time; i < play_time; i++) {
        sliding_window += timeline[i] - timeline[i - adv_time];

        if (max_time < sliding_window) {
            max_time = sliding_window;
            res = i - adv_time + 1;
        }
    }

    return res;
}

string convert_to_log(int sec) {
    string org_sec = to_string(sec % 60);
    if (org_sec.length() == 1) org_sec = '0' + org_sec;
    sec /= 60;

    string org_min = to_string(sec % 60);
    if (org_min.length() == 1) org_min = '0' + org_min;
    sec /= 60;

    string org_hour = to_string(sec);
    if (org_hour.length() == 1) org_hour = '0' + org_hour;

    return org_hour + ":" + org_min + ":" + org_sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int finded_point = 0;

    convert_logs(play_time, adv_time, logs);
    write_play_section();
    finded_point = calc_max_section(adv_info.first, adv_info.second);
    answer = convert_to_log(finded_point);

    return answer;
}
