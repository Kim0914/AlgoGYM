#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> name_map;
int main() {
    int tc = 0, prev_size = 0, answer = 0, standard = 0;
    string name;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> name;

        if (name == "ENTER") {
            standard++;
            continue;
        }

        if (name_map[name] != standard) {
            answer++;
            name_map[name] += (standard - name_map[name]);
        }
    }

    cout << answer;
    return 0;
}
