#include <string>
#include <vector>
using namespace std;

long long get_divisor(long long num) {
    long long key = num / 2;

    while (true) {
        if ((num % key) == 0)
            return key;

        key--;
    }
}

void pave_road(vector<int>& answer, long long begin, long long end) {
    long long limit = 2;

    for (long long i = begin; i <= end; i++) {
        if (i == 1) continue;
        answer[i - begin] = get_divisor(i);
    }
}

vector<int> solution(long long begin, long long end) {
    long long road_length = (end - begin) + 1;
    vector<int> answer(road_length, 1);
    answer[0] = 0; // Init Zero block

    pave_road(answer, begin, end);
    return answer;
}
