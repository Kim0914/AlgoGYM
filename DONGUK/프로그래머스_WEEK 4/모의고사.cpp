#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int first[5] = {1, 2, 3, 4, 5};
    int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int score[3] = {0, 0, 0};
    for(int i=0; i<answers.size(); i++){
        int ind = i;
        
        if(i > 4) ind = i % 5;
        if(first[ind] == answers[i]){
            score[0] += 1;
        }
        
        ind = i;
        if(i > 7) ind = i % 8;
        if(second[ind] == answers[i]){
            score[1] += 1;
        }
        
        ind = i;
        if(i > 9) ind = i % 10;
        if(third[ind] == answers[i]){
            score[2] += 1;
        }
    }
    
    int max_val = max({score[0],score[1],score[2]});
    
    for(int i=0; i<3; i++){
        if (score[i] == max_val){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}