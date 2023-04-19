#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> hall_of_fame;
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    hall_of_fame.push(score[0]);
    answer.push_back(hall_of_fame.top());

    for (int i = 1; i < score.size(); i++) {
        if(hall_of_fame.size() < k)
            hall_of_fame.push(score[i]);
        else {
            if (hall_of_fame.top() < score[i]) {
                hall_of_fame.push(score[i]);
                hall_of_fame.pop();
            }
        }

        answer.push_back(hall_of_fame.top());
    }

    return answer;
}
