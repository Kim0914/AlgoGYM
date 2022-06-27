#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int list[30] = {};
    for(int i = 0 ; i < 30 ; i++){
        list[i] = -1;
    }
    for(int i = 0; i < n; i++){
        list[i] = 1;
    }
    for(int i = 0; i < lost.size(); i++){
        list[lost[i]-1]--;
    }
    for(int i = 0; i < reserve.size(); i++){
        list[reserve[i]-1]++;
    }
    if(list[0] == 0){
            if(list[1] == 2){
                list[1]--;
                list[0]++;
            }
    }
    for(int i = 1; i < n; i++){
        if(list[i] == 0){
            if(list[i-1] == 2){
                list[i-1]--;
                list[i]++;
            }
            else if(list[i+1] == 2){
                list[i+1]--;
                list[i]++;
            }
        }
        
    }
    
    int answer = n;
    for(int i = 0 ; i < n; i++){
        if(list[i] == 0){
            answer--;
        }
    }
    return answer;
}
