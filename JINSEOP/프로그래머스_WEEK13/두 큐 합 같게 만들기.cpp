#include <string>
#include <vector>
using namespace std;

bool validate(vector<int> queue1, vector<int> queue2) {
    long long s1 = 0, s2 = 0;
    for (auto i : queue1)
        s1 += i;
    for (auto i : queue2)
        s2 += i;

    if ((s1 + s2) % 2 != 0) return false;
    return true;
}

int calc_rotate(vector<int> queue1, vector<int> queue2) {
    int cnt = 0, ptr_1 = 0, ptr_2 = 0, q1_size = queue1.size(), q2_size = queue2.size();
    long long sum_1 = 0, sum_2 = 0;

    for (int i = ptr_1; i < queue1.size(); i++)
        sum_1 += queue1[i];
    for (int i = ptr_2; i < queue2.size(); i++)
        sum_2 += queue2[i];

    while (true) {
        if (sum_1 > sum_2) {
            sum_1 -= queue1[ptr_1];
            queue2.push_back(queue1[ptr_1]);
            sum_2 += queue2[queue2.size() - 1];
            ptr_1++; cnt++;
        }
        else if (sum_1 < sum_2) {
            sum_2 -= queue2[ptr_2];
            queue1.push_back(queue2[ptr_2]);
            sum_1 += queue1[queue1.size() - 1];
            ptr_2++; cnt++;
        }

        if (sum_1 == sum_2) break;
        if (cnt > (q1_size + q2_size) * 2) return -1;
    }

    return cnt;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;

    if (!validate(queue1, queue2)) answer = -1;
    else answer = calc_rotate(queue1, queue2);

    return answer;
}
