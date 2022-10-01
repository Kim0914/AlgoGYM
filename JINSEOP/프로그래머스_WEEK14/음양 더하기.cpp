#include <string>
#include <vector>
using namespace std;

int calculate(vector<int> absolutes, vector<bool> signs){
    int sum = 0;
    
    for(int i = 0; i < absolutes.size(); i++){
        if(signs[i] == true)
            sum += absolutes[i];
        else
            sum += absolutes[i] * -1;
    }
    
    return sum;
}

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    
    answer = calculate(absolutes, signs);
    return answer;
}
