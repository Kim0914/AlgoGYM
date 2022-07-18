#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (auto num : numbers) {
        if (num % 2 == 0) answer.push_back(num + 1);
        else {
            long long key = 1;

            while (true) {
                if ((num & key) == 0) break;
                key *= 2;
            }
            key /= 2;

            answer.push_back(num + key);
        }
    }

    return answer;
}

// 규칙성
