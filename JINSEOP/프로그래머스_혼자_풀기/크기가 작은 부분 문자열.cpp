#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    long long answer = 0;
    int window = p.size();

    for (int i = 0; i < t.size() - window + 1; i++) {
        if (stoll(t.substr(i, window)) <= stoll (p)) {
            answer++;
        }
    }

    return answer;
}
