#include <iostream>
#include <stack>
using namespace std;

stack<char> par_stack;
int main() {
    int result = 0, part_sum = 1;
    string par_quence;
    cin >> par_quence;

    for (int i = 0; i < par_quence.size(); i++) {
        if (par_quence[i] == '(') {
            part_sum *= 2;
            par_stack.push(par_quence[i]);
        }
        else if (par_quence[i] == '[') {
            part_sum *= 3;
            par_stack.push(par_quence[i]);
        }
        else if (par_quence[i] == ')') {
            if (par_stack.empty() || par_stack.top() != '(') {
                result = 0;
                break;
            }
            if (par_quence[i - 1] == '(') {
                result += part_sum;
                part_sum /= 2;
                par_stack.pop();
            }
            else {
                part_sum /= 2;
                par_stack.pop();
            }
        }
        else if (par_quence[i] == ']') {
            if (par_stack.empty() || par_stack.top() != '[') {
                result = 0;
                break;
            }
            if (par_quence[i - 1] == '[') {
                result += part_sum;
                part_sum /= 3;
                par_stack.pop();
            }
            else {
                part_sum /= 3;
                par_stack.pop();
            }
        }
    }

    if (!par_stack.empty()) 
        result = 0;
    cout << result << '\n';
    return 0;
}
