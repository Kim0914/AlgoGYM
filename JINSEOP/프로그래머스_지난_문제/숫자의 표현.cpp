#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n / 2; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += j;
            if (sum > n) break;
            if (sum == n) {
                answer++;
                break;
            }
        }
    }

    answer += 1;
    return answer;
}
