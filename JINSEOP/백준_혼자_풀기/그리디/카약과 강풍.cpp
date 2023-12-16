#include <iostream>
using namespace std;

int num = 0, broken_num = 0, addit_num = 0, broken_team = 0, addit_team = 0;
bool broken[11], addit[11];

int main() {
    cin >> num >> broken_num >> addit_num;
    for (int i = 0; i < broken_num; i++) {
        cin >> broken_team;
        broken[broken_team] = true;
    }
    for (int i = 0; i < addit_num; i++) {
        cin >> addit_team;

        if (broken[addit_team]) {
            broken[addit_team] = false;
            continue;
        }

        addit[addit_team] = true;
    }

    for (int i = 1; i <= 10; i++) {
        if (broken[i]) {
            if (addit[i - 1]) {
                broken[i] = false;
                addit[i - 1] = false;
            }
            else if (addit[i + 1]) {
                broken[i] = false;
                addit[i + 1] = false;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 10; i++) {
        if (broken[i])
            answer++;
    }

    cout << answer;
    return 0;
}
