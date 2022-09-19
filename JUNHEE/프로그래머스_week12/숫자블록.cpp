#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long is_prime(long long num){
    for(long long i = 2; i*i <= num; i++){
        if(num % i == 0 && (num / i) <= 10000000) return num / i;
    }
    return 1;
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1, 0);
    for(int i = begin, j = 0; i <= end; i++, j++){
        answer[j] = is_prime(i);
        
    }
    if(begin == 1) answer[0] = 0;
    return answer;
}
