#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> counter_q;
void fill_queue(vector<int> section) {
    for (int i : section)
        counter_q.push(i);
}

int count_answer(int m, vector<int> section) {
    int cnt = 0;

    while (!counter_q.empty()) {
        int curr = counter_q.front();
        counter_q.pop();
        cnt++;

        while (counter_q.front() <= curr + (m - 1)) {
            if (counter_q.empty())
                break;
            counter_q.pop();
        }
    }

    return cnt;
}

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    fill_queue(section);
    answer = count_answer(m, section);

    return answer;
}
