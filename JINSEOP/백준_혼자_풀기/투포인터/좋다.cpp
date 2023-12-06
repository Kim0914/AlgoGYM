#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, answer = 0;
ll number_list[2000];
int main() {
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> number_list[i];

    // 투 포인터로 긁으면 모든 수 표현 가능
    // 왜? 핵심은 모든 수를 표현해야 하는게 아님.
    sort(number_list, number_list + num);
    for (int i = 0; i < num; i++) {
        ll target = number_list[i];
        
        int left = 0, right = num - 1;
        while (left < right) {
            int partial_sum = number_list[left] + number_list[right];

            if (partial_sum < target)
                left++;
            else if (partial_sum > target)
                right--;
            else if (partial_sum == target) {
                if (left != i && right != i) {
                    answer++;
                    break;
            // 본인은 결과에 포함시킬 수 없음
                }

                else if (left == i)
                    left++;
                else if (right == i)
                    right--;
            // 본인이 등장했으면 지나쳐야 한다.
            }
        }
    }

    cout << answer;
    return 0;
}
