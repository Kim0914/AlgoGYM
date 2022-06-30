#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(true){
        answer++;
        if(abs(a-b) == 1 && ((a > b && a%2 == 0) || (b > a && b % 2 == 0)))
            break;
        if(a % 2 == 0){
            a /= 2;
        }
        else{
            a = (a + 1) / 2;
        }
        if(b % 2 == 0){
            b /= 2;
        }
        else{
            b = (b + 1) / 2;
        }
    }

    return answer;
}
