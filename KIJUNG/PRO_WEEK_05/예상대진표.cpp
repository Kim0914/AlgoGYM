#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--;
    b--;

    while(true){
        a /= 2;
        b /= 2;
        answer++;
        if (a==b) break;
    }
    return answer;
}