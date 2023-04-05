#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> divisors(e + 1);
    vector<int> maxvec(e + 1);
    int max = 0, max_idx = 0;

    for (int i = 1; i <= e; i++) {
        for (int j = i; j <= e; j += i) {
            divisors[j] += 1;
        }
    }

    
    for (int i = e; i >= 0; i--) {
        max_idx = max > divisors[i] ? max_idx : i;
        max = max > divisors[i] ? max : divisors[i];
        maxvec[i] = max_idx;
    }

    for (auto i : starts)
        answer.push_back(maxvec[i]);

    return answer;
}
