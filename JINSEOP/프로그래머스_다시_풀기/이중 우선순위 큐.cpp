#include <set>
#include <string>
#include <vector>
using namespace std;

set<int> min_max_heap;
pair<char, int> parse_command(string operation) {
    char cmd = operation[0];
    int num = stoi(operation.substr(2, operation.size() - 1));

    return make_pair(cmd, num);
}

void delete_elem(int cmd) {
    if (min_max_heap.empty()) return;

    int min_v = *min_max_heap.begin();
    int max_v = *(--min_max_heap.end());
    if (cmd == 1) min_max_heap.erase(max_v);
    else min_max_heap.erase(min_v);
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (auto s : operations) {
        pair<char, int> cmd = parse_command(s);
        switch (cmd.first)
        {
        case 'I':
            min_max_heap.insert(cmd.second);
            break;
        case 'D':
            delete_elem(cmd.second);
            break;
        }
    }
    
    if (!min_max_heap.empty()) {
        answer.push_back(*(--min_max_heap.end())); // end()는 마지막 원소 다음을 가리킨다.
        answer.push_back(*min_max_heap.begin());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

// Set은 이진 트리인 Balanced Tree(Red Black Tree) 형태로 이미 구성되어있다.
// 따라서 삽입 삭제 및 최대 최소 판별이 용이하다.
// 위와 같은 문제 해결시에 매우 간편한 STL이다.
// 기본 오름차순 정렬.
