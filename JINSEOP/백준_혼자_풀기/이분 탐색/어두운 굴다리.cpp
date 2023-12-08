#include <iostream>
#include <vector>
using namespace std;

int bridge_length = 0, num = 0;
int light_pos[100001];
int main() {
    cin >> bridge_length >> num;
    for (int i = 0; i < num; i++)
        cin >> light_pos[i];

    int left = 0, right = bridge_length * 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        bool can_set = false;

        if (light_pos[0] > mid)
        // 첫 구역
            can_set = true;
        for (int i = 1; i < num; i++)
        // 중앙 구역
            if (light_pos[i] - light_pos[i - 1] > mid * 2)
                can_set = true;
        if (bridge_length - light_pos[num - 1] > mid)
        // 마지막 구역
            can_set = true;

        if (can_set)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << left;
    return 0;
}
