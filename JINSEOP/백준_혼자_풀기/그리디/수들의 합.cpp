#include <iostream>
using namespace std;

int main() {
    long long num = 0, sum = 0, cnt = 0, iter = 1;

    cin >> num;
    while (true) {
        sum += iter;

        if (sum > num)
            break;

        iter++;
        cnt++;
    }
    
    cout << cnt;
}
