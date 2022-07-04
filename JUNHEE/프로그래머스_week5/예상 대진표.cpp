#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(true){
        answer++;
        if(abs(a-b) == 1 && ((a > b && a%2 == 0) || (b > a && b % 2 == 0)))
            break;
        
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    return answer;
}
