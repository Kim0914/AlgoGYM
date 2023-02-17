#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp_q {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

priority_queue<vector<int>, vector<vector<int>>, cmp_q> room_checker;
vector<vector<int>> time_table;

bool cmp_v(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int time_carry(int in_time) {
    in_time += 10;

    if (in_time % 100 >= 60)
        in_time += 40;

    return in_time;
}

void parse_time(vector<vector<string>> &book_time) {
    for (int i = 0; i < book_time.size(); i++) {
        time_table.push_back(
            { stoi(book_time[i][0].erase(2, 1)), stoi(book_time[i][1].erase(2, 1)) });
    }
}

int check_room() {
    int max_room = 1;
    room_checker.push(time_table[0]);

    for (int i = 1; i < time_table.size(); i++) {
        while (time_table[i][0] >= time_carry(room_checker.top()[1])) {
            room_checker.pop();
            if (room_checker.empty()) break;
        }

        room_checker.push(time_table[i]);
        max_room = max_room < room_checker.size() ? room_checker.size() : max_room;
    }

    return max_room;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    parse_time(book_time);
    sort(time_table.begin(), time_table.end(), cmp_v);
    answer = check_room();

    return answer;
}
