#include <string>
#include <vector>
using namespace std;

int DP[100001];
void init_DP(){
    DP[0] = 0;
    DP[1] = 1;
}

void fill_DP(int n){
    for(int i = 2; i <= n; i++)
        DP[i] = (DP[i-1] + DP[i-2]) % 1234567;
}

int solution(int n) {
    int answer = 0;
    
    init_DP();
    fill_DP(n);
    answer = DP[n];
    
    return answer;
}

// DP의 기본 피보나치!!
