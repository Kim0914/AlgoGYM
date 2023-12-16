#include <iostream>
using namespace std;

int num = 0;
string target = "";
int check_inner_palindrome(int left, int right) {
    while (left < right) {
        if (target[left] == target[right]) {
            left++;
            right--;
            // 같으면 그냥 계속 줄이면 됨
        }

        if (target[left] != target[right]) 
            return 2;
        // 다른게 한 번 더 나와버리면
    }

    return 1;
    // 정상적으로 종료되면 유사회문.
}

int check_palindrome() {
    int left = 0, right = target.size() - 1, count = 9999;
    while (left <= right) {
        if (target[left] == target[right]) {
            left++;
            right--;
        // 같으면 그냥 계속 줄이면 됨
        }

        if (target[left] != target[right]) {
            // 둘이 다르다면?
            if (target[left + 1] == target[right])
                count = min(count, check_inner_palindrome(left + 1, right));
            if (target[left] == target[right - 1])
                count = min(count, check_inner_palindrome(left, right - 1));
            // 위의 경우들은 하나를 줄였을 때, 회문이 되는 경우

            if ((target[left + 1] != target[right]) && (target[left] != target[right - 1]))
                return 2;
            // 해당 경우는 양 쪽 하나씩 다 줄여봐도 다른 경우
            // 더 이상 탐색할 필요가 없음.

            return count;
        }
    }

    return count;
}

int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> target;

        int answer = check_palindrome();
        if (answer == 9999)
            cout << 0 << '\n';
        else
            cout << answer <<'\n';
    }

    return 0;
}
