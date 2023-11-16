#include <iostream>
#include <string>
using namespace std;
#define ll long long

int num = 0;
string ineq = "", part = "", answer = "", min_answer = "9999999999", max_answer = "0";
bool visit[10];
void backtrack(int depth, int curr_digit) {
    if (depth == num) {
        ll partial_answer = stoll(answer);

        if (stoll(min_answer) > partial_answer)
            min_answer = answer;
        if (stoll(max_answer) < partial_answer)
            max_answer = answer;

        return;
    }

    if (ineq[depth] == '<') {
        for (int i = curr_digit + 1; i <= 9; i++) {
            if (!visit[i]) {
                answer += to_string(i);
                visit[curr_digit] = true;
                backtrack(depth + 1, i);
                answer.pop_back();
                visit[curr_digit] = false;
            }
        }       
    }
    else {
        for (int i = curr_digit - 1; i >= 0; i--) {
            if (!visit[i]) {
                answer += to_string(i);
                visit[curr_digit] = true;
                backtrack(depth + 1, i);
                answer.pop_back();
                visit[curr_digit] = false;
            }
        }
    }
}

int main() {
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> part;
        ineq += part;
    }
    
    for (int i = 0; i < 10; i++) {
        answer += to_string(i);
        visit[i] = true;
        backtrack(0, i);
        visit[i] = false;
        answer = "";
    }

    cout << max_answer << '\n' << min_answer;
    return 0;
}
