#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> hamburger;
vector<int> manual = {1, 2, 3, 1};
int solution(vector<int> ingredient) {
    int answer = 0, iter = 0, man_ptr = 0;
    // 기본 순서는 1 2 3 1

    while(true) {
        if (man_ptr == 1 && hamburger.top() == 1)
            man_ptr = 0;

        if (!hamburger.empty() && (hamburger.top() == manual[man_ptr])) {
            man_ptr++;

            if (man_ptr == manual.size()) {
                for (int i = 0; i < 4; i++)
                    hamburger.pop();

                man_ptr = 0;
                answer++;
                continue;
            }
        }
        else
            man_ptr = 0;

        if (iter >= ingredient.size())
            break;

        hamburger.push(ingredient[iter]);
        iter++;
    }

    return answer;
}

int main() {
    vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    cout << solution(ingredient);
    return 0;
}
