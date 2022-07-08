#include <vector>
#include <queue>
using namespace std;
#define NULL_TIME 0

queue<int> bridge;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tot_weight = 0, cursor = 0;
    
    while (true) {
        if (cursor == truck_weights.size()) {
            answer += bridge_length;
            // 마지막 차.
            break;
        }

        answer++; // 시간은 계속 흐른다.
        int temp = truck_weights[cursor];
        // 현재 내가 가리키는 차.

        if (bridge.size() == bridge_length) {
            // 현재 다리가 꽉 찼으면, 앞에서 부터 탈출
            tot_weight -= bridge.front();
            bridge.pop();
        }

        if (tot_weight + temp <= weight) {
            // 아직 다리 위에 차가 더 올라갈 수 있다면?
            tot_weight += temp;
            bridge.push(temp);
            // 다리 위에 차를 밀어넣고
            cursor++; // 다음 차 가리키기
        }
        else bridge.push(NULL_TIME);
        // 올릴 수 있는 차가 없을 때, 시간을 채우기 위해 공백 삽입
        // 무게 총합에 영향이 없게 하기 위해 0으로 삽입
    }

    return answer;
}
