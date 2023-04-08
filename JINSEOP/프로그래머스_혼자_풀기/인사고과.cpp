#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<pair<pair<int, int>, int>> infos;
vector<int> ranks;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first > b.first.first;
}

void fill_infos(vector<vector<int>> scores) {
    for (int i = 0; i < scores.size(); i++)
        infos.push_back({ {scores[i][0], scores[i][1]}, i+1 });
}

int validate() {
    int prev_score = 0;

    for (auto pair : infos) {
        if (pair.first.second < prev_score) {
            // 자기 앞에 자기보다 동료 평가 점수가 큰 사람이 있으면, 
            // 무조건 그 사람은 인센에서 제외됨.
            // 왜? 내가 근무 평가 점수로 내림차순 정렬을 해서.
            if (pair.second == 1)
                return -1; // 완호
        }
        else {
            ranks.push_back(pair.first.first + pair.first.second);
            prev_score = max(prev_score, pair.first.second);
        }
    }

    return 0;
}

int solution(vector<vector<int>> scores) {
    int answer = 0;

    fill_infos(scores);
    sort(infos.begin(), infos.end(), cmp);
    answer = validate();
    sort(ranks.begin(), ranks.end(), greater<>());
    if (answer == 0) // 완호가 인센 대상이면
        answer = find(ranks.begin(), ranks.end(), scores[0][0] + scores[0][1]) - ranks.begin() + 1;

    return answer;
}
