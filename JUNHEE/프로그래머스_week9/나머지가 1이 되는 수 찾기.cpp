#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    n--;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            answer = i;
            break;
        }
        answer = n;
    }
    return answer;
}
