#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> work_classifier;
void init_queue(vector<int> works) {
    for (int i : works)
        work_classifier.push(i);
}

void progress_task(int n) {
    int curr_work = 0;

    for (int i = 0; i < n; i++) {
        curr_work = work_classifier.top();
        work_classifier.pop();
        
        curr_work--;
        if (curr_work < 0) break;
        work_classifier.push(curr_work);
    }
}

long long calculate_fatigue() {
    long long sum = 0;
    long long temp = 0;

    while (!work_classifier.empty()) {
        temp = work_classifier.top();
        sum += temp * temp;
        work_classifier.pop();
    }

    return sum;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;

    init_queue(works);
    progress_task(n);
    answer = calculate_fatigue();
    return answer;
}
