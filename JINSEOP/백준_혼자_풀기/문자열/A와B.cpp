#include <iostream>
#include <algorithm>
using namespace std;

string src = "", dest = "";
int main() {
    cin >> src >> dest;

    while (dest.size() != src.size()) {
        if (dest[dest.size() - 1] == 'A')
            dest.pop_back();
        else {
            dest.pop_back();
            reverse(dest.begin(), dest.end());
        }
    }

    if (src == dest)
        cout << 1;
    else
        cout << 0;

    return 0;
}
