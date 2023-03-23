#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int> go;
    stack<int> back;
    for(auto i : deliveries){
        go.push(i);
    }
    for(auto i : pickups){
        back.push(i);
    }
    while(!go.empty() || !back.empty()){
        int temp = 0;
        while(!go.empty() && go.top() == 0)
            go.pop();
        while(!back.empty() && back.top() == 0)
            back.pop();
        answer += max(go.size(), back.size()) * 2;
        while(!go.empty() && temp < cap){
            if(temp + go.top() <= cap){
                temp += go.top();
                go.pop();
            }
            else {
                go.top() -= cap - temp;
                temp = cap;
            }
        }
        temp = 0;
        while(!back.empty() && temp < cap){
            if(temp + back.top() <= cap){
                temp += back.top();
                back.pop();
            }
            else {
                back.top() -= cap - temp;
                temp = cap;
            }
        }
    }
    return answer;
}
