#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> results;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second - a.first) < (b.second - b.first);
}

void two_pointer(vector<int> sequence, int k) {
    int front_ptr = 0, rear_ptr = 0;
    int sum = 0;

    while (front_ptr < sequence.size()) {
        sum += sequence[rear_ptr];
        if (sum == k)
            results.push_back({ front_ptr, rear_ptr });

        while (sum >= k || (rear_ptr >= sequence.size()-1 && front_ptr < sequence.size())) {
            sum -= sequence[front_ptr];
            front_ptr++;
            if (sum == k)
                results.push_back({ front_ptr, rear_ptr });
        }

        rear_ptr++;
    }
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    two_pointer(sequence, k);
    sort(results.begin(), results.end(), cmp);
    answer = { results[0].first, results[0].second };

    return answer;
}
