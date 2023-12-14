#include <iostream>
using namespace std;

string target = "";
int main() {
    cin >> target;
    
    if (target.size() == 1) {
        cout << 1;
        return 0;
    }

    int left = 0, right = target.size() - 1, mid = target.size() / 2;

    for (int i = 0; i < mid; i++) {
        if (target[left] != target[right]) {
            cout << 0;
            return 0;
        }

        left++; right--;
    }

    cout << 1;
    return 0;
}
