#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stack;
    for(int i = numbers.size() - 1; i >= 0; i--){
        while(!stack.empty()){
            if(stack.top() > numbers[i]){
                answer.push_back(stack.top());
                stack.push(numbers[i]);
                break;
            }
            else{
                stack.pop();
            }
        }
        if(stack.empty()){
            answer.push_back(-1);
            stack.push(numbers[i]);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
