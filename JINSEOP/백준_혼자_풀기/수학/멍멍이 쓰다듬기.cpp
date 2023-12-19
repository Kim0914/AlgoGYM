#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll monkey = 0, puppy = 0, answer = 0;
int main() {
    cin >> monkey >> puppy;

    ll diff = puppy - monkey;
    if (diff == 0)
        cout << 0;
    // 나이 차이가 1보다 작으면 시간 안걸림
    else {
        ll square_root = sqrt(diff);

        if (diff == (square_root * square_root))
            answer = (square_root * 2) - 1;
        else if (diff <= (square_root * square_root) + square_root)
            answer = (square_root * 2);
        else
            answer = (square_root * 2) + 1;
    }

    cout << answer;
    return 0;
}
