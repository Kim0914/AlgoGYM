#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<string, int> counter;
vector<string> names;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_hear = 0, num_see = 0, answer = 0;
    string name = "";
    
    cin >> num_hear >> num_see;
    
    for (int i = 0; i < (num_hear + num_see); i++) {
        cin >> name;
        counter[name]++;

        if (counter[name] == 2) {
            answer++;
            names.push_back(name);
        }
    }

    sort(names.begin(), names.end());

    cout << answer << "\n";
    for (string s : names)
        cout << s << "\n";
    return 0;
}
