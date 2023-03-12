#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sorter;
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    for (int i = 0; i < numbers.size(); i++) {
        while (!sorter.empty()) {
            if (sorter.top().first >= numbers[i])
                break;

            answer[sorter.top().second] = numbers[i];
            sorter.pop();
        }

        sorter.push({ numbers[i], i });
    }

    return answer;
}

int main() {
    vector<int> numbers = {9, 1, 5, 3, 6, 2};
    solution(numbers);
    return 0;
}
