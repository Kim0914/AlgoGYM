#include <iostream>
using namespace std;
#define ll long long

ll num = 0;
bool seq[7] = {true, false, true, true, true, true, false};
int main() {
    cin >> num;

    if (seq[(num - 1) % 7])
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
