#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> counter;
void count_sum(vector<int> elements) {
    int len = 1, start_idx = 0, limit = elements.size();
    int sum = 0;

    while (len < limit) {
        while (start_idx < limit) {
            sum = 0;

            for (int i = start_idx; i < start_idx + len; i++) {
                if (i >= limit)
                    sum += elements[i % limit];
                else
                    sum += elements[i];
            }

            counter.insert(sum);
            start_idx++;
        }

        start_idx = 0;
        len++;
    }
}

void add_whole_case(vector<int> elements) {
    int sum = 0;
    for (int i : elements)
        sum += i;

    counter.insert(sum);
}

int solution(vector<int> elements) {
    int answer = 0;

    count_sum(elements);
    add_whole_case(elements);
    answer = counter.size();
    return answer;
}
