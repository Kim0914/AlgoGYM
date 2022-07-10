#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown+yellow;
    for(int i=1; i<=sqrt(yellow); i++){
        if(yellow%i == 0){
            if((i+2)*(yellow/i+2) == sum){
                answer.push_back(yellow/i+2);
                answer.push_back(i+2);
            }
        }
    }
    return answer;
}