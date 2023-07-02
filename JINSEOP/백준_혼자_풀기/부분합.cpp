#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;
int two_pointer(int sum_bound) {
    int front_ptr = 0, rear_ptr = 0, sum = 0, len = 0, min_len = 999999;

    while (rear_ptr < sequence.size()) {
        if (front_ptr < sequence.size()) {
            sum += sequence[front_ptr];
            front_ptr++;
            len++;
        }

        if (front_ptr == sequence.size() && (sum < sum_bound))
            break;

        if(sum >= sum_bound) {
            if (min_len > len)
                min_len = len;

            while (sum >= sum_bound) {
                if (min_len > len)
                    min_len = len;

                sum -= sequence[rear_ptr];
                rear_ptr++;
                len--;
            }
        }
    }

    return min_len;
}

int main() {
    int seq = 0, num = 0, sum_bound = 0, result_length = 0;

    cin >> seq >> sum_bound;
    for (int i = 0; i < seq; i++) {
        cin >> num;
        sequence.push_back(num);
    }

    result_length = two_pointer(sum_bound);

    if (result_length == 999999)
        result_length = 0;
    cout << result_length;

    return 0;
}
