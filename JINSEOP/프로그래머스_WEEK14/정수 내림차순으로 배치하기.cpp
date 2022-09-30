#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string temp = to_string(n);
    sort(temp.begin(), temp.end(), greater<>());

    answer = stoll(temp);
    return answer;
}
