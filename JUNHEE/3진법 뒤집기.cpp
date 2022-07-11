#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0, temp;
    string ternary;
    while(n != 0){
        temp = n % 3;
        ternary += (temp + '0');
        n /= 3;
    }
    reverse(ternary.begin(), ternary.end());
    int idx = 1;
    for(int i = 0; i < ternary.size(); i++){
        answer += (ternary[i] - '0') * idx;
        idx *= 3;
    }
    return answer;
}
