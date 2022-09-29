#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check_no_exist(vector<int> numbers){
    int key = 0, ptr = 0, sum = 0;
    
    while(key < 10){
        if(numbers[ptr] != key)
            sum += key;
        else
            ptr++;
        
        key++;
    }
    
    return sum;
}

int solution(vector<int> numbers) {
    int answer = -1;
    
    sort(numbers.begin(), numbers.end());
    answer = check_no_exist(numbers);
    
    return answer;
}
