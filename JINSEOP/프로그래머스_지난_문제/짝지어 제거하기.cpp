#include <stack>
#include <string>
using namespace std;

stack<char> stacker;
void stack_and_erase(string s) {
    for (auto c : s) {
        if (stacker.empty())
            stacker.push(c);
        else {
            if (stacker.top() == c)
                stacker.pop();
            else
                stacker.push(c);
        }
    }
}

int solution(string s){
    int answer = -1;

    stack_and_erase(s);
    
    if (stacker.empty()) answer = 1;
    else answer = 0;

    return answer;
}
