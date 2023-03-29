#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int> t_A;
    priority_queue<int> t_B;
    int n = A.size();
    for(int i = 0; i < n; i++){
        t_A.push(A.back());
        t_B.push(B.back());
        A.pop_back();
        B.pop_back();
    }
    while(!t_A.empty()){
        int a = t_A.top();
        int b = t_B.top();
        if(a < b){
            answer++;
            t_B.pop();
        }
        t_A.pop();
    }
    return answer;
}
