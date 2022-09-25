#include <string>
#include <vector>

using namespace std;

double calculate_average(vector<int> arr){
    double sum = 0;
    
    for(int num : arr)
        sum += num;
    
    return sum / arr.size();
}

double solution(vector<int> arr) {
    double answer = 0;
    
    answer = calculate_average(arr);
    return answer;
}
