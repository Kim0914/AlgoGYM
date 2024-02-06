#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;

    sort(targets.begin(), targets.end(), cmp);
    // 좌표 시작 위치 기준 정렬

    int curr_missile = targets[0][1];
    for (int i = 1; i < targets.size(); i++) {
        if (targets[i][0] >= curr_missile) {
        // 현재 날아오는 미사일의 마지막 범위가
        // 다음 날아올 미사일의 범위와 겹치지 않으면?
            answer++;
            curr_missile = targets[i][1];
            continue;
        }
        
        curr_missile = min(curr_missile, targets[i][1]);
        // 이 부분이 핵심이다.
        // 끝 범위가 더 짧은 미사일
    }

    return answer;
}
