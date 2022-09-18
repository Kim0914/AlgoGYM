#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define BIGINT 10000000
long long get_divisor(long long num) {
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0 && (num / i) <= BIGINT)
            return (num / i);
    }

    return 1;
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
