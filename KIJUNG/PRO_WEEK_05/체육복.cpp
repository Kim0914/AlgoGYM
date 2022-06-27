#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int stud[32];
    fill(stud, stud+32, 1);
    
    for(int e: lost){
        stud[e]--;
    }
    
    for(int e: reserve){
        stud[e]++;
    }
    
    for(int i=1;i<=n;i++){
        if(stud[i] == 2){
            stud[i]--;
            if(stud[i-1] == 0) stud[i-1]++;
            else if(stud[i+1] == 0) stud[i+1]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        if(stud[i]>0) answer++;
    }    
    return answer;
}