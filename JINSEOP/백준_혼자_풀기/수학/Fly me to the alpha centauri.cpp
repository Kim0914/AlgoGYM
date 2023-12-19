#include <iostream>
#include <cmath>
using namespace std;

int earth = 0, centauri = 0, num = 0, answer = 0;
int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> earth >> centauri;
        
        int distance = centauri - earth;
        if (distance < 1)
        // 거리가 1보다 작으면 시간이 안걸린다.
            cout << 0;
        else {
            int square_root = sqrt(distance);
            // 여기서 가장 가까운 제곱근을 찾는다.

            if (distance == (square_root * square_root))
                answer = (square_root * 2) - 1;
            // N^2 기준, 동일할 시 N*2 - 1
            else if (distance <= (square_root * square_root) + square_root)
                answer = (square_root * 2);
            // N^2 ~ N^2 + N 사이의 수는 N * 2;
            else
                answer = (square_root * 2) + 1;
            // N^2 + N ~ (N+1)^2 까지는 N * 2 + 1;
        }

        cout << answer <<'\n';
    }

    return 0;
}
