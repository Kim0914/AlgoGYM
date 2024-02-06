#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), cmp);
    // 차량의 출발 지점이 빠른 순서로 정렬

    int curr_car = routes[0][1];
    for (int i = 1; i < routes.size(); i++) {
    // 범위가 겹치는 자동차끼리는 반드시 같은 카메라를 지난다.
        if (routes[i][0] > curr_car) {
        // 다음 자동차의 진입이 현재 자동차의 퇴장보다 늦으면?
        // 카메라를 새로 설치해야하며, 퇴장 또한 갱신한다.
            answer++;
            curr_car = routes[i][1];
            continue;
        }

        curr_car = min(curr_car, routes[i][1]);
        // 겹치는 범위 내에서는 더 작은 쪽으로 퇴장 위치 갱신
    }

    return answer;
}

int main() {
    solution({ {-20,-15}, {-14, 5}, {-18,-13}, {-5,3} });
    return 0;
}
