#include <iostream>
using namespace std;

int num = 0, window_size = 0, answer = 0, cnt = 0;
int visitor_list[250000];
int main() {
    cin >> num >> window_size;

    int front_ptr = 0, partial_sum = 0;
    for (int rear_ptr = 0; rear_ptr < num; rear_ptr++) {
        cin >> visitor_list[rear_ptr];
        partial_sum += visitor_list[rear_ptr];
        
        while ((rear_ptr - front_ptr) + 1 > window_size) {
            partial_sum -= visitor_list[front_ptr];
            front_ptr++;
        }

        if ((rear_ptr - front_ptr) + 1 == window_size)
            answer = max(answer, partial_sum);
    }

    front_ptr = 0, partial_sum = 0;
    for (int rear_ptr = 0; rear_ptr < num; rear_ptr++) {
        partial_sum += visitor_list[rear_ptr];

        while ((rear_ptr - front_ptr) + 1 > window_size) {
            partial_sum -= visitor_list[front_ptr];
            front_ptr++;
        }

        if ((rear_ptr - front_ptr) + 1 == window_size)
            if (partial_sum == answer)
                cnt++;
    }

    if (answer == 0)
        cout << "SAD";
    else
        cout << answer << "\n" << cnt;
    return 0;
}
