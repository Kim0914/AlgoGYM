#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name){
    int answer = 0;
    int endCur;
    int move = name.size()-1;

    for(char c: name){
        answer += min(c-'A', 'Z'-c+1);
    } 

    for(int i=0;i<name.size();i++){
        endCur = i+1;
        while(endCur<name.size() && name[endCur] == 'A'){
            endCur++;
        }
        move = min(move, i + ((int)name.size()-endCur) + min(i,(int)name.size()-endCur));
    }

    answer += move;
    return answer;
}