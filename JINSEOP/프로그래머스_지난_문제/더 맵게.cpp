#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> classifier;
void init_queue(vector<int> scoville) {
    for (int i : scoville)
        classifier.push(i);
}

int mix_food(int k) {
    int cnt = 0;
    while (classifier.top() < k) {
        if (classifier.size() < 2) return -1;
        
        int min = classifier.top();
        classifier.pop();
        int second_min = classifier.top();
        classifier.pop();

        int new_food = min + (second_min * 2);
        classifier.push(new_food);

        cnt++;
    }

    return cnt;
}

int solution(vector<int> scoville, int k) {
    int answer = 0;

    init_queue(scoville);
    answer = mix_food(k);

    return answer;
}
