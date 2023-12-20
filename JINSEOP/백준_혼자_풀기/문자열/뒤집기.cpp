#include <iostream>
using namespace std;

string target = "";
int main() {
    cin >> target;
    
    int zero_cnt = 0, one_cnt = 0;
    target[0] == '0' ? zero_cnt = 1 : one_cnt = 1;

    for (int i = 1; i < target.size(); i++) {
        if (target[i - 1] != target[i]) {
            if (target[i] == '1')
                one_cnt++;
            else
                zero_cnt++;
        }
    }

    cout << min(one_cnt, zero_cnt);
    return 0;
}
