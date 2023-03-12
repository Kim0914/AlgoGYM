#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++){
        bool flag = false;
        
        for(int j = i+1; j < numbers.size(); j++){
            if(numbers[i] < numbers[j]){
                answer.push_back(numbers[j]);
                flag = true;
                break;
            }
        }
        
        if(!flag)
            answer.push_back(-1);
    }
    
    return answer;
}
