#include <iostream>
using namespace std;

long long calc_gcd(int w, int h) {
    int measure = min(w, h);
    
    while (true) {
        if (w % measure == 0 && h % measure == 0)
            return measure;
        measure--;
    }
}

long long solution(int w, int h) {
    long long answer = 1;
    
    answer = (long long)w * (long long)h - (w + h - calc_gcd(w, h));
    return answer;
}
