#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long calc_section_sum(int a, int b){
    long long sum = 0;
    int temp = 0;
    
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    
    for(int i = a; i <= b; i++)
        sum += i;
    
    return sum;
}

long long solution(int a, int b) {
    long long answer = 0;
    
    answer = calc_section_sum(a, b);
    return answer;
}
