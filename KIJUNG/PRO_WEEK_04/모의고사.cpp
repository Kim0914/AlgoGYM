#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int method1[5] = {0,1,2,3,4};
    int method2[10] = {2,1,2,2,2,3,2,4,2,5};
    int method3[10] = {3,3,1,1,2,2,4,4,5,5};
    int correct[3] = {0,};

    for(int i=0;i<answers.size();i++){
        if(answer[i] == method1[i%5]) correct[0]++;
        if(answer[i] == method2[i%10]) correct[1]++;
        if(answer[i] == method3[i%10]) correct[2]++;
    }

    int M = *max_element(correct, correct+3);

    for(int i=0;i<3;i++){
        if(correct[i] == M) answer.push_back(i);
    }
    
    return answer;
}

int main(void){
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(1);
    answers.push_back(1);
    answers.push_back(1);
    answers.push_back(1);
    solution(answers);
    return 0;
}