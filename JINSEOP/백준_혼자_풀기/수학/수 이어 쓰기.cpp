#include <iostream>
#include <string>
using namespace std;

int num = 0, answer = 0;
int main(){
    cin >> num;

    for (int i = 1; i <= num; i *= 10)
        answer += (num - i) + 1;
    // 1자리수, 2자리수... 
    // ex) 목표가 15?
    // (15 - 1) + 1, (15 - 10) + 1
    // 각각, 15 + 6 = 21
    // 왜? 
    // 각각 1 ~ N사이에서 1의 자리가 0이 아닌 수의 개수
    // 1 ~ N 사이에서 10의 자리가 0이 아닌 수의 개수
    //  ... 로 진행된다.

    cout << answer;
    return 0;
}
