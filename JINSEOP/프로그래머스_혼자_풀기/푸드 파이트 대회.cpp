#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

deque<int> contest_dq;
string solution(vector<int> food) {
    string answer = "";
    contest_dq.push_front(0);
    
    for(int i = food.size() - 1; i >= 0; i--){
        for(int k = 0; k < food[i] / 2; k++){
            contest_dq.push_back(i);
            contest_dq.push_front(i);
        }
    }
    
    while(!contest_dq.empty()){
        answer += (contest_dq.front() + '0');
        contest_dq.pop_front();
    }
    
    return answer;
}
