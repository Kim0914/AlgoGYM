#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<int> sorting_machine;

void make_sum_set(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++)
            sorting_machine.insert(numbers[i] + numbers[j]);
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    sort(numbers.begin(), numbers.end());
    make_sum_set(numbers);

    for (auto i : sorting_machine)
        answer.push_back(i);

    return answer;
}
