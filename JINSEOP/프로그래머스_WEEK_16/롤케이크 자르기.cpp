#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int frontward[1000001];
int backward[1000001];
unordered_set<int> kind_counter;
void count_kind_frontward(vector<int> topping) {
    for (int i = 1; i <= topping.size(); i++) {
        kind_counter.insert(topping[i-1]);
        frontward[i] = kind_counter.size();
    }

    kind_counter.clear();
}

void count_kind_backward(vector<int> topping) {
    for (int i = topping.size() - 1; i >= 0; i--) {
        kind_counter.insert(topping[i]);
        backward[i] = kind_counter.size();
    }
}

int count_fair_part(int size) {
    int cnt = 0;

    for (int i = 0; i < size; i++)
        if (frontward[i] == backward[i])
            cnt++;

    return cnt;
}

int solution(vector<int> topping) {
    int answer = 0;

    count_kind_frontward(topping);
    count_kind_backward(topping);
    answer = count_fair_part(topping.size());

    return answer;
}
