#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    char prior[3] = {'+','-','*'};
    sort(prior, prior+3);

    do{
        deque<char> ops;
        deque<long long> nums;
        long long opNum = 0;
        int  j=0;
        for(int i=0;i<expression.size();i++){
            if(expression[i] < '0' || expression[i] > '9'){
                ops.push_back(expression[i]);
                nums.push_back(stoi(expression.substr(j,i-j)));
                j = i+1;
            }
        }
        nums.push_back(stoi(expression.substr(j,expression.size()-j)));

        for(int k=0;k<3;k++){

            int opSize = ops.size();
            while(opSize--){
                long long num1 = nums[0];
                long long num2 = nums[1];
                char op = ops[0];
                nums.pop_front();
                ops.pop_front();

                if(op == prior[k]){
                    nums.pop_front();

                    if(op=='+') nums.push_front(num1+num2);
                    else if(op=='*') nums.push_front(num1*num2);
                    else nums.push_front(num1-num2);

                }else{
                    nums.push_back(num1);
                    ops.push_back(op);
                }
            }
            nums.push_back(nums.front());
            nums.pop_front();
            
        }
        answer = max(abs(nums.front()), answer);
        
    }while(next_permutation(prior,prior+3));
    return answer;
}

int main(void){
    cout << solution("100-200*300-500+20");

    return 0;
}