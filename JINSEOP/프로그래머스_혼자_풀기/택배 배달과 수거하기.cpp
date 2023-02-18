#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliver = 0, pickup = 0;

    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0, dist = i + 1;

        deliver -= deliveries[i];
        pickup -= pickups[i];

        while (deliver < 0 || pickup < 0) {
            deliver += cap;
            pickup += cap;
            cnt += 1;
        }

        answer += dist * 2 * cnt;
    }

    return answer;
}
