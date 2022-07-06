#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int np[60001] = {0, };
    np[0] = 1;
    np[1] = 1;
    for(int i = 2; i < n + 1; i++){
        np[i] = (np[i-1] + np[i-2])%1000000007; // 이 부분때문에 고생했다..
    }
    
    answer = np[n];
    return answer;
}
