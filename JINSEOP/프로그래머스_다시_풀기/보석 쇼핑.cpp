#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_set<string> counter;
unordered_map<string, int> duplication_detector;
pair<int, int> answer;
void count_nonduplication(vector<string> gems) {
    for (auto s : gems)
        counter.insert(s);
}

void two_point(vector<string> gems) {
    int front_ptr = 0, back_ptr = 0;
    int set_size = counter.size();
    
    for (auto gem : gems) {
        duplication_detector[gem]++;
        if (duplication_detector.size() == set_size) break;
        back_ptr++;
    }

    int min_v = back_ptr - front_ptr;
    answer.first = front_ptr + 1;
    answer.second = back_ptr + 1;

    while (back_ptr < gems.size()) {
        string cursor = gems[front_ptr];
        duplication_detector[cursor]--;
        front_ptr++;

        if (duplication_detector[cursor] == 0) {
            back_ptr++;
            for (; back_ptr < gems.size(); back_ptr++) {
                duplication_detector[gems[back_ptr]]++;
                if (cursor == gems[back_ptr]) break;
            }
            if (back_ptr == gems.size()) break;
        }
        
        if (min_v > (back_ptr - front_ptr)) {
            answer.first = front_ptr + 1;
            answer.second = back_ptr + 1;
            min_v = back_ptr - front_ptr;
        }
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> res;

    count_nonduplication(gems);
    two_point(gems);
    res.push_back(answer.first);
    res.push_back(answer.second);

    return res;
}

// 투 포인터를 연습할 수 있는 문제이다.
// 더 풀어보자.
