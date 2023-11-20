#include <iostream>
#include <string>
using namespace std;
#define ll long long

string target = "";
int dp[5000];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    optimize();
    cin >> target;

    // 25114를 예시로 들어보자.
    // 제일 첫 한 글자(B) 만드는 경우 하나

    // 두 번째 dp[1] = dp[0] + 1, 뒤는 두 숫자를 한 글자로 보는 경우
    // 이 때, 26보다 작은 지 검사를 하고 더해야 함.
    // 2 5, 25 => BE, Y

    // 그럼 세 번째 dp[2]는 어떻게 될까?
    // dp[0]을 한 글자로 보는 경우에, dp[1] dp[2]를 한 글자로 볼 수 있다.
    // 또, dp[1] dp[2]를 따로 볼 수 있다.
    // dp[0]과 dp[1]을 한 글자로 보는 경우에, dp[2]를 한 글자로 볼 수 있다.
    // 2 5 1, 25 1 => BEA, YA, 51은 만들 수 없음.

    // 네 번째 글자 dp[3]은?
    // 2 5 1 1, 2 5 11, 25 1 1, 25 11 => BEAA, BEK, YAA, YK 4가지가 가능함.
    
    // 다섯 번째 글자 dp[4]는?
    // 2 5 1 1 4, 2 5 1 14, 2 5 11 4, 25 1 1 4, 25 1 14, 25 11 4
    // => BEAAD, BEAN, BEKD, YAAD, YAN, YKD 이렇게 됨.

    // 이를 미루어 보아, 아래와 같이 정리할 수 있다.
    // 각 단계에서 한 글자만 이용할 수 있다면? 이전 단계 그대로 넘어옴
                              // 그냥 알파벳 하나만 붙이는 거라서 그럼
    // 두 글자 모두 이용할 수 있다면?
    // 세 글자가 이어지는 경우는 없다는 것이 핵심!
    // dp[i - 2]를 더하고 dp[i - 1]를 더하는 것으로 점화식을 세울 수 있다.

    // 각 자리가 더할 수 있는 문자인지 검사하는 것이 중요하다!

    if (target[0] == '0') {
        cout << 0 << '\n';
        return 0; // 잘못된 암호는 0 출력
    }

    dp[0] = 1;
    string validator = target.substr(0, 2);
    if (stoi(validator) <= 26 && stoi(validator) >= 10)
        dp[1] += 1;
    if ((target[1] - '0') > 0)
        dp[1] += 1;

    for (int i = 2; i < target.size(); i++) {
        validator = target.substr(i - 1, 2);

        if (stoi(validator) <= 26 && stoi(validator) >= 10)
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        // 두 개 붙일 수 있는 경우
        if ((target[i] - '0') > 0) {
            dp[i] = (dp[i - 1] + dp[i]) % 1000000;
        }
        // 하나 붙일 수 있는 경우
    }

    cout << dp[target.size() - 1];
    return 0;
}
