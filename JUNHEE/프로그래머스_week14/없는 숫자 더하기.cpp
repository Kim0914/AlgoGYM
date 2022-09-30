#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool num[10] = {false,};
    
    for(int i = 0; i < numbers.size(); i++){
        num[numbers[i]] = true;
    }
    for(int i = 0; i < 10; i++){
        if(!num[i]) answer += i;
    }
    return answer;
}
