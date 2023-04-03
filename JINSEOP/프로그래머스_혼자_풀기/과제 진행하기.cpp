#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

stack<tuple<string, int, int>> assignments;
bool cmp(vector<string> &a, vector<string> &b) {
    return a[1] < b[1];
}

void do_assignments(vector<vector<string>> &plans, vector<string> &answer) {
    for (auto i : plans) {
        int hour = stoi(i[1].substr(0, 2));
        int minute = stoi(i[1].substr(3, 2));
        int start_time = (hour * 60) + minute; // 분 처리가 편함
        int worktime = stoi(i[2]); // 모두 int로 변환해서 stack에 넣음.

        if (!assignments.empty()) {
            string prev_plan = get<0>(assignments.top());
            int prev_start_time = get<1>(assignments.top());
            int prev_worktime = get<2>(assignments.top()); // 둘을 더하면 종료시간
            int progressable_time = start_time - prev_start_time;
            assignments.pop();

            if (progressable_time < prev_worktime)
                assignments.push(make_tuple(prev_plan, prev_start_time, prev_worktime - progressable_time));
            else {
                answer.push_back(prev_plan);
                progressable_time -= prev_worktime;

                while (!assignments.empty() && progressable_time > 0) { // 진행 가능한 시간이 남으면
                    prev_plan = get<0>(assignments.top());             // Stack에 남아있는 일 처리
                    prev_start_time = get<1>(assignments.top());
                    prev_worktime = get<2>(assignments.top());
                    assignments.pop();

                    if (progressable_time < prev_worktime) { // 진행 가능한 시간 안에 처리하지 못하는 일
                        assignments.push(make_tuple(prev_plan, prev_start_time, prev_worktime - progressable_time));
                        break; // Work time에서 진행 가능한 시간만 빼고 Stack의 top에 다시 투입
                    }
                    else { // 진행 가능한 시간 안에 모두 처리된 일
                        answer.push_back(prev_plan);
                        progressable_time -= prev_worktime;
                    }
                }
            }
        }

        assignments.push(make_tuple(i[0], start_time, worktime));
    }
}

void do_rest_assignment(vector<string> &answer) {
    while (!assignments.empty()) {
        answer.push_back(get<0>(assignments.top()));
        assignments.pop();
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);

    do_assignments(plans, answer);
    do_rest_assignment(answer);

    return answer;
}
