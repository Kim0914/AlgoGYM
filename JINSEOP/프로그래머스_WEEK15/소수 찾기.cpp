#include <string>
#include <vector>
using namespace std;

bool seive[1000001] = {0,};
int seive_of_eratosthenes(int n){
    int cnt = 0;
    
    for(int i = 2; i <= n; i++){
        if(seive[i]) continue;
        
        for(int j = i*2; j <= n; j = j+i)
                seive[j] = true;
    }
    
    for(int i = 2; i <= n; i++)
        if(!seive[i])
            cnt++;
    
    return cnt;
}

int solution(int n) {
    int answer = 0;

    answer = seive_of_eratosthenes(n);
    return answer;
}

// 에라토스테네스의 체.
