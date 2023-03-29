#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(auto i : works)
        pq.push(i);
    while(!pq.empty() && n > 0){
        if(pq.top() != 0){
            int num = pq.top();
            pq.pop();
            if(num != 1)
                pq.push(num - 1);
        }
        n--;
    }
    while(!pq.empty()){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}
