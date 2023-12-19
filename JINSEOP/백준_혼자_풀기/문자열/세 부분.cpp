#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string target = "", answer = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
int main() {
    cin >> target;

    string first_s = "", second_s = "", third_s = "", temp_string = "";
    for (int front_ptr = 1; front_ptr < target.size(); front_ptr++) {
        for (int rear_ptr = front_ptr + 1; rear_ptr < target.size(); rear_ptr++) {
            first_s = target.substr(0, front_ptr);
            second_s = target.substr(front_ptr, rear_ptr - front_ptr);
            third_s = target.substr(rear_ptr, target.size() - rear_ptr);

            reverse(first_s.begin(), first_s.end());
            reverse(second_s.begin(), second_s.end());
            reverse(third_s.begin(), third_s.end());
            temp_string = first_s + second_s + third_s;

            answer = min(answer, temp_string);
        }
    }

    cout << answer;
    return 0;
}
