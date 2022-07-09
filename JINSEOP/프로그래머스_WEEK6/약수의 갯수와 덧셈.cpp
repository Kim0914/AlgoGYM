#include <string>
#include <vector>
#include <iostream>
using namespace std;

int how_many_divisor(int num) {
    int cnt = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) cnt++;
    }

    return cnt;
}

int solution(int left, int right) {
    int answer = 0, cnt = 0;

    for (int i = left; i <= right; i++){
         cnt = how_many_divisor(i);
         if (cnt % 2 == 0) answer += i;
         else answer -= i;
    }

    return answer;
}
