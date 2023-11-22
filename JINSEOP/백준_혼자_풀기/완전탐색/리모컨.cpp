#include <iostream>
#include <string>
using namespace std;

string ch_to = "", ch_cmp = "";
int num = 0, butt = 0, answer = 0;
bool broken[10];
bool check_broken(int channel) {
    string ch_to_str = to_string(channel);
    // 들어온 채널에 대해서 고장난 버튼이 있으면
    // 만들 수 없는 채널이다.

    for (int i = 0; i < ch_to_str.size(); i++) {
        if (broken[ch_to_str[i] - '0'])
            return false;
    }

    return true;
}

int main(){
    cin >> ch_to >> num;
    for (int i = 0; i < num; i++) {
        cin >> butt;
        broken[butt] = true;
        // 고장난 버튼 입력
    }

    int ch_to_int = stoi(ch_to);
    int answer = abs(ch_to_int - 100);
    // 기본적으로, +-만 눌러서 옮기는 경우를 저장해놓자.

    for (int i = 0; i <= 1000000; i++) {
        if (check_broken(i)) {
            int partial = abs(ch_to_int - i) + to_string(i).size();
            // 옮길 수 있는 채널을 모두 순회하며 (Brute force)
            // 가능한 채널 중 최소로 이동 가능한 채널을 찾는다.
            answer = min(answer, partial);
        }
    }

    cout << answer; 
    return 0;
}

// 시간을 줄이기 위해 분기로 모든 조건을 잡으려했지만, 실패
// 단순히 Brute force를 돌려도 전혀 문제가 없음!
