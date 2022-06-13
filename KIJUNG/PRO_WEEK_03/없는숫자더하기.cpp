#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    bool num[10] = {false,};
    int answer = 0;
    
    for(int number: numbers){
        num[number] = true;
    }
    for(int i=0;i<10;i++){
        if(!num[i]) answer+=i;
    }
    
    return answer;
}