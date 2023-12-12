#include <iostream>
using namespace std;
#define ll long long

int num = 0, answer = 1, answer_cnt = 0;
int check_depth(int target) {
    int cnt = 0;

    while (true) {
        if (num - target >= 0)
            num -= target;

        if (num == 0)
            break;

        target /= 2;
        cnt++;
    }

    return cnt;
}

int main() {
    cin >> num;

    // 주어진 수보다 큰 2의 제곱수가 답임.
    for (int i = 1; i <= 20; i++) {
        answer *= 2;

        if (answer >= num) {
            answer_cnt = check_depth(answer);
            break;
    // 예를 들어 주어진 수가 7이라면, 8이 답이 될 수 있음.
    // 단, 7의 정사각형을 먹으려면 1 + 2 + 4 를 먹어야 하므로 3번 쪼개야 함

    // 그럼 만약 9라면? 16짜리 초콜릿을 사서, 4번 쪼개면 된다. 8 4 2 1
    // 10은, 16짜리 초콜릿을 사서 3번만 쪼개면 된다. 8 4 2

    // 이걸 봐선, 직접 나누는 것 아니면 답이 없어보인다.
        }
    }

    cout << answer << " " << answer_cnt;
    return 0;
}
