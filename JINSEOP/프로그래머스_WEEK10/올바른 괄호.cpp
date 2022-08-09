#include <string>
#include <stack>
using namespace std;

stack<char> validator;
bool check_parenth(string s) {
    if (s[0] == ')') return false;

    for (auto c : s) {
        if (c == '(') validator.push(c);
        else {
            if (validator.size() == 0) return false;
            else if (validator.top() == '(') validator.pop();
        }
    }

    if (!validator.empty()) return false;
    else return true;
}

bool solution(string s){
    bool answer = true;

    answer = check_parenth(s);
    return answer;
}
