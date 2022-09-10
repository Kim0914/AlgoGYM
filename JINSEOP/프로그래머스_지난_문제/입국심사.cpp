#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void binary_search(long long& answer, int n, long long st, long long end, vector<int> times) {
    while (st <= end) {
        long long mid = (st + end) / 2;
        long long client = 0;

        for (int i = 0; i < times.size(); i++)
            client += (mid / (long long)times[i]);
      // 심사관들이 처리할 수 있는 고객
      
        if (client >= n) {
            end = mid - 1;
            answer = mid;
        }
        else
            st = mid + 1;
    }
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());

    long long st = 1;
    long long end = n * (long long)times.back();
    // 심사관들이 처리했을 때 가장 늦는 시간.

    binary_search(answer, n, st, end, times);

    return answer;
}
