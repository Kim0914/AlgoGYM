#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    while (n != 0) {
        if ((n - 1) % 2 == 0) {
            n -= 1;
            answer++;
        }
        n /= 2;
    }
    return answer;
}
