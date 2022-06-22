#include <vector>
#include <queue>
using namespace std;

priority_queue<int> key_q;
queue<int> wait_q;
queue<int> index_q;

void init_q(vector<int> priorities){
    for(int i = 0; i<priorities.size(); i++){
        key_q.push(priorities[i]);
        wait_q.push(priorities[i]);
        index_q.push(i);
    }
}

void atomic_to_back() {
    wait_q.push(wait_q.front());
    wait_q.pop();
    index_q.push(index_q.front());
    index_q.pop();
}

void atomic_pop() {
    key_q.pop();
    wait_q.pop();
    index_q.pop();
}

int solution(vector<int> priorities, int location) {
    int answer = 1;

    init_q(priorities);

    while (!wait_q.empty()) {
        if (key_q.top() != wait_q.front()) 
            atomic_to_back();
        else {
            if (index_q.front() == location) break;
            atomic_pop();
            answer++;
        }
    }

    return answer;
}
