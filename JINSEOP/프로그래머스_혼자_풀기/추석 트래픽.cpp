#include <string>
#include <vector>
#include <iostream>
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
    
    priority_queue<ll> process_q;
    for (string s : lines) {
        pll parsed_time = parse_time(s);
        while (!process_q.empty() && ((process_q.top() + 1000) <= parsed_time.first))
            process_q.pop();

        // pair에 시작 시간, 완료 시간이 들어있음
        process_q.push(parsed_time.second);
        int size = process_q.size();

        answer = max(answer, size);
    }

    return answer;
}

int main() {
    solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" });
	return 0;
}
