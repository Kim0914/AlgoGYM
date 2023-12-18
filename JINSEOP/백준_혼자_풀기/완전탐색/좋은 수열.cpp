#include <iostream>
#include <string>
using namespace std;

int num = 0;
string target = "", answer = "";
bool visit[10];
bool check_duplication() {
    int size = target.size();
    for (int i = 1; i <= size / 2; i++)
        if (target.substr(size - i, i) == target.substr(size - 2 * i, i))
            return false;
    // 수열 체크, 동일 부분 수열 반복 시 중지
    // 추가된 문자의 위치부터 체크한다.
    // 뒤로 한 글자씩 늘려가며 문자열 길이의 절반까지 검사

    return true;
}

void backtrack() {
    if (!check_duplication())
        return;

    if (target.size() == num) {
        cout << target;
        exit(0);
    // 찾으면 프로그램을 즉시 종료시켜야함
    }

    for (int i = 1; i <= 3; i++) {
        target += (i + '0');
        backtrack();
        target.pop_back();
    // 일반적인 백트래킹
    }
}

int main() {
    cin >> num;
    backtrack();

    return 0;
}
