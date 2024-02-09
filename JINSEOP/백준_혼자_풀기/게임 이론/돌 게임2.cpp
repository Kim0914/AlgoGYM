#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    if (!(n % 2))
        cout << "SK";
    if (n % 2)
        cout << "CY";

    return 0;
}
