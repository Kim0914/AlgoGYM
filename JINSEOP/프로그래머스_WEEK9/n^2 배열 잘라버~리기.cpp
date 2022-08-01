#include <string>
#include <vector>
using namespace std;

void init_map(int n, long long left, long long right, vector<int>& maps) {
    long long start_idx = left / n; // 1
    long long end_idx = right / n; // 3

    long long cnt = start_idx;

    for (long long i = 0; i < (end_idx - start_idx + 1); i++) {
        for (long long j = 0; j < cnt; j++) {
            maps.push_back(cnt + 1);
        }
        for (long long j = cnt+1; j <= n; j++) {
            maps.push_back(j);
        }
        cnt++;
    }
}

void slice_map(int n, long long left, long long right, vector<int> maps, vector<int>& answer) {
    long long diff = right - left;
    
    copy(maps.begin() + (left % n), maps.begin() + (left%n) + diff + 1, answer.begin());
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    vector<int> maps;

    init_map(n, left, right, maps);
    slice_map(n, left, right, maps, answer);

    return answer;
}
