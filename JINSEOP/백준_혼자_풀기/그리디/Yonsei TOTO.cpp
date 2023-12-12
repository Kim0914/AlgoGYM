#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, my_milage = 0, stud = 0, limit = 0, milage = 0, answer = 0;
priority_queue<int, vector<int>, greater<>> milage_q;
int main() {
    cin >> num >> my_milage;
    for (int i = 0; i < num; i++) {
        priority_queue<int> temp_q;
        int min_milage = 36;

        cin >> stud >> limit;
        int limit_for_q = limit;
        for (int i = 0; i < stud; i++) {
            cin >> milage;
            temp_q.push(milage);
        }

        while (limit_for_q--) {
            min_milage = min(temp_q.top(), min_milage);
            temp_q.pop();

            if (temp_q.empty())
                break;
        }

        if (stud >= limit)
            milage_q.push(min_milage);
        else
            milage_q.push(1);
    }

    while (!milage_q.empty()) {
        my_milage -= milage_q.top();
        milage_q.pop();

        if (my_milage < 0)
            break;

        answer++;
    }

    cout << answer;
    return 0;
}
