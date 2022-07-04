#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<char> stor;
bool no_check = false;
void clear_stack() {
    while (!stor.empty()) stor.pop();
}

void classify(char part_s) {
    if (stor.empty()) {
        if (part_s == ')' || part_s == '}' || part_s == ']') {
            stor.push(part_s); 
            no_check = true; return;
        }
        else {
            stor.push(part_s); return;
        }
    }

    if (!stor.empty()) {
        if (stor.top() == '(') {
            if (part_s == ')') {
                stor.pop(); return;
            }
            else {
                stor.push(part_s); return;
            }
        }
        if (stor.top() == '{') {
            if (part_s == '}') {
                stor.pop(); return;
            }
            else {
                stor.push(part_s); return;
            }
        }
        if (stor.top() == '[') {
            if (part_s == ']') {
                stor.pop(); return;
            }
            else {
                stor.push(part_s); return;
            }
        }
    }
}

int solution(string s) {
    int answer = 0, break_cnt = 0;

    while (true) {
        no_check = false;
        if (break_cnt == s.size()) break;
        for (int i = break_cnt; i < (break_cnt + s.size()); i++) {
            classify(s[i % s.size()]);
            if (no_check) break;
        }

        if (stor.empty()) answer++;
        break_cnt++; clear_stack();
    }

    return answer;
}
