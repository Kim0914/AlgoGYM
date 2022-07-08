#include <string>
#include <vector>

using namespace std;
int measure (int num){
    int count = 0;
    for(int i = 1; i * i < num + 1; i++){
        if(num % i == 0){
            if(i*i != num) count += 2;
            else count += 1;
        }
    }
    return count;
}
int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i < right + 1; i++){
        if(measure(i) % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}
