#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define pll pair<long long, long long>

ll second_to_millisecond(string target) {
    ll result = 0;

    ll hour = stoi(target.substr(0, 2)) * 3600 * 1000;
    ll minute = stoi(target.substr(3, 2)) * 60 * 1000;
    ll second = stoi(target.substr(6, 2)) * 1000;
    ll milsec = stoi(target.substr(9, 3));

    result = hour + minute + second + milsec;
    return result;
}

pll parse_time(string target) {
    string response_time = target.substr(11, 12);
    string processing_time = target.substr(24);
    processing_time = processing_time.substr(0, processing_time.size() - 1);
    
    ll response_milsec = second_to_millisecond(response_time);
    ll starting_milsec = response_milsec - (stod(processing_time) * 1000) + 1;

    return {starting_milsec, response_milsec};
    // 처리 시작 시간, 처리 완료 시간을 반환
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pll> timeline;
    for (string s : lines)
        timeline.push_back(parse_time(s));
    sort(timeline.begin(), timeline.end());
    // 시작 시간 기준 오름차순 정렬
    
    priority_queue<ll, vector<ll>, greater<>> process_q;
    for (pll time_pair : timeline) {
        while (!process_q.empty() && ((process_q.top() + 999) < time_pair.first))
        // 현재 큐에 있는 가장 빨리 끝나는 작업의 완료 시간에 대해
        // 1초를 더했는데도 시작 시간이 더 크다면? 큐에서 해당 작업은 빼내도록 하자.
            process_q.pop();

        process_q.push(time_pair.second);
        // 이제 남은 작업들은 (완료 시간 + 1초)에도 남아있는 작업들이다.
        int size = process_q.size();
        answer = max(answer, size);
    }

    return answer;
}
