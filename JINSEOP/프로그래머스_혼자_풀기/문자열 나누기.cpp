#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<int, int> counter;
int solution(string s) {
    int answer = 0, ptr = 0;
    char start = s[0];

    while (ptr < s.size()) {
        if (start == s[ptr]) {
            counter.first++;
            ptr++;
        }
        else {
            counter.second++;
            ptr++;
        }

        if (counter.first == counter.second) {
            start = s[ptr];
            counter.first = 0; counter.second = 0;
            answer++;
        }
        else {
            if (ptr == s.size())
                answer++;
        }
    }

    return answer;
}
