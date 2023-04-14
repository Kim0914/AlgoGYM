#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> hamburger;
string manual = "1321"; // Stack이니까 반대로 봐야함
void validate(int &answer) {
    string test = "";
    stack<int> temp_stack;

    for (int i = 0; i < 4; i++) {
        test += (hamburger.top() + '0');
        temp_stack.push(hamburger.top());
        hamburger.pop();
    }

    if (test == manual)
        answer++;
    else {
        for (int i = 0; i < 4; i++) {
            hamburger.push(temp_stack.top());
            temp_stack.pop();
        }
    }
}

int solution(vector<int> ingredient) {
    int answer = 0;

    for (int i = 0; i < ingredient.size(); i++) {
        hamburger.push(ingredient[i]);

        if (hamburger.size() >= 4 && hamburger.top() == 1)
            validate(answer);
    }

    return answer;
}

// 4개마다 그냥 다 빼서 확인하고 도로 집어넣기.
