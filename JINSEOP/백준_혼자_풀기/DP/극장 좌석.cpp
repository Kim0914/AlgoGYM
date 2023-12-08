#include <iostream>
using namespace std;

int num = 0, vip_num = 0, vip_seat = 0, answer = 1;
int seats[41], vips[41];
void init_basis() {
    seats[0] = 1;
    seats[1] = 1;
    seats[2] = 2;
    // 피보나치 수열의 초항과 같다
    vips[num + 1] = 9;
    // 마지막을 강제로 vip로 만든다.
}

int main() {
    cin >> num >> vip_num;
    for (int i = 0; i < vip_num; i++) {
        cin >> vip_seat;
        vips[vip_seat] = 9;
        // VIP 좌석을 9로 표현하자.
    }

    init_basis();
    // 주어진 의자까지의 결과를 우선 모두 저장해놓자.
    for (int i = 3; i <= num; i++)
        seats[i] = seats[i - 1] + seats[i - 2];

    int partial = 0;
    
    for (int i = 1; i <= num + 1; i++) {
    // num + 1번째 좌석은 반드시 VIP이다.
    // 그래야 마지막 구간도 계산이 가능!
        if (vips[i] == 9) {
            answer *= seats[partial];
            partial = 0;
            continue;
        }

        partial++;
    }
    
    cout << answer;
    return 0;
}
