#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    
    while(progresses.size()){
        for(int i=0; i<progresses.size(); i++){
            progresses[i] += speeds[i];
            if (progresses[i] > 100) progresses[i] = 100;
        }
        
        
        int cnt = 0;
        while(1){
            int top = progresses.front();
            
            if (top == 100){
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt += 1;
                
                if(progresses.size() == 0) break;
            }
            else break;
            
        }
        
        if(cnt > 0){
            answer.push_back(cnt);
        }
    }
    
    
    return answer;
}