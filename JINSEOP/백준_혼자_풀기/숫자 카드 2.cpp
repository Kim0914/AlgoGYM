#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, int> counter;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input = 0, num = 0;
    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        counter[num]++;
    }

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        cout << counter[num] << " ";
    }

    return 0;
}
