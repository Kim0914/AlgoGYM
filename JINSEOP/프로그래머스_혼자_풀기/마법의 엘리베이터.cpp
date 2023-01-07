#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey != 0) {
        if (storey % 10 == 5) {
            int carry = storey / 10;
            if (carry % 10 >= 5) {
                answer += 5;
                storey += 5;
            }
            else
                answer += 5;
        }
        else if (storey % 10 > 5) {
            answer += 10 - (storey % 10);
            storey += 10;
        }
        else if (storey % 10 < 5) {
            answer += storey % 10;
        }
        
        storey /= 10;
    }

    return answer;
}
