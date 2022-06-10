#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int answer = 0;
    
    for(int data : scoville){
        pq.push(data);
    }
    
    while(1){
        if(pq.top() >= K) break;
        
        if(pq.size() <= 1){
            return -1;
        }
        
        int top1 = pq.top();
        pq.pop();
        
        int top2 = pq.top();
        pq.pop();
        
        pq.push(top1 + (top2 * 2));
        answer += 1;
    }
    
    
    return answer;
}