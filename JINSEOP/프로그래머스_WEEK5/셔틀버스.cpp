#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<string, vector<string>, greater<string>> wait_q;
void init_queue(vector<string> timetable) {
    for (int i = 0; i < timetable.size(); i++)
        wait_q.push(timetable[i]);
}

string convert_time(string t) {
    int hour = (t[0] - '0') * 10 + (t[1] - '0');
    int min = (t[3] - '0') * 10 + (t[4] - '0');

    min -= 1;
    if (min < 0) {
        hour -= 1;
        min += 60;
    }
    t = to_string(hour / 10) + to_string(hour % 10) + ":"
        + to_string(min / 10) + to_string(min % 10);
    return t;
}

vector<pair<string, int>> set_bus(int n, int t, int m) {
    vector<pair<string, int>> table; 
    int hour = 9;
    int min = 0;
    string bt_s = "09:00";

    table.push_back(make_pair(bt_s, m));
    for (int i = 0; i < n - 1; i++) {
        min += t;
        if (min > 59) {
            hour += 1;
            min -= 60;
        }
        bt_s = to_string(hour / 10) + to_string(hour % 10) + ":"
            + to_string(min / 10) + to_string(min % 10);
        table.push_back(make_pair(bt_s, m));
    }

    return table;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<pair<string, int>> bus = set_bus(n, t, m);
    int idx = 0;
    bool no_seat = false;
    string answer = "";
    
    init_queue(timetable);

    for (int i = 0; i < bus.size(); i++) {
        if (wait_q.empty()) break;
        for (int j = 0; j < m; j++) {
            if (wait_q.empty()) break;
            if (bus[i].first >= wait_q.top()) {
                answer = wait_q.top();
                wait_q.pop();
                bus[i].second--;
            }
            else break;
        }
    }

    if (bus[bus.size() - 1].second == 0)
        no_seat = true;

    if (no_seat) answer = convert_time(answer);
    else answer = bus[bus.size() - 1].first;

    return answer;
}
