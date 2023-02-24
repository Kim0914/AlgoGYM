#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> A_q;
priority_queue<int, vector<int>, greater<>> B_q;
void fill_queue(vector<int> A, vector<int> B) {
    for (int i = 0; i < A.size(); i++) {
        A_q.push(A[i]);
        B_q.push(B[i]);
    }
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    fill_queue(A, B);
    while (!B_q.empty()) {
        if (A_q.top() < B_q.top()) {
            A_q.pop();
            B_q.pop();
            answer++;
            continue;
        }

        B_q.pop();
    }

    return answer;
}

// 정렬을 해도 상관이 없다는 것이 핵심!
