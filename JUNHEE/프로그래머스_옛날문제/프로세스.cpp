#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        pair<int,int> temp;
        int max = pq.top();
        temp = q.front();
        q.pop();
        if(temp.first == max){
            pq.pop();
            if(temp.second == location)
                break;
            answer++;
        }
        else{
            q.push(temp);
        }
    }
    return answer;
}
