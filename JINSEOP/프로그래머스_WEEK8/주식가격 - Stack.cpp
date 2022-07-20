#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> timestamp;
    int p_size = prices.size();

    for (int i = 0; i < p_size; i++) {
        while (!timestamp.empty() && prices[timestamp.top()] > prices[i]) {
            // 가격이 줄어들었다면?
            answer[timestamp.top()] = i - timestamp.top();
            // 해당 index의 현재 시간 - 시작 시간
            timestamp.pop();
        }
        
        timestamp.push(i);
    }

    while (!timestamp.empty()) {
        // 이제 남은 친구들은 마지막까지 줄어들지 않는 친구들이다.
        answer[timestamp.top()] = (p_size - 1) - timestamp.top();
        timestamp.pop();
    }

    return answer;
}
